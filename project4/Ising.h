#include <armadillo>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
using namespace arma;

class Ising {

public:
  mat spin;
  double T;
  vec w;

  vec transitions();
};
