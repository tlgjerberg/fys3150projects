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


ising.x: ising.o main.o
					${MPI_CXX} ${CPPflags} -o $@ $^ ${INCL} ${LIB}

ising_abcd.x: ising.o main_abcd.o
							${MPI_CXX} ${CPPflags} -o $@ $^ ${INCL} ${LIB}
ising.o :Ising.cpp
						${MPI_CXX} ${CPPflags} -c $@ $^ ${INCL} ${LIB}

main.o: main.cpp
				${MPI_CXX} ${CPPflags} -c $@ $^ ${INCL} ${LIB}

main_abcd.o: main_abcd.cpp
					${MPI_CXX} ${CPPflags} -c $@ $^ ${INCL} ${LIB}


clean:
			rm -f *.o *.dat 
