#include "planet.h"
#include "solver.h"
// #include "vec3.h"

planet::planet() {
  x = 1.;
  y = 1.;
  z = 1.;
  vx = 1.;
  vy = 1.;
  vz = 1.;
  mass = 1.;
}

planet::planet(vec position, vec velocity, const double M) {
  x = position[0];
  y = position[1];
  z = position[2];
  vx = velocity[0];
  vy = velocity[1];
  vz = velocity[2];
  mass = M;
}

double planet::distance(planet otherplanet) {
  x = x - otherplanet.x;
  y = y - otherplanet.y;
  z = z - otherplanet.z;
  return sqrt(x * x + y * y + z * z);
}

vec planet::GForce(planet otherplanet) {
  double M1, M2, r;
  M1 = mass;
  M2 = otherplanet.mass;
  r = distance(otherplanet);
  gforce[0] = -G * (M2 * M1 / pow(r, 3)) * (x - otherplanet.x);
  gforce[1] = -G * (M2 * M1 / pow(r, 3)) * (y - otherplanet.y);
  gforce[2] = -G * (M2 * M1 / pow(r, 3)) * (z - otherplanet.z);
  return gforce;
}

vec planet::accel(planet otherplanet) {
  vec acceleration = zeros(3);
  double M2 = otherplanet.mass;
  double r = distance(otherplanet);
  acceleration(0) = -G * M2 * (x - otherplanet.x) / pow(r, 3);
  acceleration(1) = -G * M2 * (y - otherplanet.y) / pow(r, 3);
  acceleration(2) = -G * M2 * (z - otherplanet.z) / pow(r, 3);
  return acceleration;
}

// double planet::kinetic() { return 0.5 * mass * (vx * vx + vy * vy + vz * vz);
// } double planet::potential(planet otherplanet) {
//   return -G(mass * otherplanet.mass) / distance(otherplanet);
// }
