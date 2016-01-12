/*
 *    This file is part of CasADi.
 *
 *    CasADi -- A symbolic framework for dynamic optimization.
 *    Copyright (C) 2010-2014 Joel Andersson, Joris Gillis, Moritz Diehl,
 *                            K.U. Leuven. All rights reserved.
 *    Copyright (C) 2011-2014 Greg Horn
 *
 *    CasADi is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    CasADi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with CasADi; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


#include "rootfinder.hpp"
#include "../mx/mx_node.hpp"
#include <iterator>

#include "../casadi_options.hpp"

using namespace std;
namespace casadi {

  Rootfinder::Rootfinder(const std::string& name, const Function& f)
    : FunctionInternal(name), f_(f) {

    addOption("linear_solver",            OT_STRING, "csparse",
              "User-defined linear solver class. Needed for sensitivities.");
    addOption("linear_solver_options",    OT_DICT,   GenericType(),
              "Options to be passed to the linear solver.");
    addOption("constraints",              OT_INTVECTOR, GenericType(),
              "Constrain the unknowns. 0 (default): no constraint on ui, "
              "1: ui >= 0.0, -1: ui <= 0.0, 2: ui > 0.0, -2: ui < 0.0.");
    addOption("implicit_input",           OT_INT,      0,
              "Index of the input that corresponds to the actual root-finding");
    addOption("implicit_output",          OT_INT,      0,
              "Index of the output that corresponds to the actual root-finding");
    addOption("jacobian_function",        OT_FUNCTION,  GenericType(),
              "Function object for calculating the Jacobian (autogenerated by default)");
  }

  Rootfinder::~Rootfinder() {
  }

  void Rootfinder::init(const Dict& opts) {
    // Which input/output correspond to the root-finding problem?
    iin_ = option("implicit_input");
    iout_ = option("implicit_output");

    // Get the number of equations and check consistency
    casadi_assert_message(iin_>=0 && iin_<f_.n_in() && f_.n_in()>0,
                          "Implicit input not in range");
    casadi_assert_message(iout_>=0 && iout_<f_.n_out() && f_.n_out()>0,
                          "Implicit output not in range");
    casadi_assert_message(f_.sparsity_out(iout_).is_dense()
                          && f_.sparsity_out(iout_).is_column(),
                          "Residual must be a dense vector");
    casadi_assert_message(f_.sparsity_in(iin_).is_dense()
                          && f_.sparsity_in(iin_).is_column(),
                          "Unknown must be a dense vector");
    n_ = f_.nnz_out(iout_);
    casadi_assert_message(n_ == f_.nnz_in(iin_),
                          "Dimension mismatch. Input size is "
                          << f_.nnz_in(iin_)
                          << ", while output size is "
                          << f_.nnz_out(iout_));

    // Call the base class initializer
    FunctionInternal::init(opts);

    // Get the Jacobian function object, if any
    if (hasSetOption("jacobian_function")) {
      jac_ = option("jacobian_function");
    }

    // Generate Jacobian if not provided
    if (jac_.isNull()) jac_ = f_.jacobian(iin_, iout_);

    // Check for structural singularity in the Jacobian
    casadi_assert_message(
      !jac_.sparsity_out(0).is_singular(),
      "Rootfinder::init: singularity - the jacobian is structurally rank-deficient. "
      "sprank(J)=" << sprank(jac_.sparsity_out(0)) << " (instead of "<< jac_.size1_out(0) << ")");

    // Get the linear solver creator function
    if (linsol_.isNull()) {
      if (hasSetOption("linear_solver")) {
        // Pass options
        Dict linear_solver_options;
        if (hasSetOption("linear_solver_options")) {
          linear_solver_options = option("linear_solver_options");
        }

        // Allocate a linear solver
        linsol_ = linsol("linsol", option("linear_solver"),
                         jac_.sparsity_out(0), 1, linear_solver_options);
      }
    } else {
      casadi_assert(linsol_.sparsity_in(0)==jac_.sparsity_out(0));
    }
    alloc(linsol_);

    // Constraints
    if (hasSetOption("constraints")) u_c_ = option("constraints");

    casadi_assert_message(u_c_.size()==n_ || u_c_.empty(),
                          "Constraint vector if supplied, must be of length n, but got "
                          << u_c_.size() << " and n = " << n_);

    // Allocate sufficiently large work vectors
    alloc(f_);
    size_t sz_w = f_.sz_w();
    if (!jac_.isNull()) {
      alloc(jac_);
      sz_w = max(sz_w, jac_.sz_w());
    }
    alloc_w(sz_w + 2*static_cast<size_t>(n_));
  }

  Function Rootfinder
  ::get_forward(const std::string& name, int nfwd, Dict& opts) {
    // Symbolic expression for the input
    vector<MX> arg = mx_in();
    arg[iin_] = MX::sym(arg[iin_].name() + "_guess",
                        Sparsity(arg[iin_].size()));
    vector<MX> res = mx_out();
    vector<vector<MX> > fseed = symbolicFwdSeed(nfwd, arg), fsens;
    forward(arg, res, fseed, fsens, false, false);

    // Construct return function
    arg.insert(arg.end(), res.begin(), res.end());
    for (int d=0; d<nfwd; ++d) arg.insert(arg.end(), fseed[d].begin(), fseed[d].end());
    res.clear();
    for (int d=0; d<nfwd; ++d) res.insert(res.end(), fsens[d].begin(), fsens[d].end());
    return Function(name, arg, res, opts);
  }

  Function Rootfinder
  ::get_reverse(const std::string& name, int nadj, Dict& opts) {
    // Symbolic expression for the input
    vector<MX> arg = mx_in();
    arg[iin_] = MX::sym(arg[iin_].name() + "_guess",
                        Sparsity(arg[iin_].size()));
    vector<MX> res = mx_out();
    vector<vector<MX> > aseed = symbolicAdjSeed(nadj, res), asens;
    reverse(arg, res, aseed, asens, false, false);

    // Construct return function
    arg.insert(arg.end(), res.begin(), res.end());
    for (int d=0; d<nadj; ++d) arg.insert(arg.end(), aseed[d].begin(), aseed[d].end());
    res.clear();
    for (int d=0; d<nadj; ++d) res.insert(res.end(), asens[d].begin(), asens[d].end());
    return Function(name, arg, res, opts);
  }

  void Rootfinder::spFwd(const bvec_t** arg, bvec_t** res, int* iw, bvec_t* w, int mem) {
    int num_out = n_out();
    int num_in = n_in();
    bvec_t* tmp1 = w; w += n_;
    bvec_t* tmp2 = w; w += n_;

    // Propagate dependencies through the function
    const bvec_t** arg1 = arg+n_in();
    copy(arg, arg+num_in, arg1);
    arg1[iin_] = 0;
    bvec_t** res1 = res+n_out();
    fill_n(res1, num_out, static_cast<bvec_t*>(0));
    res1[iout_] = tmp1;
    f_(arg1, res1, iw, w, 0);

    // "Solve" in order to propagate to z
    fill_n(tmp2, n_, 0);
    linsol_.linsol_spsolve(tmp2, tmp1, false);
    if (res[iout_]) copy(tmp2, tmp2+n_, res[iout_]);

    // Propagate to auxiliary outputs
    if (num_out>1) {
      arg1[iin_] = tmp2;
      copy(res, res+num_out, res1);
      res1[iout_] = 0;
      f_(arg1, res1, iw, w, 0);
    }
  }

  void Rootfinder::spAdj(bvec_t** arg, bvec_t** res, int* iw, bvec_t* w, int mem) {
    int num_out = n_out();
    int num_in = n_in();
    bvec_t* tmp1 = w; w += n_;
    bvec_t* tmp2 = w; w += n_;

    // Get & clear seed corresponding to implicitly defined variable
    if (res[iout_]) {
      copy(res[iout_], res[iout_]+n_, tmp1);
      fill_n(res[iout_], n_, 0);
    } else {
      fill_n(tmp1, n_, 0);
    }

    // Propagate dependencies from auxiliary outputs to z
    bvec_t** res1 = res+num_out;
    copy(res, res+num_out, res1);
    res1[iout_] = 0;
    bvec_t** arg1 = arg+num_in;
    copy(arg, arg+num_in, arg1);
    arg1[iin_] = tmp1;
    if (num_out>1) {
      f_.rev(arg1, res1, iw, w, 0);
    }

    // "Solve" in order to get seed
    fill_n(tmp2, n_, 0);
    linsol_.linsol_spsolve(tmp2, tmp1, true);

    // Propagate dependencies through the function
    for (int i=0; i<num_out; ++i) res1[i] = 0;
    res1[iout_] = tmp2;
    arg1[iin_] = 0; // just a guess
    f_.rev(arg1, res1, iw, w, 0);
  }

  std::map<std::string, Rootfinder::Plugin> Rootfinder::solvers_;

  const std::string Rootfinder::infix_ = "rootfinder";

  void Rootfinder::
  forward(const std::vector<MX>& arg, const std::vector<MX>& res,
          const std::vector<std::vector<MX> >& fseed,
          std::vector<std::vector<MX> >& fsens,
          bool always_inline, bool never_inline) {
    // Number of directional derivatives
    int nfwd = fseed.size();
    fsens.resize(nfwd);

    // Quick return if no seeds
    if (nfwd==0) return;

    // Propagate through f_
    vector<MX> f_arg(arg);
    f_arg.at(iin_) = res.at(iout_);
    vector<MX> f_res(res);
    f_res.at(iout_) = MX(size_in(iin_)); // zero residual
    std::vector<std::vector<MX> > f_fseed(fseed);
    for (int d=0; d<nfwd; ++d) {
      f_fseed[d].at(iin_) = MX(size_in(iin_)); // ignore seeds for guess
    }
    f_.forward(f_arg, f_res, f_fseed, fsens, always_inline, never_inline);

    // Get expression of Jacobian
    MX J = jac_(f_arg).front();

    // Solve for all the forward derivatives at once
    vector<MX> rhs(nfwd);
    for (int d=0; d<nfwd; ++d) rhs[d] = vec(fsens[d][iout_]);
    rhs = horzsplit(J->getSolve(-horzcat(rhs), false, linsol_));
    for (int d=0; d<nfwd; ++d) fsens[d][iout_] = reshape(rhs[d], size_in(iin_));

    // Propagate to auxiliary outputs
    int num_out = n_out();
    if (num_out>1) {
      for (int d=0; d<nfwd; ++d) f_fseed[d][iin_] = fsens[d][iout_];
      f_.forward(f_arg, f_res, f_fseed, fsens, always_inline, never_inline);
      for (int d=0; d<nfwd; ++d) fsens[d][iout_] = f_fseed[d][iin_]; // Otherwise overwritten
    }
  }

  void Rootfinder::
  reverse(const std::vector<MX>& arg, const std::vector<MX>& res,
          const std::vector<std::vector<MX> >& aseed,
          std::vector<std::vector<MX> >& asens,
          bool always_inline, bool never_inline) {

    // Number of directional derivatives
    int nadj = aseed.size();
    asens.resize(nadj);

    // Quick return if no seeds
    if (nadj==0) return;

    // Get expression of Jacobian
    vector<MX> f_arg(arg);
    f_arg[iin_] = res.at(iout_);
    MX J = jac_(f_arg).front();

    // Get adjoint seeds for calling f
    int num_out = n_out();
    int num_in = n_in();
    vector<MX> f_res(res);
    f_res[iout_] = MX(size_in(iin_)); // zero residual
    vector<vector<MX> > f_aseed(nadj);
    for (int d=0; d<nadj; ++d) {
      f_aseed[d].resize(num_out);
      for (int i=0; i<num_out; ++i) f_aseed[d][i] = i==iout_ ? f_res[iout_] : aseed[d][i];
    }

    // Propagate dependencies from auxiliary outputs
    vector<MX> rhs(nadj);
    vector<vector<MX> > asens_aux;
    if (num_out>1) {
      f_.reverse(f_arg, f_res, f_aseed, asens_aux, always_inline, never_inline);
      for (int d=0; d<nadj; ++d) rhs[d] = vec(asens_aux[d][iin_] + aseed[d][iout_]);
    } else {
      for (int d=0; d<nadj; ++d) rhs[d] = vec(aseed[d][iout_]);
    }

    // Solve for all the adjoint seeds at once
    rhs = horzsplit(J->getSolve(-horzcat(rhs), true, linsol_));
    for (int d=0; d<nadj; ++d) {
      for (int i=0; i<num_out; ++i) {
        if (i==iout_) {
          f_aseed[d][i] = reshape(rhs[d], size_out(i));
        } else {
          // Avoid counting the auxiliary seeds twice
          f_aseed[d][i] = MX(size_out(i));
        }
      }
    }

    // No dependency on guess (1)
    vector<MX> tmp(nadj);
    for (int d=0; d<nadj; ++d) {
      asens[d].resize(num_in);
      tmp[d] = asens[d][iin_].is_empty(true) ? MX(size_in(iin_)) : asens[d][iin_];
    }

    // Propagate through f_
    f_.reverse(f_arg, f_res, f_aseed, asens, always_inline, never_inline);

    // No dependency on guess (2)
    for (int d=0; d<nadj; ++d) {
      asens[d][iin_] = tmp[d];
    }

    // Add contribution from auxiliary outputs
    if (num_out>1) {
      for (int d=0; d<nadj; ++d) {
        for (int i=0; i<num_in; ++i) if (i!=iin_) asens[d][i] += asens_aux[d][i];
      }
    }
  }

} // namespace casadi
