

CPPflags = g++ -o -03

LIB = -DARMA_DONT_USE_WRAPPER -llapack -lblas

PROG = elec
${PROG}:			main_ee.o toeplitz.o maxoffdiag.o jacobi.o jacobi_method.o
							${CPPflags} main_ee.cpp toeplitz.cpp maxoffdiag.cpp jacobi.cpp jacobi_method.cpp ${LIB} -o ${PROG}


main_ee.o: main_ee.cpp jacobi.h
						${CPPflags} -c main_ee.cpp

toeplitz.o: toeplitz.cpp
						${CPPflags} -c toeplitz.cpp

maxoffdiag.o: maxoffdiag.cpp
							${CPPflags} -c maxoffdiag.cpp

jacobi.o:	jacobi.cpp
					${CPPflags} -c jacobi.cpp

jacobi_method.o:  jacobi_method.cpp
									${CPPflags} -c jacobi_method.cpp


clean:
			rm *o elec
