#include "toeplitz.h"
#include <armadillo>
#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;
using namespace arma;

mat toeplitz(int n, double hh) {
  mat A = zeros(n, n);
  A.diag() += 2 / hh;
  A.diag(1) += -1 / hh;
  A.diag(-1) += -1 / hh;

  return A;
}
