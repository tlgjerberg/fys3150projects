#include "catch.hpp"
#include "jacobi.h"

/* Create program with: make test-jacobi */
/* Run ./test-jacobi */

TEST_CASE("Testing the maximum off-diagonal element") {
  int k, l;
  int n = 10;
  double rho_N = 1;
  double rho_0 = 0;
  double h = (rho_N - rho_0) / n;
  double hh = h * h;
  mat A = toeplitz(n, hh);
  mat B = abs(A);
  B.diag().fill(0);
  double max_B = B.max();
  double max_A = maxoffdiag(A, k, l, n);
  cout << max_A << max_B << endl;
  REQUIRE(max_A == Approx(max_B));
}

TEST_CASE("Check if eigenvalues are correct") {
  int k, l;
  int n = 4;
  double rho_N = 1;
  double rho_0 = 0;
  double h = (rho_N - rho_0) / n;
  double hh = h * h;
  double eps = 1e-8;
  mat A = toeplitz(n, hh);
  mat R = zeros(n, n);
  vec arma_eigval;
  mat arma_eigvec;
  eig_sym(arma_eigval, arma_eigvec, A);
  double max = maxoffdiag(A, k, l, n);
  vec eig_jac = jacobi_method(A, R, eps, max, k, l, n);
  vec eig_arma = arma_eigval;
  for (int i = 0; i < n; i++) {
    REQUIRE(eig_jac(i) == Approx(eig_arma(i)));
  }
}
