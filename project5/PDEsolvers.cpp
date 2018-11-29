#include "PDEsolvers.hpp"

PDEsolvers::PDEsolvers(double init1, double init2, double bound1,
                       double bound2);
{
  double u_0 = init1;
  double u_n = init2;
  double b_0 = bound1;
  double b_L = bound2;
}

void PDEsolvers::Explicit_Euler() {

  for (int i = 1; i < n; i++) {
  }

  return 0;
}
