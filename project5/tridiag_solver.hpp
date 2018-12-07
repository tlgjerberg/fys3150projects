#ifndef Tridiag_H
#define Tridiag_H

#include <armadillo>
#include <iostream>

using namespace std;
using namespace arma;

class Tridiag {
private:
  double diag, sub, super, temp;

public:
  // double *d, *b;
  vec d;
  vec b;
  int n;

  Tridiag(double diagonal, double sub, double super);
  ~Tridiag();
  void initialize(int totstep);
  void Gauss_Seidel();
};

#endif /* Tridiag_H */
