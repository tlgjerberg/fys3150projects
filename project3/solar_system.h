#ifndef Solar_system_H
#define Solar_system_H

#include <cmath>
#include <fstream>
#include <iostream>

class Solar_system {
private:
  double MS = 2e30;
  double ME = 6e24;
  double G = 6.67e-11;
};
void verlet(double *x, double *y, double *vx, double *vy, int n, double h,
            double MS, double G)

#endif
