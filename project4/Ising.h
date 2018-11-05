#ifndef ISING_H
#define ISING_H

#include <armadillo>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
using namespace arma;

class Ising {
private:
  void tryflip(mat &spin, int n, int Delta_E, map<double, double> W, int rx,
               int ry);

public:
  // Variables
  mat spin;
  double T;
  map<double, double> W;

  // Methods

  void initialize();
  map<double, double> W transitions();
  int PBC();
};

#endif // ISING_H
