CPPflags = g++ -o -03

LIB = -DARMA_DONT_USE_WRAPPER -llapack -lblas

two_elec:		main_ee.o toeplitz.o maxoffdiag.o jacobi.o
					${CPPflags} main_ee.cpp toeplitz.cpp maxoffdiag.cpp jacobi.cpp ${LIB} -o two_elec.o

elec:		main_e.o toeplitz.o maxoffdiag.o jacobi.o
					${CPPflags} main_e.cpp toeplitz.cpp maxoffdiag.cpp jacobi.cpp ${LIB} -o elec.o

beam:		main_beam.o toeplitz.o maxoffdiag.o jacobi.o
					${CPPflags} main_beam.cpp toeplitz.cpp maxoffdiag.cpp jacobi.cpp ${LIB} -o beam.o


# Run without this part to save all .o files
main_beam.o: main_beam.cpp jacobi.h
						${CPPflags} -c main_beam.cpp

main_ee.o: main_ee.cpp jacobi.h
						${CPPflags} -c main_ee.cpp

main_e.o: main_e.cpp jacobi.h
					${CPPflags} -c main_e.cpp

toeplitz.o: toeplitz.cpp
						${CPPflags} -c toeplitz.cpp

maxoffdiag.o: maxoffdiag.cpp
							${CPPflags} -c maxoffdiag.cpp

jacobi.o:	jacobi.cpp
					${CPPflags} -c jacobi.cpp



# clean:
# 			rm *o elec
