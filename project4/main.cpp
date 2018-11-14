#include "Ising.h"

int main(int argc, char *argv[]) {
  char *outfilename = argv[1];
  int initial_temp = atof(argv[2]);
  int final_temp = atof(argv[3]);
  int temp_step = atoi(argv[4]);
  int totcycles = atoi(argv[5]);
  // int mcs = atoi(argv[5]);
  int L = atoi(argv[6]);
  // cout << mcs << endl;
  char *outfilename2;

  int numprocs, my_rank;

  mat spin = zeros(L, L);
  double E, M, total_E, total_M;
  E = 0;
  M = 0;
  int GS = 1;
  double T = initial_temp;

  ofstream outfile;

  // initialize(spin, L, E, M, GS);
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

  int mcs = totcycles / numprocs;
  int *energies;
  int *mag_mom;
  energies = new int[mcs];
  mag_mom = new int[mcs];
  // broadcast to all nodes common variables
  // MPI_Bcast(&L, 1, MPI_INT, 0, MPI_COMM_WORLD);
  // MPI_Bcast(&initial_temp, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  // MPI_Bcast(&final_temp, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  // MPI_Bcast(&temp_step, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

  double Timestart, Timeend, Totaltime;
  Timestart = MPI_Wtime();

  // for (int T = initial_temp; T < final_temp; T += temp_step) {

  MC(spin, T, L, E, M, mcs, GS, energies);
  if (numprocs == 1) {
    if (my_rank == 0) {

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
      MPI_Send(energies, mcs, MPI_INT, 0, 500, MPI_COMM_WORLD);
    }
  }

  MPI_Reduce(&E, &total_E, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
  MPI_Reduce(&M, &total_M, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  Timeend = MPI_Wtime();
  Totaltime = Timeend - Timestart;
  if (my_rank == 0) {
    cout << "Time = " << Totaltime << " on number of processors: " << numprocs
         << endl;
  }
  // if (rank == 0) {
  outfilename2 = "mean_energy.txt";
  ofstream meanfile;
  meanfile.open(outfilename2);
  meanfile << total_E << " " << total_M;
  meanfile.close();
  // }
  // delete energies;
  // delete[] energies;
  // }
  MPI_Finalize();

  return 0;
}
