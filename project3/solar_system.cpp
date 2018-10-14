#include "solar_system.h"
#include "solver.h"
#include "vec3.h"

planet::planet() {
  x = 1.;
  y = 1.;
  z = 1.;
  vx = 1.;
  vy = 1.;
  vz = 1.;
  kinetic = 1.;
  potential = 1.;
}

planet::planet(vec3 position, vec3 velocity) {
  x = position[0];
  y = position[1];
  z = position[2];
  vx = velocity[0];
  vy = velocity[1];
  vz = velocity[2];
  kinetic = 1.;
  potential = 1.;
}

double planet::distance(planet otherplanet) {
  double x, y;
  x = x - otherplanet.x;
  y = y - otherplanet.y;
  z = z - otherplanet.z;
  return sqrt(x * x + y * y + z * z);
}

double planet::GForce(planet otherplanet) {
  double M1, M2, r;
  M1 = mass;
  M2 = otherplanet.mass;
  r = distance(otherplanet);

  return -((G * M1 * M2) / r * r);
}
