#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <armadillo>
using namespace std;
using namespace arma;

inline double f( double x){return 100.0*exp(-10*x);} //Analytical function f(x)

//Closed form solution of f
inline double closed_form(double x){return 1 - (1 - exp(-10))*x - exp(-10*x);}

int main(int argc, char* argv[])
{

int n = atoi(argv[1]);
double h = 1.0/double (n+1);
double hh = h*h;

double *x = new double[n]; //Declare array for x to be used in function f
x[0] = 0; x[n] = 1;
double *f_cf = new double[n];

vec b = zeros(n);


for (int i = 1; i < n; i++)
{
  x[i] = i*h;
  b[i] = hh*f(x[i]);
  f_cf[i] = closed_form(x[i]);
}

mat A = zeros(n, n);
A.diag() += 2;
A.diag(1) += -1;
A.diag(-1) += -1;

clock_t c_start = clock(); //CPU time clock start

vec v = solve(A, b);

clock_t c_end = clock(); //CPU time clock stop

ofstream tfile; //Setting up file for time output

//Writing n and CPU-time in milliseconds to file for each run of the program
tfile.open("CPUtime.txt", ofstream::app);

tfile << n << " " << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << endl;

tfile.close();

//Output of CPU-time of the algorithm in milliseconds
cout << fixed << setprecision(2) << "CPU time used: "
      << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms\n";

// Printing x, numerical and analytical to file
ofstream ofile;

char *sol_array;

ofile.open("sol_array.txt");

for (int i = 1; i < n; i++)
{
  ofile << x[i] << " " << v[i] << " " << f_cf[i] << endl;
}

ofile.close();

return 0;
}
