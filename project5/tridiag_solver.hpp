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
  vec d, b, u;
  int n;
  Tridiag();
  Tridiag(double diagonal, double subdiagonal, double superdiagonal);
  ~Tridiag();
  void initialize(int totstep);
  void Gauss_Seidel();
};

#endif /* Tridiag_H */
