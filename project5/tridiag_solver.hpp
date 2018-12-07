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
  // double *d, *b, *upper, *lower;
  vec d;
  vec b;
  vec upper;
  vec lower;

  Tridiag(double diagonal, double sub, double super);
  ~Tridiag();
  void initialize(int n, double hh);
  void Gauss_Seidel(int n);
};

#endif /* Tridiag_H */
