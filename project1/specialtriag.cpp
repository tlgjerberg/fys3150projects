#include <cstdlib>
#include <cmath>
#include <iostream>


inline double f( double x){return 100.0*exp(-10*x);}

int main(int argc, char* argv[]) {

int n = atoi(argv[1]);
double h = 1.0/(n);
double hh = h*h;


// No array a and c are necessary
double *d = new double[n+1];
double *b = new double[n+1]; double *x = new double[n+1];



double d_arg[n] = {2, 5, 7, 6};
double c_arg[n-1] = {2, 9, 3};

x[0] = 0; b[0] = 1; d[0] = d_arg[0];

for (int i = 1; i < n; i++){
  x[i] = x[i-1]+h;
  b[i] = hh*f(x[i]);
}

for (int i = 1; i < n+1; i++){
  d[i] = d_arg[i] - 1.0/d[i-1];
  b[i] = b[i] - (b[i-1]*(-1))/d[i-1];
}

double *u = new double[n+1];

u[n] = b[n]/d[n];

for (int j = n-1; j > 0; j++){
  ;
}

}
