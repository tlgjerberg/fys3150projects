#include "jacobi.h"
#include <armadillo>
#include <cmath>

using namespace std;
using namespace arma;

double maxoffdiag(mat A, int &k, int &l, int n) {
  double max = 0.0;
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
