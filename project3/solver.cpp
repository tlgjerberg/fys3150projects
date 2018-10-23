#include "planet.h"
#include "solar_system.h"
#include "solver.h"
#define _USE_MATH_DEFINES

solver::solver() { radius = 1.0; }

solver::solver(double r) { radius = r; }

// void solver::acceleration() {}

void solver::euler(planet &current, planet &other, int n, double h) {
  x = current.x;
  y = current.y;
  z = current.z;
  vx = current.vx;
  vy = current.vy;
  vz = current.vz;
  ofstream ofile;

  char *sol_array;

  ofile.open("sol_array.txt");
  for (int i = 0; i < n; i++) {
    double r = current.distance(other);
    vx += -h * (4 * pow(M_PI, 2) / pow(r, 3)) * x;
    vy += -h * (4 * pow(M_PI, 2) / pow(r, 3)) * y;
    vz += -h * (4 * pow(M_PI, 2) / pow(r, 3)) * z;
    x += h * vx;
    y += h * vy;
    z += h * vz;
    if (i % 10 == 0) {
      ofile << x << " " << y << endl;
    }
  }
  ofile.close();
  return;
}

/* Velocity verlet for integrating the positions and velocities of all planets
 in the SolarSystem object*/
void solver::verlet(SolarSystem &input_obj, int n, double h) {
  solsys = &input_obj;

  // vector of objects of planets given in the solar system
  vector<planet> &bodies = solsys->objects();

  double hh = h * h;

  int dim = bodies.size(); // Size of the vector of planets
  cout << dim << endl;
  mat a_next(3, dim); // Declare empty acceleration matrix
  mat a(3, dim);      // Declare empty acceleration matrix

  // vec a, a_next;

  for (int i = 0; i < n; i++) {

    // If test to ensure that only every 10th step is printed
    if (i % 10 == 0) {
      // Loop for printing x, y, z coordinates of each celestial object to a
      // diffeent file
      for (int k = 0; k < dim; k++) {
        ofstream ofile;
        string filename[dim];
        filename[k] = to_string(k);
        filename[k].append(".txt");
        ofile.open(filename[k], fstream::app);

        // cout << bodies[k].position(0) << " " << bodies[k].position(1) << " "
        //      << bodies[k].position(2) << "\n";
        ofile << bodies[k].position(0) << " " << bodies[k].position(1) << " "
              << bodies[k].position(2) << "\n";
        ofile.close();
      }
    }

    a = zeros(3, dim);    // Resets acceleration for each step
    a += solsys->accel(); // Adds acceleration for all planets

    // Integrating the position each planet
    for (int j = 0; j < dim; j++) {

      bodies[j].position += h * bodies[j].velocity + (hh / 2) * a.col(j);
      // cout << bodies.position << endl;
    }
    a_next = zeros(3, dim);    // Resets the next step of the acceleration
    a_next += solsys->accel(); // Adds the acceleration for the next step after
                               // finding the new positions

    // Integrating the velocity of each planet
    for (int j = 0; j < dim; j++) {

      bodies[j].velocity += (h / 2) * (a_next.col(j) + a.col(j));
    }
  }

  return;
}
