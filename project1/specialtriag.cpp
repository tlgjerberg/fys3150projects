#include <cstdlib>
#include <cmath>
#include <iostream>


inline double f( double x){return 100.0*exp(-10*x);}

int main(int argc, char* argv[]) {

int n = atoi(argv[1]);
double h = 1.0/(n);
double hh = h*h;


double *d = new double[n+1]; double *a = new double[n];
double *b = new double[n+1];
double *c = new double[n]; double *x = new double[n+1];

x[0] = h; b[0] = 2; a[0] = -1; c[0] = -1;

for (int i = 1; i < n+1; i++){
  x[i] = x[i-1]+h;
  b[i] = hh*f(x[i]);
  a[i] = -1;
  c[i] = -1;
  d[i] = 2;
}

double *u = new double[n+1];
for (int j = 0; j < n; j++){
  u[j] = (1/b[j])*();
}



  return 0;
}
