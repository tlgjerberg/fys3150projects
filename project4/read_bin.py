import numpy as np
import matplotlib.pyplot as plt

T = np.loadtxt("means40.txt", usecols=1)
E = np.loadtxt("means40.txt", usecols=3)
M = np.loadtxt("means40.txt", usecols=5)
C_V = np.loadtxt("means40.txt", usecols=7)
chi = np.loadtxt("means40.txt", usecols=9)
# print(T)
# print(E)


file = "energy.dat"
array = np.fromfile(file, dtype="int32", count=-1)


mcs = np.linspace(0, len(array), len(array))

# plt.figure('Probability')
# plt.hist(array[100:], bins=40)
# plt.xlabel('Monte Carlo cycles')
# plt.figure()
# plt.plot(mcs, array)
# plt.xlabel('Monte Carlo cycles')
# plt.ylabel('E')
plt.figure('Mean energy')
plt.plot(T, E)
plt.xlabel('Temperature')
plt.ylabel('<E>')
plt.figure('Mean magnetisation')
plt.plot(T, M)
plt.xlabel('Temperature')
plt.ylabel('<|M|>')
plt.figure('Heat capacity')
plt.plot(T, C_V)
plt.xlabel('Temperature')
plt.ylabel('$C_{V}$')
plt.figure('Susceptibility')
plt.plot(T, chi)
plt.xlabel('Temperature')
plt.ylabel('chi')
plt.show()
