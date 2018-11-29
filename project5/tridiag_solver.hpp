#ifndef Tridiag_H
#define Tridiag_H

#include <armadillo>
#include <iostream>

using namespace std;
using namespace arma;

class Tridiag {
private:
  double diag, sub, super, temp;
  double *d, *u, *upper, *lower;

public:
  Tridiag Tridiag(double diagonal, double sub, double super);
  void Gauss_Seidel();
};

#endif /* Tridiag_H */
