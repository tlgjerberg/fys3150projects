#ifndef JACOBI_H
#define JACOBI_H

#include <armadillo>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;
using namespace arma;

mat toeplitz(int n, double hh);
mat rand_toeplitz(int n, double hh);
double maxoffdiag(mat A, int &k, int &l, int n);
void rotation(mat &A, int &k, int &l, int n);

#endif /* JACOBI_H */
