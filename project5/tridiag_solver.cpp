#include "tridiag_solver.hpp"

Tridiag::Tridiag(double diagonal, double subdiagonal, double superdiagonal) {
  diag = diagonal;
  sub = subdiagonal;
  super = superdiagonal;
}

void Tridiag::initialize(int n, double hh) {
  d = new double[n];
  lower = new double[n - 1];
  upper = new double[n - 1];
  d[0] = d[n] = diag;
  for (int i = 1; i < n; i++) {
    d[i] = diag;
    lower[i] = sub;
    upper[i] = super;
  }
  return;
}

void Tridiag::Gauss_Seidel(int n) {
  b = new double[n];
  for (int i = 0; i < n; i++) {
    temp = lower[i - 1] / d[i - 1];
    d[i] -= upper[i - 1] * temp;
    b[i] -= b[i - 1] * temp;
  }
  return;
}
