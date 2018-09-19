#include <armadillo>
#include <cmath>
#include <iostream>
using namespace std;
using namespace arma;

// -DARMA_DONT_USE_WRAPPER -llapack -lblas

int main(int argc, char const *argv[]) {

  int n = atoi(argv[1]);
  double rho_N = 1;
  double rho_0 = 0;
  double h = (rho_N - rho_0) / n;
  double hh = h * h;

  // cout << hh << endl;

  mat A = zeros(n, n);
  A.diag() += 2 / hh;
  A.diag(1) += -1 / hh;
  A.diag(-1) += -1 / hh;

  vec eigval;
  mat eigvec;

  eig_sym(eigval, eigvec, A);

  // cout << eigval << eigvec << endl;

  return 0;
}

double maxdiag(mat &A, int k, int l, int n) {
  double max = 0.0;
  for (int i; i < n; i++) {
    for (int j; j < n; j++) {
      double a_ij = fabs(A(i, j));
      if (a_ij > max) {
        max = a_ij;
        k = i;
        l = j;
      }
    }
  }
}

void rotate(mat &A, mat &R, int k, int l, int n) {
  double c, s;
  double t, tau;
  tau = (A(l, l) - A(k, k)) / (2 * A(k, l));
  t = -tau + sqrt(1 + tau * tau);
  c = 1 / sqrt(1 + tau * tau);
  s = t * c;

  double akk = A(k, k);
  double all = A(l, l);
  double akl;
  akk = akk * c * c - 2 * A(k, l) * c * s + all * s * s;
  all = all * c * c + 2 * A(k, l) * c * s + akk * s * s;
  A(k, l) = 0.0;
  A(l, k) = 0.0;

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      aik = A(i, k);
      ail = A(i, l);
      A(i, i) = A(i, i);
      A(i, k) = aik * c - ail * s;
      A(i, l) = ail * c + aik * s;
    }
  }
}
