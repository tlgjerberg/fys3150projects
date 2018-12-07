#include "PDEsolvers.hpp"

PDEsolvers::PDEsolvers(double bound1, double bound2) {
  double b_0 = bound1;
  double b_L = bound2;
}

PDEsolvers::~PDEsolvers() {
  // delete[] u;
  // delete[] d;
}

// Defines initial conditions for a PDE with first order time derivative
void PDEsolvers::init_cond(double init1, int n) {
  // u = new double[n];
  u = zeros(n);
  // double u_0 = init1;
  u.fill(init1);
  // for (int i = 0; i < n; i++) {
  //   u[i] = u_0;
  // }
}

// Explicit Euler algorithm
void PDEsolvers::Explicit_Euler(int n, int tsteps, double alpha) {
  for (int l = 1; l < tsteps; l++) {
    for (int i = 1; i < n - 1; i++) {
      u(i) = (1.0 - 2.0 * alpha) * u(i) + alpha * u(i + 1) + alpha * u(i - 1);
    }
    u(0) = b_0;
    u(n - 1) = b_L;
  }

  return;
}

// void PDEsolvers::Implicit_Euler(int n, vec &d, vec &b, vec &upper) {
//   u[0] = b_0;
//   u[n] = b_L;
//   for (int i = n; i > 0; i--) {
//     u[i] = (b[i] - upper[i] * u[i + 1]) / d[i];
//   }
//   return;
// }
//
// void PDEsolvers::Crank_Nicolson() {
//   u[0] = b_0;
//   u[n] = b_L;
//   for (int i =)
// }
