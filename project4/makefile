CXX = g++
MPI_CXX = mpic++
CPPflags_r =  -Wall
CPPflags_o =  -O3

LIB = -DARMA_DONT_USE_WRAPPER -llapack -lblas



ising.o: ising.o
			${MPI_CXX} ${CPPflags_r} main.cpp Ising.cpp  ${LIB} -o ising.o

ising_opt.o :ising.cpp main.cpp
						${MPI_CXX} ${CPPflags_o} main.cpp Ising.cpp  ${LIB} -o ising.o


clean:
			rm -f *.o *.dat *.txt
