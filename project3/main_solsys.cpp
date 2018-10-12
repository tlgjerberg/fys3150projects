#include "solar_system.h"
#include "solver.h"

int main(int argc, char const *argv[]) {
  int n = 100;
  double h = 0.01;
  planet planet1(1, 0, 0, 2 * M_PI);
  planet planet2(2, 1, 1, 0);
  cout << planet1.distance(planet2) << endl;
  cout << planet1.GForce(planet2) << endl;
  solver binobj(planet1.distance(planet2));
  binobj.euler(planet1, planet2, n, h);
  return 0;
}
