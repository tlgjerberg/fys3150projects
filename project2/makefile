CPPflags = g++ -o -03

LIB = -DARMA_DONT_USE_WRAPPER -llapack -lblas

two_elec:
					${CPPflags} two_elec_quantum_dot.cpp toeplitz.cpp maxoffdiag.cpp jacobi.cpp ${LIB} -o two_elec.o

elec:
					${CPPflags} quantum_dot.cpp toeplitz.cpp maxoffdiag.cpp jacobi.cpp ${LIB} -o elec.o

beam:
					${CPPflags} buckling_beam.cpp toeplitz.cpp maxoffdiag.cpp jacobi.cpp ${LIB} -o beam.o

test-jacobi:
						 ${CPPflags} test-main.cpp test-jacobi.cpp toeplitz.cpp maxoffdiag.cpp jacobi.cpp ${LIB} -o test-jacobi.o
