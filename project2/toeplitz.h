#ifndef TOEPLITZ_H
#define TOEPLITZ_H

#include <armadillo>
#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;
using namespace arma;

mat toeplitz(int n, double hh);
mat rand_toeplitz(int n, double hh);

#endif /* TOEPLITZ_H */
