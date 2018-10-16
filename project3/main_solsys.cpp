#include "planet.h"
#include "solar_system.h"
#include "solver.h"
// #include "vec3.h"

int main(int argc, char const *argv[]) {
  double t = 10.0;
  int n = 1000;
  int N = n * t;
  double h = t / N;
  planet planet1(vec3(1, 0, 0), vec3(0, 2 * M_PI, 0), 0.0003);
  planet planet2(vec3(0, 0, 0), vec3(0, 0, 0), 1);
  // cout << planet1.distance(planet2) << endl;
  vec3 gforce = planet1.GForce(planet2);
  solver binobj(planet1.distance(planet2));
  binobj.verlet(planet1, planet2, N, h);
  // binobj.euler(planet1, planet2, N, h);
  return 0;
}
