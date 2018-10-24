CPPflags = g++ -O3

LIB = -DARMA_DONT_USE_WRAPPER -llapack -lblas

solsys: main_solsys.o planet.o solver.o solar_system.o
	${CPPflags} planet.cpp solver.cpp solar_system.cpp main_solsys.cpp ${LIB} -o solsys.o
