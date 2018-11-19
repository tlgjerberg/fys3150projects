#include "Ising.h"

int main(int argc, char *argv[]) {
  char *outfilename = argv[1];
  char *outfilename2 = argv[2];
  double T = atof(argv[3]);

  int totcycles = atoi(argv[4]);
  int L = atoi(argv[5]);
  int GS = atoi(argv[6]);
  int numprocs, my_rank;
  int Accepted = 0;

  mat spin = zeros(L, L);

  ofstream outfile1;
  ofstream outfile2;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

  int mcs = totcycles / numprocs;
  // int cut_off = 0;
  int cut_off = mcs * 0.05; // Cut off for part 4d
  int *energies;
  int *mag_mom;
  energies = new int[mcs];
  mag_mom = new int[mcs];

  // broadcast to all nodes common variables
  MPI_Bcast(&L, 1, MPI_INT, 0, MPI_COMM_WORLD);

  double Timestart, Timeend, Totaltime;
  Timestart = MPI_Wtime();

  vec ExpectVals = zeros<vec>(5);
  vec TotalExpectVals = zeros<vec>(5);

  MC(spin, T, L, mcs, GS, energies, mag_mom, ExpectVals, Accepted, cut_off);
  if (numprocs == 1) {
    if (my_rank == 0) {

      /* MPI process for writing all energies to a file specified as argv[1]
       */

      MPI_Status status;
      outfile1.open(outfilename, ios::binary);
      outfile2.open(outfilename2, ios::binary);
      outfile1.write(reinterpret_cast<const char *>(energies),
                     mcs * sizeof(int));
      outfile2.write(reinterpret_cast<const char *>(mag_mom),
                     mcs * sizeof(int));

      for (int i = 1; i < numprocs; i++) {
        MPI_Recv(energies, mcs, MPI_INT, MPI_ANY_SOURCE, 500, MPI_COMM_WORLD,
                 &status);
        MPI_Recv(mag_mom, mcs, MPI_INT, MPI_ANY_SOURCE, 500, MPI_COMM_WORLD,
                 &status);
        outfile1.write(reinterpret_cast<const char *>(energies),
                       mcs * sizeof(int));
        outfile2.write(reinterpret_cast<const char *>(mag_mom),
                       mcs * sizeof(int));
      }

      outfile1.close();
      outfile2.close();
    } else {
      // Processes of rank 1 to numprocs sends results to the process of rank 0
      MPI_Send(energies, mcs, MPI_INT, 0, 500, MPI_COMM_WORLD);
      MPI_Send(mag_mom, mcs, MPI_INT, 0, 500, MPI_COMM_WORLD);
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
    writemeta(totcycles, Accepted);
    writetofile(TotalExpectVals, T, totcycles - cut_off, L);
  }

  // delete energies;
  // delete[] energies;
  MPI_Finalize();

  return 0;
}
