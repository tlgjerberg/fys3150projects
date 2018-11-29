#include "tridiag_solver.hpp"

Tridiag::Tridiag(double diag, double sub, double super) {
  diagonal = diag;
  subdiag = sub;
  superdiag = super;
}

mat Tridiag::initialize(int n, double hh) {
  mat A = zeros(n, n);
  A.diag() += diagonal;
  A.diag(1) += subdiag;
  A.diag(-1) += superdiag;
}

void Tridiag::Gauss_Seidel() { return 0; }
