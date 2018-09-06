#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;


inline double f( double x){return 100.0*exp(-10*x);} //Analyical function f(x)

//Closed form solution of f
inline double closed_form(double x){return 1 - (1 - exp(-10))*x - exp(-10*x);}

int main(int argc, char* argv[])
{

  ofstream ofile;

  char *error;

  ofile.open("error.txt");

  int m = atoi(argv[1]);

for (int n = 10; n <= pow(10, m); n *= 10)
{

double h = 1.0/double (n+1);
double hh = h*h;


double *d = new double[n+2]; //Declare array for diagonal
double *b = new double[n+2]; //Declare array for right-hand side
double *x = new double[n+2]; //Declare array for x to be used in function f
double *a = new double[n+1]; //Declare array for elements directly below the diagonal
double *c = new double[n+1];
double *f_cf = new double[n+2];
double *u = new double[n+2];
double temp; //Temporary value for storing
double *eps = new double[n+2];
double *max_er = new double[m];
int iter_count = 0;


//Setting start and endpoints
x[0] = 0; x[n+1] = 1; b[0] = b[n+2] = 0; a[0] = 0; c[0] = 0; d[0] = d[n+2] = 0;
f_cf[0] = f_cf[n+2] = 0; u[0] = u[n+2] = 0;


// Compute arrays that have been declared.
for (int i = 1; i < n+2; i++){
  x[i] = i*h;
  b[i] = hh*f(x[i]);
  f_cf[i] = closed_form(x[i]);
  d[i] = 2;
}
clock_t c_start = clock(); //CPU time clock start
//Gaussian elimination start
for (int i = 2; i < n+2; i++){
  temp = 1/d[i-1];
  d[i] = d[i] - temp;
  b[i] = b[i] + b[i-1]*temp;
}

for (int j = n; j > 0; j--){
  u[j] = (b[j] - ((-1)*u[j+1]))/d[j];

}

clock_t c_end = clock(); //CPU time clock stop

cout << fixed << "CPU time used: "
      << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms\n";


// Computing logarithm of the error
for (int i = 1; i < n+1; i++)
{
  eps[i] = log10(abs((u[i] - f_cf[i])/f_cf[i]));
    if (eps[i] > eps[i-1])
    {
      // finding maximum error for n
      max_er[iter_count] = eps[i];
    }

}
cout << *max_er;
// Printing error to file

ofile << n << " " << max_er[iter_count]  << endl;
iter_count += 1 //Increase index of maximum array values by 1

}

ofile.close();
return 0;

}
