#include "planet.h"
#include "solar_system.h"
#include "solver.h"
#include "vec3.h"

int main(int argc, char const *argv[]) {
  int n = 100;
  double h = 0.01;
  planet planet1(vec3(0, 1, 0), vec3(1, 2, 0), 6e24);
  planet planet2(vec3(0, 0, 0), vec3(0, 0, 0), 2e30);
  cout << planet1.distance(planet2) << endl;
  vec3 gforce = planet1.GForce(planet2);
  solver binobj(planet1.distance(planet2));
  binobj.verlet(planet1, planet2, n, h, gforce);
  // binobj.euler(planet1, planet2, n, h);
  return 0;
}
