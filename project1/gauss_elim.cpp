#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
using namespace std;


inline double f( double x){return 100.0*exp(-10*x);} //Analyical function f(x)

//Closed form solution of f
inline double closed_form(double x){return 1 - (1 - exp(-10))*x - exp(-10*x);}

int main(int argc, char* argv[])
{



int n = atoi(argv[1]);
double h = 1.0/double (n+1);
double hh = h*h;


double *d = new double[n+2]; //Declare array for diagonal
double *b = new double[n+2]; //Declare array for right-hand side
double *x = new double[n+2]; //Declare array for x to be used in function f
double *a = new double[n+1]; //Declare array for elements directly below the diagonal
double *c = new double[n+1];
double *f_cf = new double[n+2];
double *u = new double[n+2];


//Setting start and endpoints
x[0] = 0; x[n+1] = 1; b[0] = b[n+2] = 0; a[0] = 0; c[0] = 0; d[0] = d[n+2] = 0;
f_cf[0] = f_cf[n+2] = 0;


// Compute arrays that have been declared.
for (int i = 1; i < n+2; i++){
  x[i] = i*h;
  b[i] = hh*f(x[i]);
  f_cf[i] = closed_form(x[i]);
  a[i] = -1;
  c[i] = -1;
  d[i] = 2;
}
clock_t c_start = clock(); //CPU time clock start
//Gaussian elimination start
for (int i = 2; i < n+2; i++){
  d[i] = d[i] - (a[i-1]*c[i-1])/d[i-1];
  b[i] = b[i] - (b[i-1]*a[i-1])/d[i-1];
}

cout << b[n+1] << endl;
cout << c[n-1] << endl;

u[0] = u[n+2] = 0;

for (int j = n; j > 0; j--){
  u[j] = (b[j] - (c[j]*u[j+1]))/d[j];

}
cout << u[1] << endl;
clock_t c_end = clock(); //CPU time clock stop

cout << fixed << setprecision(2) << "CPU time used: "
      << 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC << " ms\n";

// Printing arrays to file
ofstream ofile;

char *sol_array;

ofile.open("sol_array.txt");

for (int i = 0; i < n+2; i++)
{
  ofile << x[i] << " " << u[i] << " " << f_cf[i] << endl;
}


ofile.close();


  return 0;
}
