import numpy as np
import matplotlib.pyplot as plt

T, E, M, C_V, chi = np.loadtxt(
    "means.txt", usecols=(1, 3, 5, 7, 9), unpack=True)
T40, E40, M40, C_V40, chi40 = np.loadtxt(
    "results/means40.txt", usecols=(1, 3, 5, 7, 9), unpack=True)
T60, E60, M60, C_V60, chi60 = np.loadtxt(
    "results/means60.txt", usecols=(1, 3, 5, 7, 9), unpack=True)
T80, E80, M80, C_V80, chi80 = np.loadtxt(
    "results/means80.txt", usecols=(1, 3, 5, 7, 9), unpack=True)
# T100, E100, M100, C_V100, chi100 = np.loadtxt(
#     "results/means100.txt", usecols=(1, 3, 5, 7, 9), unpack=True)


#===============================================================================
# Plots 4c)
#===============================================================================

# file = "energy.dat"
# array = np.fromfile(file, dtype="int32", count=-1)
#
#
# mcs = np.linspace(0, len(array), len(array))

#===============================================================================
# Plots 4d)
#===============================================================================

# plt.figure('Probability')
# plt.hist(array[100:], bins=48)
# plt.xlabel('Monte Carlo cycles')
# plt.figure()
# plt.plot(mcs, array)
# plt.xlabel('Monte Carlo cycles')
# plt.ylabel('E')

#===============================================================================
# Plots 4e)
#===============================================================================
# plt.figure("Testplot")
# plt.plot(T, C_V)

plt.figure('Mean energy')
plt.plot(T40, E40)
plt.plot(T60, E60)
plt.plot(T80, E80)
# plt.plot(T100, E100)
plt.legend(['L=40', 'L=60', 'L=80', 'L=100'])
plt.xlabel('Temperature')
plt.ylabel('<E>')
plt.figure('Mean magnetisation')
plt.plot(T40, M40)
plt.plot(T60, M60)
plt.plot(T80, M80)
# plt.plot(T100, M100)
plt.legend(['L=40', 'L=60', 'L=80', 'L=100'])
plt.xlabel('Temperature')
plt.ylabel('<|M|>')
plt.figure('Heat capacity')
plt.plot(T40, C_V40)
plt.plot(T60, C_V60)
plt.plot(T80, C_V80)
# plt.plot(T100, C_V100)
plt.legend(['L=40', 'L=60', 'L=80', 'L=100'])
plt.xlabel('Temperature')
plt.ylabel('$C_{V}$')
plt.figure('Susceptibility')
plt.plot(T40, chi40)
plt.plot(T60, chi60)
plt.plot(T80, chi80)
# plt.plot(T100, chi100)
plt.legend(['L=40', 'L=60', 'L=80', 'L=100'])
plt.xlabel('Temperature')
plt.ylabel('chi')

plt.show()
