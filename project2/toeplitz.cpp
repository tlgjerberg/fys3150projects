#include "jacobi.h"

mat toeplitz(int n, double hh) {
  mat A = zeros(n, n);
  double d = 2 / hh;
  A.diag() += d;
  A.diag(1) += -1 / hh;
  A.diag(-1) += -1 / hh;

  return A;
}

mat rand_toeplitz(int n, double hh) {
  mat A = zeros(n, n);
  A.diag() += randu() / hh;
  A.diag(1) += -randu() / hh;
  A.diag(-1) += randu() / hh;

  return A;
}

// Toeplitz matrix for a harmonic oscillator potential
mat HO_toeplitz(int n, double hh, vec rho) {
  mat A = zeros(n, n);
  double d = 2 / hh;
  A.diag() += (d + (rho % rho));
  A.diag(1) += -1 / hh;
  A.diag(-1) += -1 / hh;
  // A(0, 0) = 0;
  // A(n - 1, n - 1) = 0;
  return A;
}
