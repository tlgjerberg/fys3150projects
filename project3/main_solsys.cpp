#include "planet.h"
#include "solar_system.h"
#include "solver.h"
// #include "vec3.h"

int main(int argc, char const *argv[]) {
  double t = 10.0;
  int n = 1000;
  int N = n * t;
  double h = t / N;
  SolarSystem solsys;
  vec pos1 = {1, 0, 0};
  vec vel1 = {0, 2 * M_PI, 0};
  vec pos2 = {0, 0, 0};
  vec vel2 = {0, 0, 0};
  vec pos3 = {5.2, 0, 0};
  vec vel3 = {0, 2 * M_PI, 0};
  planet planet1(pos1, vel1, 0.000003);
  planet planet2(pos2, vel2, 1);
  planet planet3(pos3, vel3, 0.00095);
  solsys.add_celestial_objects(planet1);
  solsys.add_celestial_objects(planet2);
  // solsys.add_celestial_objects(planet3);
  cout << solsys.length() << endl;
  cout << planet1.distance(planet2) << endl;
  cout << solsys.accel() << endl;
  cout << solsys.position() << endl;

  // vec gforce = planet1.GForce(planet2);
  solver binobj;
  binobj.verlet(solsys, N, h);
  // binobj.euler(planet1, planet2, N, h);
  return 0;
}
