#ifndef JACOBI_H
#define JACOBI_H

#include <armadillo>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;
using namespace arma;

mat toeplitz(int n, double hh);
mat rand_toeplitz(int n, double hh);
mat HO_toeplitz(int n, double hh, vec rho);
mat HO_toeplitz_coulomb(int n, double hh, vec rho, double omega_r);
double maxoffdiag(mat A, int &k, int &l, int n);
void rotation(mat &A, mat &R, int &k, int &l, int n);
vec eigenpairs(mat &R, vec eigval, int n);
vec jacobi_method(mat A, mat &R, double eps, double max, int k, int l, int n);

#endif /* JACOBI_H */
