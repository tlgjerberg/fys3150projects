#include "PDEsolvers.hpp"

PDEsolvers::PDEsolvers(double bound1, double bound2) {
  double b_0 = bound1;
  double b_L = bound2;
}

void PDEsolvers::init_cond(double init1, int n) {
  u = new double[n];
  double u_0 = init1;
  for (int i = 0; i < n; i++) {
    u[i] = u_0;
  }
}

void PDEsolvers::Explicit_Euler(int n, double *d, double *b, double *upper) {
  u[0] = b_0;
  u[n] = b_L;
  for (int i = n; i > 0; i--) {
    u[i] = (b[i] - upper[i] * u[i + 1]) / d[i];
  }

  return;
}