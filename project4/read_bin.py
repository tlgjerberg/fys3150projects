import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl
import matplotlib.mlab as mlab

params = {'legend.fontsize': 'large', 'axes.labelsize': 'large',
          'axes.titlesize': 'large', 'xtick.labelsize': 'large',
          'ytick.labelsize': 'large'}
mpl.rcParams.update(params)

# T, E, M, C_V, chi = np.loadtxt(
#     "means.txt", usecols=(1, 3, 5, 7, 9), unpack=True)

# ===============================================================================
# Plots 4b)
# ===============================================================================


# ===============================================================================
# Plots 4c)
# ===============================================================================

# E_1_u = np.loadtxt("results/means1_u.txt", usecols=(3), unpack=True)
# E_24_u = np.loadtxt("results/means24_u.txt", usecols=(3), unpack=True)
# E_1_o = np.loadtxt("results/means1_o.txt", usecols=(3), unpack=True)
# E_24_o = np.loadtxt("results/means24_o.txt", usecols=(3), unpack=True)
# mcs_4c, Acc1_u = np.loadtxt("results/meta1_u.txt",
#                             usecols=(2, 5), unpack=True)
# Acc1_o = np.loadtxt("results/meta1_o.txt", usecols=(5), unpack=True)
# Acc24_u = np.loadtxt("results/meta24_u.txt", usecols=(5), unpack=True)
# Acc24_o = np.loadtxt("results/meta24_o.txt", usecols=(5), unpack=True)
#


# plt.figure()
# plt.plot(mcs, array)
# plt.xlabel('Monte Carlo cycles')
# plt.ylabel('E')
# plt.figure('Time development')
# plt.plot(mcs_4c, E_1_u, '-o')
# plt.plot(mcs_4c, E_24_u, '-o')
# plt.xlabel('Monte Carlo cycles')
# plt.ylabel('$\\langle E \\rangle$')
# plt.legend(['T = 1.0', 'T = 2.4'])
# plt.grid('on')
# plt.figure('Time development 2')
# plt.plot(mcs_4c, E_1_o, '-o')
# plt.plot(mcs_4c, E_24_o, '-o')
# plt.xlabel('Monte Carlo cycles')
# plt.ylabel('$\\langle E \\rangle$')
# plt.legend(['T = 1.0', 'T = 2.4'])
# plt.grid('on')
# plt.figure('Accepted T=1')
# plt.plot(mcs_4c, Acc1_u, '-o')
# plt.plot(mcs_4c, Acc1_o, '-o')
# plt.xlabel('Monte Carlo cycles')
# plt.ylabel('# accepted states')
# plt.legend(['Unordered', 'ordered'])
# plt.grid('on')
# plt.figure('Accepted T=2.4')
# plt.plot(mcs_4c, Acc24_u, '-o')
# plt.plot(mcs_4c, Acc24_o, '-o')
# plt.xlabel('Monte Carlo cycles')
# plt.ylabel('# accepted states')
# plt.legend(['Unordered', 'ordered'])
# plt.grid('on')


# ===============================================================================
# Plots 4d)
# ===============================================================================

# plt.hist(arr, normed=True)
# plt.xlim((min(arr), max(arr)))


file1 = "energy20_1_u.dat"
file2 = "energy20_1_o.dat"
file3 = "energy20_24_u.dat"
file4 = "energy20_24_o.dat"
array1 = np.fromfile(file1, dtype="int32", count=-1)
array2 = np.fromfile(file2, dtype="int32", count=-1)
array3 = np.fromfile(file3, dtype="int32", count=-1)
array4 = np.fromfile(file4, dtype="int32", count=-1)

mean3 = np.mean(array3)
variance3 = np.var(array3)
sigma3 = np.sqrt(variance3)
x3 = np.linspace(min(array3), max(array3), 100)

mean4 = np.mean(array4)
variance4 = np.var(array4)
sigma4 = np.sqrt(variance4)
x4 = np.linspace(min(array4), max(array4), 100)

mcs = np.linspace(0, len(array1), len(array1))

plt.figure('Probability1')
plt.hist(array1, bins=48)
plt.xlabel('Monte Carlo cycles')
plt.figure('Probability2')
plt.hist(array2, bins=48)
plt.xlabel('Monte Carlo cycles')
plt.figure('Probability3')
plt.hist(array3, bins=180)
plt.xlabel('Monte Carlo cycles')
plt.figure('Probability4')
plt.hist(array4, bins=180)
plt.xlabel('Monte Carlo cycles')
plt.figure('Probability3_normed')
plt.hist(array3, bins=180, normed=True)
plt.plot(x3, mlab.normpdf(x3, mean3, sigma3))
plt.xlabel('Monte Carlo cycles')
plt.figure('Probability4_normed')
plt.hist(array4, bins=180, normed=True)
plt.plot(x4, mlab.normpdf(x4, mean4, sigma4))
plt.xlabel('Monte Carlo cycles')

# ===============================================================================
# Plots 4e)
# ===============================================================================
# plt.figure("Testplot")
# plt.plot(T, C_V)

# T40, E40, M40, C_V40, chi40 = np.loadtxt(
#     "results/means40_2_2_2_4.txt", usecols=(1, 3, 5, 7, 9), unpack=True)
# T60, E60, M60, C_V60, chi60 = np.loadtxt(
#     "results/means60_2_2_2_4.txt", usecols=(1, 3, 5, 7, 9), unpack=True)
# T80, E80, M80, C_V80, chi80 = np.loadtxt(
#     "results/means80_2_2_2_4.txt", usecols=(1, 3, 5, 7, 9), unpack=True)
# T100, E100, M100, C_V100, chi100 = np.loadtxt(
#     "results/means100_2_2_2_4.txt", usecols=(1, 3, 5, 7, 9), unpack=True)
#
#
# plt.figure('Mean energy')
# plt.plot(T40, E40)
# plt.plot(T60, E60)
# plt.plot(T80, E80)
# plt.plot(T100, E100)
# plt.legend(['L=40', 'L=60', 'L=80', 'L=100'])
# plt.xlabel('Temperature')
# plt.ylabel('<E>')
# plt.figure('Mean magnetisation')
# plt.plot(T40, M40)
# plt.plot(T60, M60)
# plt.plot(T80, M80)
# plt.plot(T100, M100)
# plt.legend(['L=40', 'L=60', 'L=80', 'L=100'])
# plt.xlabel('Temperature')
# plt.ylabel('<|M|>')
# plt.figure('Heat capacity')
# plt.plot(T40, C_V40)
# plt.plot(T60, C_V60)
# plt.plot(T80, C_V80)
# plt.plot(T100, C_V100)
# plt.legend(['L=40', 'L=60', 'L=80', 'L=100'])
# plt.xlabel('Temperature')
# plt.ylabel('$C_{V}$')
# plt.figure('Susceptibility')
# plt.plot(T40, chi40)
# plt.plot(T60, chi60)
# plt.plot(T80, chi80)
# plt.plot(T100, chi100)
# plt.legend(['L=40', 'L=60', 'L=80', 'L=100'])
# plt.xlabel('Temperature')
# plt.ylabel('$\\langle\\chi\\rangle$')

plt.show()
