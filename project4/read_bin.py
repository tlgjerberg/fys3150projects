import numpy as np
import matplotlib.pyplot as plt

E = np.loadtxt("means.txt", usecols=1)
T = np.loadtxt("means.txt", usecols=3)
C_V = np.loadtxt("means.txt", usecols=5)
chi = np.loadtxt("means.txt", usecols=7)


file = "energy.dat"
array = np.fromfile(file, dtype="int32", count=-1)


mcs = np.linspace(0, len(array), len(array))

plt.figure('Probability')
plt.hist(array[100:], bins=40)
plt.xlabel('Monte Carlo cycles')
plt.figure()
plt.plot(mcs, array)
plt.xlabel('Monte Carlo cycles')
plt.ylabel('E')
plt.figure()
plt.plot(T, E)
plt.xlabel('Temperature')
plt.ylabel('<E>')
plt.figure()
plt.plot(T, C_V)
plt.figure()
plt.plot(T, chi)
plt.show()
