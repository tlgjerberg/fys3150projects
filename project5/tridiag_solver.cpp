#include "tridiag_solver.hpp"

Tridiag::Tridiag(double diagonal, double subdiagonal, double superdiagonal) {
  diag = diagonal;
  sub = subdiagonal;
  super = superdiagonal;
}

void Tridiag::initialize(int n, double hh) {
  // u[0] = u[1] = 0.0;
  for (int i = 1; i < n; i++) {
    d[i] = diag;
    lower[i] = sub;
    upper[i] = super;
  }
}

void Tridiag::Gauss_Seidel(int n) {

  for (int i = 1; i < n; i++) {
    temp = lower[i - 1] / d[i - 1];
    d[i] -= upper[i - 1] * temp;
    b[i] -= b[i - 1] * temp;
  }

  return;
}
