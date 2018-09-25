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
