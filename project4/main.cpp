#include "Ising.h"

int main(int argc, char *argv[]) {
  char *outfilename = argv[1];
  double initial_temp = atof(argv[2]);
  double final_temp = atof(argv[3]);
  double temp_step = atof(argv[4]);
  int totcycles = atoi(argv[5]);
  int L = atoi(argv[6]);
  int GS = atoi(argv[7]);
  int numprocs, my_rank;
  int Accepted = 0;

  mat spin = zeros(L, L);

  // double T = initial_temp;

  ofstream outfile;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

  int mcs = totcycles / numprocs;
  int *energies;
  // int *mag_mom;
  energies = new int[mcs];
  // mag_mom = new int[mcs];

  // broadcast to all nodes common variables
  MPI_Bcast(&L, 1, MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Bcast(&initial_temp, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  MPI_Bcast(&final_temp, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  MPI_Bcast(&temp_step, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

  double Timestart, Timeend, Totaltime;
  Timestart = MPI_Wtime();

  for (double T = initial_temp; T < final_temp; T += temp_step) {
    vec ExpectVals = zeros<vec>(5);
    vec TotalExpectVals = zeros<vec>(5);

    MC(spin, T, L, mcs, GS, energies, ExpectVals, Accepted);
    if (numprocs == 1) {
      if (my_rank == 0) {

        /* MPI process for writing all energies to a file specified as argv[1]
         */

        MPI_Status status;
        outfile.open(outfilename, ios::binary);
        outfile.write(reinterpret_cast<const char *>(energies),
                      mcs * sizeof(int));

        for (int i = 1; i < numprocs; i++) {
          MPI_Recv(energies, mcs, MPI_INT, MPI_ANY_SOURCE, 500, MPI_COMM_WORLD,
                   &status);
          outfile.write(reinterpret_cast<const char *>(energies),
                        mcs * sizeof(int));
        }

        outfile.close();
      } else {
        // Processes of rank 1-numprocs sends results to the process of rank 0
        MPI_Send(energies, mcs, MPI_INT, 0, 500, MPI_COMM_WORLD);
      }
    }
    for (int i = 0; i < 5; i++) {
      MPI_Reduce(&ExpectVals(i), &TotalExpectVals(i), 1, MPI_DOUBLE, MPI_SUM, 0,
                 MPI_COMM_WORLD);
    }

    Timeend = MPI_Wtime();
    Totaltime = Timeend - Timestart;
    // Retrieving information from the master(rank 0) process
    if (my_rank == 0) {
      cout << "Time = " << Totaltime << " on number of processors: " << numprocs
           << endl;

      // printexpect(TotalExpectVals, T, totcycles);
      writetofile(TotalExpectVals, T, totcycles, L);
    }

    // delete energies;
    // delete[] energies;
  }
  MPI_Finalize();

  return 0;
}
