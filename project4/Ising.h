#ifndef ISING_H
#define ISING_H

#include "mpi.h"
#include <armadillo>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <random>

using namespace std;
using namespace arma;

int gen_random(mt19937 &generator);
int PBC(int i, int limit, int add);
void initialize(mat &spin, int n, double &E, double &M, int OS,
                mt19937 &generator);
void flip_one(mat &spin, int xf, int yf);
map<double, double> transitions(double T);
void tryflip(mat &spin, int n, int Delta_E, map<double, double> W, int rx,
             int ry, double &E, double &M, mt19937 &generator, int &Accepted);
void Metropolis(mat &spin, double T, int L, map<double, double> W, double &E,
                double &M, mt19937 &generator,
                uniform_int_distribution<int> rand_spin,
                uniform_real_distribution<float> uni_dist, int &Accepted);
void MC(mat &spin, double T, int L, int mcs, int GS, int *energies,
        int *mag_mom, vec &ExpectVals, int &Accepted, int cut_off);

void addexpect(vec &ExpectVals, double &E, double &M);
void printexpect(vec &TotalExpectVals, double T, int totcycles);
void writetofile(vec &TotalExpectVals, double T, int mc_cut, int L);
void writemeta(int &totcycles, int &Accepted);
#endif // ISING_H
