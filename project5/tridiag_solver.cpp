#include "tridiag_solver.hpp"

Tridiag::Tridiag(double diagonal, double subdiagonal, double superdiagonal) {
  diag = diagonal;
  sub = subdiagonal;
  super = superdiagonal;
}

Tridiag::~Tridiag() {
  // delete[] d;
}

// Initializes a tridiagonal matrix with arguements from the constructor
void Tridiag::initialize(int totstep) {
  // d = new double[n];
  // d[0] = d[n] = diag;
  n = totstep;
  d = zeros(n);
  d.fill(diag);

  return;
}

// Gauss-Seidel method for eliminating the lower diagonal
void Tridiag::Gauss_Seidel() {
  // b = new double[n];
  // for (int i = 0; i < n; i++) {
  //   temp = sub / d[i - 1];
  //   d[i] -= upper[i - 1] * temp;
  //   b[i] -= b[i - 1] * temp;
  // }
  b = zeros(n);
  for (int i = 1; i < n; i++) {
    temp = super / d(i - 1);
    d(i) -= super * temp;
    b(i) -= b(i - 1) * temp;
  }
  b(0) = 0;
  b(n - 1) = 1;
  return;
}
