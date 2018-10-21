#include "planet.h"
#include "solver.h"
// #include "vec3.h"

// Default constructor
planet::planet() {
  x = 1.;
  y = 1.;
  z = 1.;
  vx = 1.;
  vy = 1.;
  vz = 1.;
  mass = 1.;
  position = {0, 0, 0};
  velocity = {0, 0, 0};
  // acceleration = {0, 0, 0};
}

// Constructor creating a planet object with known initial condition
planet::planet(vec pos, vec vel, const double M) {

  mass = M;
  position = pos;
  velocity = vel;
  x = position(0);
  y = position(1);
  z = position(2);
  vx = velocity(0);
  vy = velocity(1);
  vz = velocity(2);
}

// Finds the distance between two objects
double planet::distance(planet otherplanet) {
  double delta_x = this->x - otherplanet.x;
  double delta_y = this->y - otherplanet.y;
  double delta_z = this->z - otherplanet.z;
  return sqrt(delta_x * delta_x + delta_y * delta_y + delta_z * delta_z);
}

vec planet::GForce(planet otherplanet) {
  double M1, M2, r;
  vec gforce = zeros(3);
  M1 = this->mass;
  M2 = otherplanet.mass;
  r = distance(otherplanet);
  gforce(0) = -G * (M2 * M1 / pow(r, 3)) * (this->x - otherplanet.x);
  gforce(1) = -G * (M2 * M1 / pow(r, 3)) * (this->y - otherplanet.y);
  gforce(2) = -G * (M2 * M1 / pow(r, 3)) * (this->z - otherplanet.z);
  return gforce;
}

vec planet::accel(planet otherplanet) {

  acceleration = zeros(3);
  double M2 = otherplanet.mass;
  double r = distance(otherplanet);
  acceleration(0) = -G * M2 * (this->x - otherplanet.x) / pow(r, 3);
  acceleration(1) = -G * M2 * (this->y - otherplanet.y) / pow(r, 3);
  acceleration(2) = -G * M2 * (this->z - otherplanet.z) / pow(r, 3);
  return acceleration;
}

// vec planet::accel(planet otherplanet) {
//   acceleration = zeros(3);
//   double M2 = otherplanet.mass;
//   double r = distance(otherplanet);
//   acceleration(0) = -G * M2 * (x - otherplanet.x) / pow(r, 3);
//   acceleration(1) = -G * M2 * (y - otherplanet.y) / pow(r, 3);
//   acceleration(2) = -G * M2 * (z - otherplanet.z) / pow(r, 3);
//   return acceleration;
// }

// vec planet::accel_reset() { acceleration = zeros(3) }

// double planet::kinetic() { return 0.5 * mass * (vx * vx + vy * vy + vz * vz);
// } double planet::potential(planet otherplanet) {
//   return -G(mass * otherplanet.mass) / distance(otherplanet);
// }
