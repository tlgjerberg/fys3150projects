import numpy as np
import matplotlib.pyplot as plt
import numpy.linalg

""" Script for preforming a linear regression of """

file = "results/means40_2_2_2_4.txt"
file2 = "results/means60_2_2_2_4.txt"
file3 = "results/means80_2_2_2_4.txt"
file4 = "results/means100_2_2_2_4.txt"


T, chi = np.loadtxt(file, usecols=(1, 9), unpack=True)
chi2 = np.loadtxt(file2, usecols=9)
chi3 = np.loadtxt(file3, usecols=9)
chi4 = np.loadtxt(file4, usecols=9)

files = [file, file2, file3, file4]

L = np.array([1.0 / 100, 1.0 / 80, 1.0 / 60, 1.0 / 40])
T = np.array([T[np.argmax(chi4)] - L[0], T[np.argmax(chi3)] - L[1],
              T[np.argmax(chi2)] - L[2], T[np.argmax(chi)] - L[3]])

z = np.polyfit(L, T, 1)
zz = np.poly1d(z)

print(zz[0], zz[1])

plt.plot(L, T, 'o')
plt.plot(L, zz(L))
plt.legend(['Data', 'Fitted'], prop={'size': 15})
plt.title('Linear regression of critical temperature as a function of L', size=15)
plt.xlabel('1/L', size=15)
plt.ylabel('$T_C$ [k/J]')


plt.show()
