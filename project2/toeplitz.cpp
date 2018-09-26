#include "jacobi.h"

mat toeplitz(int n, double hh) {
  mat A = zeros(n, n);
  A.diag() += 2 / hh;
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
  // A.diag() += 2 / hh;
  for (int i = 1; i < n; i++) {
    A.diag()[i] += 2 / hh + rho[i];
  }
  A.diag(1) += -1 / hh;
  A.diag(-1) += -1 / hh;
  return A;
}
