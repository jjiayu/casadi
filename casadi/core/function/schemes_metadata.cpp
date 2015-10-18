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

/** All edits to this file will be lost - autogenerated by misc/autogencode.py */
#include "schemes_metadata.hpp"
#include <string>
namespace casadi {
std::string getSchemeName(InputOutputScheme scheme) {
  switch (scheme) {
    case SCHEME_DAEInput: return "DAEInput";
    case SCHEME_DAEOutput: return "DAEOutput";
    case SCHEME_RDAEInput: return "RDAEInput";
    case SCHEME_RDAEOutput: return "RDAEOutput";
    case SCHEME_IntegratorInput: return "IntegratorInput";
    case SCHEME_IntegratorOutput: return "IntegratorOutput";
    case SCHEME_NLPInput: return "NLPInput";
    case SCHEME_NLPOutput: return "NLPOutput";
    case SCHEME_GradFInput: return "GradFInput";
    case SCHEME_GradFOutput: return "GradFOutput";
    case SCHEME_JacGInput: return "JacGInput";
    case SCHEME_JacGOutput: return "JacGOutput";
    case SCHEME_HessLagInput: return "HessLagInput";
    case SCHEME_HessLagOutput: return "HessLagOutput";
    case SCHEME_NlpSolverInput: return "NlpSolverInput";
    case SCHEME_NlpSolverOutput: return "NlpSolverOutput";
    case SCHEME_QpSolverInput: return "QpSolverInput";
    case SCHEME_QpSolverOutput: return "QpSolverOutput";
    case SCHEME_LinsolInput: return "LinsolInput";
    case SCHEME_LinsolOutput: return "LinsolOutput";
  default: casadi_error("getSchemeName: Scheme '" << scheme <<  "' does not exist.");
  }
}
std::string getSchemeEntryNames(InputOutputScheme scheme) {
  switch (scheme) {
    case SCHEME_DAEInput:
      return "x, z, p, t";
    case SCHEME_DAEOutput:
      return "ode, alg, quad";
    case SCHEME_RDAEInput:
      return "rx, rz, rp, x, z, p, t";
    case SCHEME_RDAEOutput:
      return "ode, alg, quad";
    case SCHEME_IntegratorInput:
      return "x0, p, z0, rx0, rp, rz0";
    case SCHEME_IntegratorOutput:
      return "xf, qf, zf, rxf, rqf, rzf";
    case SCHEME_NLPInput:
      return "x, p";
    case SCHEME_NLPOutput:
      return "f, g";
    case SCHEME_GradFInput:
      return "x, p";
    case SCHEME_GradFOutput:
      return "grad, f, g";
    case SCHEME_JacGInput:
      return "x, p";
    case SCHEME_JacGOutput:
      return "jac, f, g";
    case SCHEME_HessLagInput:
      return "x, p, lam_f, lam_g";
    case SCHEME_HessLagOutput:
      return "hess, f, g, grad_x, grad_p";
    case SCHEME_NlpSolverInput:
      return "x0, p, lbx, ubx, lbg, ubg, lam_x0, lam_g0";
    case SCHEME_NlpSolverOutput:
      return "x, f, g, lam_x, lam_g, lam_p";
    case SCHEME_QpSolverInput:
      return "h, g, a, lba, uba, lbx, ubx, x0, lam_x0";
    case SCHEME_QpSolverOutput:
      return "x, cost, lam_a, lam_x";
    case SCHEME_LinsolInput:
      return "A, B";
    case SCHEME_LinsolOutput:
      return "X";
  default: casadi_error("getSchemeName: Scheme '" << scheme <<  "' does not exist.");
  }
}
std::string getSchemeEntryName(InputOutputScheme scheme, int i) {
  switch (scheme) {
    case SCHEME_DAEInput:
      if (i==0) return "x";
      if (i==1) return "z";
      if (i==2) return "p";
      if (i==3) return "t";
      break;
    case SCHEME_DAEOutput:
      if (i==0) return "ode";
      if (i==1) return "alg";
      if (i==2) return "quad";
      break;
    case SCHEME_RDAEInput:
      if (i==0) return "rx";
      if (i==1) return "rz";
      if (i==2) return "rp";
      if (i==3) return "x";
      if (i==4) return "z";
      if (i==5) return "p";
      if (i==6) return "t";
      break;
    case SCHEME_RDAEOutput:
      if (i==0) return "ode";
      if (i==1) return "alg";
      if (i==2) return "quad";
      break;
    case SCHEME_IntegratorInput:
      if (i==0) return "x0";
      if (i==1) return "p";
      if (i==2) return "z0";
      if (i==3) return "rx0";
      if (i==4) return "rp";
      if (i==5) return "rz0";
      break;
    case SCHEME_IntegratorOutput:
      if (i==0) return "xf";
      if (i==1) return "qf";
      if (i==2) return "zf";
      if (i==3) return "rxf";
      if (i==4) return "rqf";
      if (i==5) return "rzf";
      break;
    case SCHEME_NLPInput:
      if (i==0) return "x";
      if (i==1) return "p";
      break;
    case SCHEME_NLPOutput:
      if (i==0) return "f";
      if (i==1) return "g";
      break;
    case SCHEME_GradFInput:
      if (i==0) return "x";
      if (i==1) return "p";
      break;
    case SCHEME_GradFOutput:
      if (i==0) return "grad";
      if (i==1) return "f";
      if (i==2) return "g";
      break;
    case SCHEME_JacGInput:
      if (i==0) return "x";
      if (i==1) return "p";
      break;
    case SCHEME_JacGOutput:
      if (i==0) return "jac";
      if (i==1) return "f";
      if (i==2) return "g";
      break;
    case SCHEME_HessLagInput:
      if (i==0) return "x";
      if (i==1) return "p";
      if (i==2) return "lam_f";
      if (i==3) return "lam_g";
      break;
    case SCHEME_HessLagOutput:
      if (i==0) return "hess";
      if (i==1) return "f";
      if (i==2) return "g";
      if (i==3) return "grad_x";
      if (i==4) return "grad_p";
      break;
    case SCHEME_NlpSolverInput:
      if (i==0) return "x0";
      if (i==1) return "p";
      if (i==2) return "lbx";
      if (i==3) return "ubx";
      if (i==4) return "lbg";
      if (i==5) return "ubg";
      if (i==6) return "lam_x0";
      if (i==7) return "lam_g0";
      break;
    case SCHEME_NlpSolverOutput:
      if (i==0) return "x";
      if (i==1) return "f";
      if (i==2) return "g";
      if (i==3) return "lam_x";
      if (i==4) return "lam_g";
      if (i==5) return "lam_p";
      break;
    case SCHEME_QpSolverInput:
      if (i==0) return "h";
      if (i==1) return "g";
      if (i==2) return "a";
      if (i==3) return "lba";
      if (i==4) return "uba";
      if (i==5) return "lbx";
      if (i==6) return "ubx";
      if (i==7) return "x0";
      if (i==8) return "lam_x0";
      break;
    case SCHEME_QpSolverOutput:
      if (i==0) return "x";
      if (i==1) return "cost";
      if (i==2) return "lam_a";
      if (i==3) return "lam_x";
      break;
    case SCHEME_LinsolInput:
      if (i==0) return "A";
      if (i==1) return "B";
      break;
    case SCHEME_LinsolOutput:
      if (i==0) return "X";
      break;
  }
  casadi_error("getSchemeEntryName: supplied number is out of range. Scheme '"
               << getSchemeName(scheme) << "' has only " << getSchemeSize(scheme)
               << " entries: " << getSchemeEntryNames(scheme) << ".");
}
std::string getSchemeEntryDoc(InputOutputScheme scheme, int i) {
  switch (scheme) {
    case SCHEME_DAEInput:
      if (i==0) return "Differential state";  // NOLINT(whitespace/line_length)
      if (i==1) return "Algebraic state";  // NOLINT(whitespace/line_length)
      if (i==2) return "Parameter";  // NOLINT(whitespace/line_length)
      if (i==3) return "Explicit time dependence";  // NOLINT(whitespace/line_length)
      break;
    case SCHEME_DAEOutput:
      if (i==0) return "Right hand side of the implicit ODE";  // NOLINT(whitespace/line_length)
      if (i==1) return "Right hand side of algebraic equations";  // NOLINT(whitespace/line_length)
      if (i==2) return "Right hand side of quadratures equations";  // NOLINT(whitespace/line_length)
      break;
    case SCHEME_RDAEInput:
      if (i==0) return "Backward differential state";  // NOLINT(whitespace/line_length)
      if (i==1) return "Backward algebraic state";  // NOLINT(whitespace/line_length)
      if (i==2) return "Backward  parameter vector";  // NOLINT(whitespace/line_length)
      if (i==3) return "Forward differential state";  // NOLINT(whitespace/line_length)
      if (i==4) return "Forward algebraic state";  // NOLINT(whitespace/line_length)
      if (i==5) return "Parameter vector";  // NOLINT(whitespace/line_length)
      if (i==6) return "Explicit time dependence";  // NOLINT(whitespace/line_length)
      break;
    case SCHEME_RDAEOutput:
      if (i==0) return "Right hand side of ODE.";  // NOLINT(whitespace/line_length)
      if (i==1) return "Right hand side of algebraic equations.";  // NOLINT(whitespace/line_length)
      if (i==2) return "Right hand side of quadratures.";  // NOLINT(whitespace/line_length)
      break;
    case SCHEME_IntegratorInput:
      if (i==0) return "Differential state at the initial time";  // NOLINT(whitespace/line_length)
      if (i==1) return "Parameters";  // NOLINT(whitespace/line_length)
      if (i==2) return "Initial guess for the algebraic variable";  // NOLINT(whitespace/line_length)
      if (i==3) return "Backward differential state at the final time";  // NOLINT(whitespace/line_length)
      if (i==4) return "Backward parameter vector";  // NOLINT(whitespace/line_length)
      if (i==5) return "Initial guess for the backwards algebraic variable";  // NOLINT(whitespace/line_length)
      break;
    case SCHEME_IntegratorOutput:
      if (i==0) return "Differential state at the final time";  // NOLINT(whitespace/line_length)
      if (i==1) return "Quadrature state at the final time";  // NOLINT(whitespace/line_length)
      if (i==2) return "Algebraic variable at the final time";  // NOLINT(whitespace/line_length)
      if (i==3) return "Backward differential state at the initial time";  // NOLINT(whitespace/line_length)
      if (i==4) return "Backward quadrature state at the initial time";  // NOLINT(whitespace/line_length)
      if (i==5) return "Backward algebraic variable at the initial time";  // NOLINT(whitespace/line_length)
      break;
    case SCHEME_NLPInput:
      if (i==0) return "Decision variable";  // NOLINT(whitespace/line_length)
      if (i==1) return "Fixed parameter";  // NOLINT(whitespace/line_length)
      break;
    case SCHEME_NLPOutput:
      if (i==0) return "Objective function";  // NOLINT(whitespace/line_length)
      if (i==1) return "Constraint function";  // NOLINT(whitespace/line_length)
      break;
    case SCHEME_GradFInput:
      if (i==0) return "Decision variable";  // NOLINT(whitespace/line_length)
      if (i==1) return "Fixed parameter";  // NOLINT(whitespace/line_length)
      break;
    case SCHEME_GradFOutput:
      if (i==0) return "Jacobian of the constraints";  // NOLINT(whitespace/line_length)
      if (i==1) return "Objective function";  // NOLINT(whitespace/line_length)
      if (i==2) return "Constraint function";  // NOLINT(whitespace/line_length)
      break;
    case SCHEME_JacGInput:
      if (i==0) return "Decision variable";  // NOLINT(whitespace/line_length)
      if (i==1) return "Fixed parameter";  // NOLINT(whitespace/line_length)
      break;
    case SCHEME_JacGOutput:
      if (i==0) return "Jacobian of the constraints";  // NOLINT(whitespace/line_length)
      if (i==1) return "Objective function";  // NOLINT(whitespace/line_length)
      if (i==2) return "Constraint function";  // NOLINT(whitespace/line_length)
      break;
    case SCHEME_HessLagInput:
      if (i==0) return "Decision variable";  // NOLINT(whitespace/line_length)
      if (i==1) return "Fixed parameter";  // NOLINT(whitespace/line_length)
      if (i==2) return "NLP solver might use to scale the objective.";  // NOLINT(whitespace/line_length)
      if (i==3) return "Multiplier for g";  // NOLINT(whitespace/line_length)
      break;
    case SCHEME_HessLagOutput:
      if (i==0) return "Hessian of the Lagrangian";  // NOLINT(whitespace/line_length)
      if (i==1) return "Objective function";  // NOLINT(whitespace/line_length)
      if (i==2) return "Constraint function";  // NOLINT(whitespace/line_length)
      if (i==3) return "Gradient of the Lagrangian with respect to x";  // NOLINT(whitespace/line_length)
      if (i==4) return "Gradient of the Lagrangian with respect to p";  // NOLINT(whitespace/line_length)
      break;
    case SCHEME_NlpSolverInput:
      if (i==0) return "Decision variables, initial guess (nx x 1) ";  // NOLINT(whitespace/line_length)
      if (i==1) return "Value of fixed parameters (np x 1)";  // NOLINT(whitespace/line_length)
      if (i==2) return "Decision variables lower bound (nx x 1), default -inf";  // NOLINT(whitespace/line_length)
      if (i==3) return "Decision variables upper bound (nx x 1), default +inf";  // NOLINT(whitespace/line_length)
      if (i==4) return "Constraints lower bound (ng x 1), default -inf";  // NOLINT(whitespace/line_length)
      if (i==5) return "Constraints upper bound (ng x 1), default +inf";  // NOLINT(whitespace/line_length)
      if (i==6) return "Lagrange multipliers for bounds on X, initial guess (nx x 1)";  // NOLINT(whitespace/line_length)
      if (i==7) return "Lagrange multipliers for bounds on G, initial guess (ng x 1)";  // NOLINT(whitespace/line_length)
      break;
    case SCHEME_NlpSolverOutput:
      if (i==0) return "Decision variables at the optimal solution (nx x 1)";  // NOLINT(whitespace/line_length)
      if (i==1) return "Cost function value at the optimal solution (1 x 1)";  // NOLINT(whitespace/line_length)
      if (i==2) return "Constraints function at the optimal solution (ng x 1)";  // NOLINT(whitespace/line_length)
      if (i==3) return "Lagrange multipliers for bounds on X at the solution (nx x 1)";  // NOLINT(whitespace/line_length)
      if (i==4) return "Lagrange multipliers for bounds on G at the solution (ng x 1)";  // NOLINT(whitespace/line_length)
      if (i==5) return "Lagrange multipliers for bounds on P at the solution (np x 1)";  // NOLINT(whitespace/line_length)
      break;
    case SCHEME_QpSolverInput:
      if (i==0) return "The matrix is assumed to be symmetrical.";  // NOLINT(whitespace/line_length)
      if (i==1) return "The vector g: dense,  (n x 1)";  // NOLINT(whitespace/line_length)
      if (i==2) return "The matrix A: sparse, (nc x n) - product with x must be dense.";  // NOLINT(whitespace/line_length)
      if (i==3) return "dense, (nc x 1)";  // NOLINT(whitespace/line_length)
      if (i==4) return "dense, (nc x 1)";  // NOLINT(whitespace/line_length)
      if (i==5) return "dense, (n x 1)";  // NOLINT(whitespace/line_length)
      if (i==6) return "dense, (n x 1)";  // NOLINT(whitespace/line_length)
      if (i==7) return "dense, (n x 1)";  // NOLINT(whitespace/line_length)
      if (i==8) return "dense";  // NOLINT(whitespace/line_length)
      break;
    case SCHEME_QpSolverOutput:
      if (i==0) return "The primal solution";  // NOLINT(whitespace/line_length)
      if (i==1) return "The optimal cost";  // NOLINT(whitespace/line_length)
      if (i==2) return "The dual solution corresponding to linear bounds";  // NOLINT(whitespace/line_length)
      if (i==3) return "The dual solution corresponding to simple bounds";  // NOLINT(whitespace/line_length)
      break;
    case SCHEME_LinsolInput:
      if (i==0) return "The square matrix A: sparse, (n x n).";  // NOLINT(whitespace/line_length)
      if (i==1) return "The right-hand-side matrix b: dense,  (n x m)";  // NOLINT(whitespace/line_length)
      break;
    case SCHEME_LinsolOutput:
      if (i==0) return "Solution to the linear system of equations";  // NOLINT(whitespace/line_length)
      break;
  }
  casadi_error("getSchemeEntryDoc: supplied number is out of range. Scheme '"
               << getSchemeName(scheme) << "' has only " << getSchemeSize(scheme)
               << " entries: " << getSchemeEntryNames(scheme) << ".");
}
std::string getSchemeEntryEnumName(InputOutputScheme scheme, int i) {
  switch (scheme) {
    case SCHEME_DAEInput:
      if (i==0) return "DAE_X";
      if (i==1) return "DAE_Z";
      if (i==2) return "DAE_P";
      if (i==3) return "DAE_T";
      break;
    case SCHEME_DAEOutput:
      if (i==0) return "DAE_ODE";
      if (i==1) return "DAE_ALG";
      if (i==2) return "DAE_QUAD";
      break;
    case SCHEME_RDAEInput:
      if (i==0) return "RDAE_RX";
      if (i==1) return "RDAE_RZ";
      if (i==2) return "RDAE_RP";
      if (i==3) return "RDAE_X";
      if (i==4) return "RDAE_Z";
      if (i==5) return "RDAE_P";
      if (i==6) return "RDAE_T";
      break;
    case SCHEME_RDAEOutput:
      if (i==0) return "RDAE_ODE";
      if (i==1) return "RDAE_ALG";
      if (i==2) return "RDAE_QUAD";
      break;
    case SCHEME_IntegratorInput:
      if (i==0) return "INTEGRATOR_X0";
      if (i==1) return "INTEGRATOR_P";
      if (i==2) return "INTEGRATOR_Z0";
      if (i==3) return "INTEGRATOR_RX0";
      if (i==4) return "INTEGRATOR_RP";
      if (i==5) return "INTEGRATOR_RZ0";
      break;
    case SCHEME_IntegratorOutput:
      if (i==0) return "INTEGRATOR_XF";
      if (i==1) return "INTEGRATOR_QF";
      if (i==2) return "INTEGRATOR_ZF";
      if (i==3) return "INTEGRATOR_RXF";
      if (i==4) return "INTEGRATOR_RQF";
      if (i==5) return "INTEGRATOR_RZF";
      break;
    case SCHEME_NLPInput:
      if (i==0) return "NL_X";
      if (i==1) return "NL_P";
      break;
    case SCHEME_NLPOutput:
      if (i==0) return "NL_F";
      if (i==1) return "NL_G";
      break;
    case SCHEME_GradFInput:
      if (i==0) return "GRADF_X";
      if (i==1) return "GRADF_P";
      break;
    case SCHEME_GradFOutput:
      if (i==0) return "GRADF_GRAD";
      if (i==1) return "GRADF_F";
      if (i==2) return "GRADF_G";
      break;
    case SCHEME_JacGInput:
      if (i==0) return "JACG_X";
      if (i==1) return "JACG_P";
      break;
    case SCHEME_JacGOutput:
      if (i==0) return "JACG_JAC";
      if (i==1) return "JACG_F";
      if (i==2) return "JACG_G";
      break;
    case SCHEME_HessLagInput:
      if (i==0) return "HESSLAG_X";
      if (i==1) return "HESSLAG_P";
      if (i==2) return "HESSLAG_LAM_F";
      if (i==3) return "HESSLAG_LAM_G";
      break;
    case SCHEME_HessLagOutput:
      if (i==0) return "HESSLAG_HESS";
      if (i==1) return "HESSLAG_F";
      if (i==2) return "HESSLAG_G";
      if (i==3) return "HESSLAG_GRAD_X";
      if (i==4) return "HESSLAG_GRAD_P";
      break;
    case SCHEME_NlpSolverInput:
      if (i==0) return "NLP_SOLVER_X0";
      if (i==1) return "NLP_SOLVER_P";
      if (i==2) return "NLP_SOLVER_LBX";
      if (i==3) return "NLP_SOLVER_UBX";
      if (i==4) return "NLP_SOLVER_LBG";
      if (i==5) return "NLP_SOLVER_UBG";
      if (i==6) return "NLP_SOLVER_LAM_X0";
      if (i==7) return "NLP_SOLVER_LAM_G0";
      break;
    case SCHEME_NlpSolverOutput:
      if (i==0) return "NLP_SOLVER_X";
      if (i==1) return "NLP_SOLVER_F";
      if (i==2) return "NLP_SOLVER_G";
      if (i==3) return "NLP_SOLVER_LAM_X";
      if (i==4) return "NLP_SOLVER_LAM_G";
      if (i==5) return "NLP_SOLVER_LAM_P";
      break;
    case SCHEME_QpSolverInput:
      if (i==0) return "QP_SOLVER_H";
      if (i==1) return "QP_SOLVER_G";
      if (i==2) return "QP_SOLVER_A";
      if (i==3) return "QP_SOLVER_LBA";
      if (i==4) return "QP_SOLVER_UBA";
      if (i==5) return "QP_SOLVER_LBX";
      if (i==6) return "QP_SOLVER_UBX";
      if (i==7) return "QP_SOLVER_X0";
      if (i==8) return "QP_SOLVER_LAM_X0";
      break;
    case SCHEME_QpSolverOutput:
      if (i==0) return "QP_SOLVER_X";
      if (i==1) return "QP_SOLVER_COST";
      if (i==2) return "QP_SOLVER_LAM_A";
      if (i==3) return "QP_SOLVER_LAM_X";
      break;
    case SCHEME_LinsolInput:
      if (i==0) return "LINSOL_A";
      if (i==1) return "LINSOL_B";
      break;
    case SCHEME_LinsolOutput:
      if (i==0) return "LINSOL_X";
      break;
  }
  casadi_error("getSchemeEntryEnumName: supplied number is out of range. Scheme '"
               << getSchemeName(scheme) << "' has only "
               << getSchemeSize(scheme) << " entries: "
                << getSchemeEntryNames(scheme) << ".");
}
int getSchemeSize(InputOutputScheme scheme) {
  switch (scheme) {
    case SCHEME_DAEInput:
      return 4;
      break;
    case SCHEME_DAEOutput:
      return 3;
      break;
    case SCHEME_RDAEInput:
      return 7;
      break;
    case SCHEME_RDAEOutput:
      return 3;
      break;
    case SCHEME_IntegratorInput:
      return 6;
      break;
    case SCHEME_IntegratorOutput:
      return 6;
      break;
    case SCHEME_NLPInput:
      return 2;
      break;
    case SCHEME_NLPOutput:
      return 2;
      break;
    case SCHEME_GradFInput:
      return 2;
      break;
    case SCHEME_GradFOutput:
      return 3;
      break;
    case SCHEME_JacGInput:
      return 2;
      break;
    case SCHEME_JacGOutput:
      return 3;
      break;
    case SCHEME_HessLagInput:
      return 4;
      break;
    case SCHEME_HessLagOutput:
      return 5;
      break;
    case SCHEME_NlpSolverInput:
      return 8;
      break;
    case SCHEME_NlpSolverOutput:
      return 6;
      break;
    case SCHEME_QpSolverInput:
      return 9;
      break;
    case SCHEME_QpSolverOutput:
      return 4;
      break;
    case SCHEME_LinsolInput:
      return 2;
      break;
    case SCHEME_LinsolOutput:
      return 1;
      break;
  default: casadi_error("getSchemeSize: Scheme '" << scheme <<  "' does not exist.");
  }
}
int getSchemeEntryEnum(InputOutputScheme scheme, const std::string &name) {
  switch (scheme) {
    case SCHEME_DAEInput:
      if (name=="x") return 0;
      if (name=="z") return 1;
      if (name=="p") return 2;
      if (name=="t") return 3;
      break;
    case SCHEME_DAEOutput:
      if (name=="ode") return 0;
      if (name=="alg") return 1;
      if (name=="quad") return 2;
      break;
    case SCHEME_RDAEInput:
      if (name=="rx") return 0;
      if (name=="rz") return 1;
      if (name=="rp") return 2;
      if (name=="x") return 3;
      if (name=="z") return 4;
      if (name=="p") return 5;
      if (name=="t") return 6;
      break;
    case SCHEME_RDAEOutput:
      if (name=="ode") return 0;
      if (name=="alg") return 1;
      if (name=="quad") return 2;
      break;
    case SCHEME_IntegratorInput:
      if (name=="x0") return 0;
      if (name=="p") return 1;
      if (name=="z0") return 2;
      if (name=="rx0") return 3;
      if (name=="rp") return 4;
      if (name=="rz0") return 5;
      break;
    case SCHEME_IntegratorOutput:
      if (name=="xf") return 0;
      if (name=="qf") return 1;
      if (name=="zf") return 2;
      if (name=="rxf") return 3;
      if (name=="rqf") return 4;
      if (name=="rzf") return 5;
      break;
    case SCHEME_NLPInput:
      if (name=="x") return 0;
      if (name=="p") return 1;
      break;
    case SCHEME_NLPOutput:
      if (name=="f") return 0;
      if (name=="g") return 1;
      break;
    case SCHEME_GradFInput:
      if (name=="x") return 0;
      if (name=="p") return 1;
      break;
    case SCHEME_GradFOutput:
      if (name=="grad") return 0;
      if (name=="f") return 1;
      if (name=="g") return 2;
      break;
    case SCHEME_JacGInput:
      if (name=="x") return 0;
      if (name=="p") return 1;
      break;
    case SCHEME_JacGOutput:
      if (name=="jac") return 0;
      if (name=="f") return 1;
      if (name=="g") return 2;
      break;
    case SCHEME_HessLagInput:
      if (name=="x") return 0;
      if (name=="p") return 1;
      if (name=="lam_f") return 2;
      if (name=="lam_g") return 3;
      break;
    case SCHEME_HessLagOutput:
      if (name=="hess") return 0;
      if (name=="f") return 1;
      if (name=="g") return 2;
      if (name=="grad_x") return 3;
      if (name=="grad_p") return 4;
      break;
    case SCHEME_NlpSolverInput:
      if (name=="x0") return 0;
      if (name=="p") return 1;
      if (name=="lbx") return 2;
      if (name=="ubx") return 3;
      if (name=="lbg") return 4;
      if (name=="ubg") return 5;
      if (name=="lam_x0") return 6;
      if (name=="lam_g0") return 7;
      break;
    case SCHEME_NlpSolverOutput:
      if (name=="x") return 0;
      if (name=="f") return 1;
      if (name=="g") return 2;
      if (name=="lam_x") return 3;
      if (name=="lam_g") return 4;
      if (name=="lam_p") return 5;
      break;
    case SCHEME_QpSolverInput:
      if (name=="h") return 0;
      if (name=="g") return 1;
      if (name=="a") return 2;
      if (name=="lba") return 3;
      if (name=="uba") return 4;
      if (name=="lbx") return 5;
      if (name=="ubx") return 6;
      if (name=="x0") return 7;
      if (name=="lam_x0") return 8;
      break;
    case SCHEME_QpSolverOutput:
      if (name=="x") return 0;
      if (name=="cost") return 1;
      if (name=="lam_a") return 2;
      if (name=="lam_x") return 3;
      break;
    case SCHEME_LinsolInput:
      if (name=="A") return 0;
      if (name=="B") return 1;
      break;
    case SCHEME_LinsolOutput:
      if (name=="X") return 0;
      break;
  }
  casadi_error("getSchemeEntryEnum: Scheme '" << getSchemeName(scheme)
               <<  "' has no entry named '" << name
               <<  "'. Available entries are: "
                << getSchemeEntryNames(scheme) << ".");
}
} // namespace casadi

