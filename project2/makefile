CPPflags = g++ -o -03

LIB = -DARMA_DONT_USE_WRAPPER -llapack -lblas

elec:		main_ee.o toeplitz.o maxoffdiag.o jacobi.o
					${CPPflags} main_ee.cpp toeplitz.cpp maxoffdiag.cpp jacobi.cpp ${LIB} -o elec.o

beam:		main_beam.o toeplitz.o maxoffdiag.o jacobi.o
					${CPPflags} main_beam.cpp toeplitz.cpp maxoffdiag.cpp jacobi.cpp ${LIB} -o beam.o

# main_beam.o: main_beam.cpp jacobi.h
# 						${CPPflags} -c main_beam.cpp
#
# main_ee.o: main_ee.cpp jacobi.h
# 						${CPPflags} -c main_ee.cpp
#
# toeplitz.o: toeplitz.cpp
# 						${CPPflags} -c toeplitz.cpp
#
# maxoffdiag.o: maxoffdiag.cpp
# 							${CPPflags} -c maxoffdiag.cpp
#
# jacobi.o:	jacobi.cpp
# 					${CPPflags} -c jacobi.cpp



# clean:
# 			rm *o elec
