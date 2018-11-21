import numpy as np
import matplotlib.pyplot as plt
import numpy.linalg

""" Script for preforming a linear regression of """

file = "results/means40_2_2_2_4.txt"
file2 = "results/means60_2_2_2_4.txt"
file3 = "results/means80_2_2_2_4.txt"
file4 = "results/means100_2_2_2_4.txt"
file5 = "results/means_L140_T22_24_o.txt"
file6 = "results/means_L160_T22_24_o.txt"


T, chi = np.loadtxt(file, usecols=(1, 9), unpack=True)
chi2 = np.loadtxt(file2, usecols=9)
chi3 = np.loadtxt(file3, usecols=9)
chi4 = np.loadtxt(file4, usecols=9)
chi5 = np.loadtxt(file5, usecols=9)
chi6 = np.loadtxt(file6, usecols=9)

files = [file, file2, file3, file4, file5, file6]

L = np.array([1.0 / 160, 1.0 / 140, 1.0 / 100, 1.0 / 80, 1.0 / 60, 1.0 / 40])
T = np.array([T[np.argmax(chi6)] - L[0], T[np.argmax(chi5)] - L[1],
              T[np.argmax(chi5)] - L[2], T[np.argmax(chi3)] - L[3],
              T[np.argmax(chi2)] - L[4], T[np.argmax(chi)] - L[5]])

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
