CXX = g++
MPI_CXX = mpic++
CPPflags =  -g -Wall -std=c++11 -O3

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
INCL := -I /usr/local/Cellar/armadillo/9.100.5/include
LIB := -DARMA_DONT_USE_WRAPPER -framework Accelerate
endif

ifeq ($(UNAME), Linux)
INCL :=
LIB := -DARMA_DONT_USE_WRAPPER -lblas -llapack
endif


diffusion.x: PDE.o tridiag.o main.o
					${CXX} ${CPPflags} -o $@ $^ ${INCL} ${LIB}

PDE.o :PDEsolvers.cpp
						${CXX} ${CPPflags} -c $@ $^ ${INCL} ${LIB}

main.o: main.cpp
				${CXX} ${CPPflags} -c $@ $^ ${INCL} ${LIB}

tridiag.o: tridiag_solver.cpp
					${CXX} ${CPPflags} -c $@ $^ ${INCL} ${LIB}



clean:
			rm -f *.o *.dat
