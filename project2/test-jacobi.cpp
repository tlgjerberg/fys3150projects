#include "jacobi.h"
#include <armadillo>
// #include <catch2/catch.hpp>
#include "catch.hpp"
#include <cmath>
#include <iostream>

using namespace std;
using namespace arma;

TEST_CASE("Testing the maximum off-diagonal element") {
  int k, l;
  int n = 45;
  double h = 1 / n;
  double hh = h * h;
  mat A = rand_toeplitz(n, hh);
  mat B = rand_toeplitz(n, hh);
  B = abs(B);
  B.diag().fill(0);
  double max_B = B.max();
  double max_A = maxoffdiag(A, k, l, n);
  REQUIRE(max_A == Approx(max_B));
}

TEST_CASE("Check if eigenvalues are correct") {
  int k, l;
  int n = 45;
  double h = 1 / n;
  double hh = h * h;
  double eps = 1e-8;
  vec arma_eigval;
  mat arma_eigvec;
  eig_sym(arma_eigval, arma_eigvec, A);
  mat A = rand_toeplitz(n, hh);
  mat R = zeros(n, n);
  R.diag() += 1;
  double max = maxoffdiag(A, k, l, n);
  vec eig_jac = jacobi_method(A, R, eps, max, k, l,
                              n); // Find eigenvalues using Jacobi's method
  vec eig_arma = arma_eigval;     // Generate eigenvalue vector with Armadillo
  for (int i = 0; i < m; i++) {
    REQUIRE(eig_jac(i) == Approx(eig_arma(i)));
  }
}
