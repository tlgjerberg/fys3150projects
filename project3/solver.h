#ifndef Solver_H
#define Solver_H
#define _USE_MATH_DEFINES

#include "solar_system.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

using std::vector;
using namespace std;

class solver {
private:
  double G;

public:
  friend class planet;
  double radius;
  vector<double> planets;

  solver();
  solver(double r);
  void euler(planet &current, planet &other, int n, double h);
};

#endif // Solver_H
