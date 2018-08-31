#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double ** CreateMatrix(int row, int col);

double *CreateVector(int n);

int main(int argc , char* argv[])
{
int n = 4;
double **A;
A = CreateMatrix(n, n);
  for (int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      A[i][j] = (j*3)/3;
    }

  }

return 0;
}


double **CreateMatrix(int row, int col)
{
  double **M;
  M = new double*[row];
  for (int i = 0; i < row; i++){
    M[i] = new double[col];
  }

  }
  return (double **)M;
}

double *CreateVector(int n)
{
 double *v;
 v = new double[n];

 return (double *)v;
}
