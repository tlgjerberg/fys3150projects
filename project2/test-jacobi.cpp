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

TEST_CASE("Testing orthogonality of the eigenvectors") {
  int k, l;
  int n = 10;
  double h = 1 / n;
  double hh = h * h
}
