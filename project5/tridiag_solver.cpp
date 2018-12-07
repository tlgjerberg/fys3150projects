#include "tridiag_solver.hpp"

Tridiag::Tridiag() {
  diag = 2;
  sub = -1;
  super = -1;
}

Tridiag::Tridiag(double diagonal, double subdiagonal, double superdiagonal) {
  diag = diagonal;
  sub = subdiagonal;
  super = superdiagonal;
}

// Tridiag::~Tridiag() {
//   // delete[] d;
// }

// Initializes a tridiagonal matrix with arguements from the constructor
void Tridiag::initialize(int totstep) {
  // d = new double[n];
  // d[0] = d[n] = diag;
  n = totstep;
  d = zeros(n);
  d.fill(diag);

  return;
}

// Gauss-Seidel method for eliminating the lower diagonal with no arguement for
// rhs
void Tridiag::Gauss_Seidel() {
  b = zeros(n);
  u = zeros(n);
  for (int i = 1; i < n; i++) {
    temp = super / d(i - 1);
    d(i) -= super * temp;
    b(i) -= b(i - 1) * temp;
  }
  b(0) = 0;
  b(n - 1) = 1;

  for (int i = n - 2; i > 0; i--) {
    u(i) = (b(i) - super * u(i + 1)) / d(i);
  }

  return;
}

void Tridiag::Gauss_Seidel(vec rhs) {
  b = rhs;
  u = zeros(n);
  for (int i = 1; i < n; i++) {
    temp = super / d(i - 1);
    d(i) -= super * temp;
    b(i) -= b(i - 1) * temp;
  }
  b(0) = 0;
  b(n - 1) = 1;

  for (int i = n - 2; i > 0; i--) {
    u(i) = (b(i) - super * u(i + 1)) / d(i);
  }

  return;
}
