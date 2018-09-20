#include <armadillo>
#include <cmath>
#include <iostream>
using namespace std;
using namespace arma;

// -DARMA_DONT_USE_WRAPPER -llapack -lblas

double maxoffdiag(mat A, int &k, int &l, double max, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      double a_ij = fabs(A(i, j));
      if (a_ij > max) {
        max = a_ij;
        k = i;
        l = j;
      }
    }
  }
  return max;
}

void jacobi_rotatation(mat &A, int &k, int &l, int n) {

  double c, s;
  double t, tau;
  if (A(k, l != 0.0)) {
    tau = (A(l, l) - A(k, k)) / (2 * A(k, l));

    // Minimizing t
    if (tau >= 0) {
      t = 1 / (tau + sqrt(1 + tau * tau));
    } else {
      t = -1 / (-tau + sqrt(1 + tau * tau));
    }
    c = 1 / sqrt(1 + tau * tau);
    s = t * c;
  } else {
    c = 1.0;
    s = 0.0;
  }

  double akk = A(k, k);
  double all = A(l, l);
  double akl, aik, ail;
  A(k, k) = akk * c * c - 2 * A(k, l) * c * s + all * s * s;
  A(l, l) = all * c * c + 2 * A(k, l) * c * s + akk * s * s;
  A(k, l) = A(l, k) = 0.0;

  for (int i = 0; i < n; i++) {
    if (i != k && i != l) {
      aik = A(i, k);
      ail = A(i, l);
      A(i, i) = A(i, i);
      A(i, k) = aik * c - ail * s;
      A(k, i) = A(i, k);
      A(i, l) = ail * c + aik * s;
      A(l, i) = A(i, l);
    }
  }
  return;
}

int main(int argc, char const *argv[]) {

  int n = atoi(argv[1]);
  double rho_N = 1;
  double rho_0 = 0;
  double h = (rho_N - rho_0) / n;
  double hh = h * h;
  int k, l;

  mat A = zeros(n, n);
  A.diag() += 2 / hh;
  A.diag(1) += -1 / hh;
  A.diag(-1) += -1 / hh;

  cout << A << endl;

  vec eigval;
  mat eigvec;

  eig_sym(eigval, eigvec, A);

  // cout << eigval << eigvec << endl;

  double eps = 10e-10;
  double max = 1.0;
  while (max > eps) {
    jacobi_rotatation(A, k, l, n);
    max = maxoffdiag(A, k, l, max, n);
    cout << max << endl;
  }

  cout << A << endl;
  return 0;
}
