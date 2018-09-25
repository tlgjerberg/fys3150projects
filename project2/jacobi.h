#ifndef JACOBI_H
#define JACOBI_H

#include <armadillo>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;
using namespace arma;

double maxoffdiag(mat A, int &k, int &l, int n);
void rotation(mat &A, int &k, int &l, int n);

#endif /* JACOBI_H */
