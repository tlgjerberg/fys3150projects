CXX = g++
MPI_CXX = mpic++
CPPflags_r =  -Wall
CPPflags_o =  -03

LIB = -DARMA_DONT_USE_WRAPPER -llapack -lblas

test: ising.o
			${MPI_CXX} ${CPPflags_r} main.cpp ising.cpp  ${LIB} -o ising.o

final:

clean:
			rm -f *.o *.dat *.txt
