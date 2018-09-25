#include "jacobi.h"
#include <armadillo>
#include <cmath>
#include <ctime>
#include <iostream>
using namespace std;
using namespace arma;

// inline double analyical_eig(double j)

void rotation(mat &A, int &k, int &l, int n) {

  double c, s;
  double t, tau;

  if (A(k, l) != 0.0) {
    tau = (A(l, l) - A(k, k)) / (2 * A(k, l));
    double t1, t2;
    // t1 = -tau + sqrt(1 + tau * tau);
    // t2 = -tau - sqrt(1 + tau * tau);
    t1 = 1 / (tau + sqrt(1 + tau * tau));
    t2 = -1 / (-tau + sqrt(1 + tau * tau));

    // Minimizing t
    if (fabs(t1) < fabs(t2)) {
      t = t1;
    } else {
      t = t2;
    }
    c = 1 / sqrt(1 + t * t);
    s = t * c;
  } else {
    c = 1.0;
    s = 0.0;
  }

  double akk = A(k, k);
  double all = A(l, l);
  double aik, ail;
  A(k, k) = akk * c * c - 2 * A(k, l) * c * s + all * s * s;
  A(l, l) = all * c * c + 2 * A(k, l) * c * s + akk * s * s;
  A(k, l) = A(l, k) = 0.0;

  for (int i = 0; i < n; i++) {
    if (i != k && i != l) {
      aik = A(i, k);
      ail = A(i, l);
      A(i, k) = aik * c - ail * s;
      A(k, i) = A(i, k);
      A(i, l) = ail * c + aik * s;
      A(l, i) = A(i, l);
    }
  }
  return;
}
