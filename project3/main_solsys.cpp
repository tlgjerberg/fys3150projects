#include "planet.h"
#include "solar_system.h"
#include "solver.h"
// #include "vec3.h"

int main(int argc, char const *argv[]) {
  double t = 10.0;
  int n = 1000;
  int N = n * t;
  double h = t / N;
  vec pos1 = zeros(3);
  pos1(0) = 1;
  pos1(1) = 0;
  pos1(2) = 0;
  vec vel1 = zeros(3);
  vel1(0) = 0;
  vel1(1) = 2 * M_PI;
  vel1(2) = 0;
  vec pos2 = zeros(3);
  vec vel2 = zeros(3);
  planet planet1(pos1, vel1, 0.0003);
  planet planet2(pos2, vel2, 1);
  cout << planet1.distance(planet2) << endl;
  // vec gforce = planet1.GForce(planet2);
  solver binobj(planet1.distance(planet2));
  binobj.verlet(planet1, planet2, N, h);
  // binobj.euler(planet1, planet2, N, h);
  return 0;
}
