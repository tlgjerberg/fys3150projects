#ifndef JACOBI_H
#define JACOBI_H

#define _USE_MATH_DEFINES
#include <armadillo>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;
using namespace arma;

vec analytic_eigenvalues_buckling_beam(int n, double hh);
mat toeplitz(int n, double hh);
mat rand_toeplitz(int n);
mat HO_tridiag(int n, double hh, vec rho);
mat HO_tridiag_coulomb(int n, double hh, vec rho, double omega_r);
double maxoffdiag(mat A, int &k, int &l, int n);
void rotation(mat &A, mat &R, int &k, int &l, int n);
vec sort_eigenpairs(mat &R, vec eigval, int n);
vec jacobi_method(mat A, mat &R, double eps, double max, int k, int l, int n);

#endif /* JACOBI_H */
