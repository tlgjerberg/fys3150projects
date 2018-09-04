#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;


inline double f( double x){return 100.0*exp(-10*x);} //Analyical function f(x)

int main(int argc, char* argv[])
{

ofstream ofile;

char *sol_array;

int n = atoi(argv[1]);
double h = 1.0/(n);
double hh = h*h;


double *d = new double[n+1]; //Declare array for diagonal
double *b = new double[n+1]; //Declare array for right-hand side
double *x = new double[n+1]; //Declare array for x to be used in function f
double *a = new double[n];
double *c = new double[n];

x[0] = x[n] = 0; b[0] = 1; a[0] = -1; c[0] = -1; d[0] = d[n] = 2;


// Compute arrays that have been declared.
for (int i = 1; i < n; i++){
  x[i] = x[i-1]+h;
  b[i] = hh*f(x[i]);
  a[i] = -1;
  c[i] = -1;
  d[i] = 2;
}

// Gaussian elimination start
for (int i = 2; i < n+1; i++){
  d[i] = d[i] - (a[i-1]*c[i-1])/d[i-1];
  b[i] = b[i] - (b[i-1]*a[i-1])/d[i-1];
}

double *u = new double[n+1];

u[0] = u[n] = 0;

ofile.open("sol_array");

for (int j = n-1; j > 0; j--){
  u[j] = b[j] - (c[j]*u[j+1])/d[j];
  ofile << u[j] << endl;
}


ofile.close();

  return 0;
}
