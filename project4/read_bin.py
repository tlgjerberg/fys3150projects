import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl
import matplotlib.mlab as mlab
import scipy.stats as stats

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

E_1_u, M_1_u = np.loadtxt("results/means_L20_T1_u.txt",
                          usecols=(3, 5), unpack=True)
E_24_u, M_24_u = np.loadtxt("results/means_L20_T24_u.txt",
                            usecols=(3, 5), unpack=True)
E_1_o, M_1_o = np.loadtxt("results/means_L20_T1_o.txt",
                          usecols=(3, 5), unpack=True)
E_24_o, M_24_o = np.loadtxt("results/means_L20_T24_o.txt",
                            usecols=(3, 5), unpack=True)
mcs_4c, Acc1_u = np.loadtxt("results/meta_L20_T1_u.txt",
                            usecols=(2, 5), unpack=True)
Acc1_o = np.loadtxt("results/meta_L20_T1_o.txt", usecols=(5), unpack=True)
Acc24_u = np.loadtxt("results/meta_L20_T24_u.txt", usecols=(5), unpack=True)
Acc24_o = np.loadtxt("results/meta_L20_T24_o.txt", usecols=(5), unpack=True)

file_E1 = "energy_L20_T1_u.dat"
file_M1 = "magmom_L20_T1_u.dat"
file_E2 = "energy_L20_T24_u.dat"
file_M2 = "magmom_L20_T24_u.dat"

E1 = np.fromfile(file_E1, dtype="int32", count=-1)
E2 = np.fromfile(file_E2, dtype="int32", count=-1)
M1 = np.fromfile(file_M1, dtype="int32", count=-1)
M2 = np.fromfile(file_M2, dtype="int32", count=-1)

mcs = np.linspace(0, len(E1), len(E1))

plt.figure('Energy')
plt.plot(mcs, E1)
plt.plot(mcs, E2)
plt.xlabel('Monte Carlo cycles')
plt.ylabel('Energy')
plt.legend(["T = 1.0", "T = 2.4"])


plt.figure('magnetisation')
plt.plot(mcs, M1)
plt.plot(mcs, M2)
plt.xlabel('Monte Carlo cycles')
plt.ylabel('Magnetisation')
plt.legend(["T = 1.0", "T = 2.4"])


plt.figure('Time development')
plt.plot(mcs_4c, E_1_u, '-o')
plt.plot(mcs_4c, E_24_u, '-o')
plt.xlabel('Monte Carlo cycles')
plt.ylabel('$\\langle E \\rangle$')
plt.legend(['T = 1.0', 'T = 2.4'])
plt.grid('on')
plt.figure('Time development 2')
plt.plot(mcs_4c, E_1_o, '-o')
plt.plot(mcs_4c, E_24_o, '-o')
plt.xlabel('Monte Carlo cycles')
plt.ylabel('$\\langle E \\rangle$')
plt.legend(['T = 1.0', 'T = 2.4'])
plt.grid('on')
plt.figure('accept unordered')
plt.semilogy(mcs_4c, Acc1_u, '-o')
plt.semilogy(mcs_4c, Acc24_u, '-o')
plt.xlabel('Monte Carlo cycles')
plt.ylabel('# accepted states')
plt.legend(['T = 1.0', 'T = 2.4'])
plt.grid('on')
plt.figure('Accecpt ordered')
plt.semilogy(mcs_4c, Acc1_o, '-o')
plt.semilogy(mcs_4c, Acc24_o, '-o')
plt.xlabel('Monte Carlo cycles')
plt.ylabel('# accepted states')
plt.legend(['T = 1.0', 'T = 2.4'])
plt.grid('on')
plt.grid('on')
plt.figure('Time mag u')
plt.plot(mcs_4c, M_1_u, '-o')
plt.plot(mcs_4c, M_24_u, '-o')
plt.xlabel('Monte Carlo cycles')
plt.ylabel('$\\langle M \\rangle$')
plt.legend(['T = 1.0', 'T = 2.4'])
plt.grid('on')
plt.figure('Time mag o')
plt.plot(mcs_4c, M_1_o, '-o')
plt.plot(mcs_4c, M_24_o, '-o')
plt.xlabel('Monte Carlo cycles')
plt.ylabel('$\\langle M \\rangle$')
plt.legend(['T = 1.0', 'T = 2.4'])
plt.grid('on')


# ===============================================================================
# Plots 4d)
# ===============================================================================


file1 = "energy_L20_T1_u.dat"
file2 = "energy_L20_T1_o.dat"
file3 = "energy_L20_T24_u.dat"
file4 = "energy_L20_T24_o.dat"
array1 = np.fromfile(file1, dtype="int32", count=-1)
array2 = np.fromfile(file2, dtype="int32", count=-1)
array3 = np.fromfile(file3, dtype="int32", count=-1)
array4 = np.fromfile(file4, dtype="int32", count=-1)


weights1 = np.ones_like(array1) / float(len(array1))
weights2 = np.ones_like(array2) / float(len(array2))
weights3 = np.ones_like(array3) / float(len(array3))
weights4 = np.ones_like(array4) / float(len(array4))


plt.figure('Probability1')
plt.hist(array1, bins=180)
plt.xlabel('Monte Carlo cycles')
plt.figure('Probability1_normed')
plt.hist(array1, bins=180, weights=weights1)
plt.xlabel('Monte Carlo cycles')
plt.figure('Probability2')
plt.hist(array2, bins=180)
plt.xlabel('Monte Carlo cycles')
plt.figure('Probability2_normed')
plt.hist(array2, bins=180, weights=weights2)
plt.figure('Probability3')
plt.hist(array3, bins=183)
plt.xlabel('Monte Carlo cycles')
plt.figure('Probability4')
plt.hist(array4, bins=186)
plt.xlabel('Monte Carlo cycles')
plt.figure('Probability3_normed')
plt.hist(array3, bins=183, weights=weights3)
plt.xlabel('Monte Carlo cycles')
plt.figure('Probability4_normed')
plt.hist(array4, bins=186, weights=weights4)
plt.xlabel('Monte Carlo cycles')

# ===============================================================================
# Plots 4e)
# ===============================================================================

T40, E40, M40, C_V40, chi40 = np.loadtxt(
    "results/means_L40_T2_23_u.txt", usecols=(1, 3, 5, 7, 9), unpack=True)
T60, E60, M60, C_V60, chi60 = np.loadtxt(
    "results/means_L60_T2_23_u.txt", usecols=(1, 3, 5, 7, 9), unpack=True)
T80, E80, M80, C_V80, chi80 = np.loadtxt(
    "results/means_L80_T2_23_u.txt", usecols=(1, 3, 5, 7, 9), unpack=True)
T100, E100, M100, C_V100, chi100 = np.loadtxt(
    "results/means_L100_T2_23_u.txt", usecols=(1, 3, 5, 7, 9), unpack=True)
T140, E140, M140, C_V140, chi140 = np.loadtxt(
    "results/means_L140_T22_24_o.txt", usecols=(1, 3, 5, 7, 9), unpack=True)
T160, E160, M160, C_V160, chi160 = np.loadtxt(
    "results/means_L160_T22_24_o.txt", usecols=(1, 3, 5, 7, 9), unpack=True)

plt.figure('Mean energy')
plt.plot(T40, E40)
plt.plot(T60, E60)
plt.plot(T80, E80)
plt.plot(T100, E100)
plt.plot(T140, E140)
plt.plot(T160, E160)
plt.legend(['L=40', 'L=60', 'L=80', 'L=100', 'L=140', 'L=160'])
plt.xlabel('Temperature')
plt.ylabel('<E>')
plt.grid('on')
plt.figure('Mean magnetisation')
plt.plot(T40, M40)
plt.plot(T60, M60)
plt.plot(T80, M80)
plt.plot(T100, M100)
plt.plot(T140, M140)
plt.plot(T160, M160)
plt.grid('on')
plt.legend(['L=40', 'L=60', 'L=80', 'L=100', 'L=140', 'L=160'])
plt.xlabel('Temperature')
plt.ylabel('<|M|>')
plt.figure('Heat capacity')
plt.plot(T40, C_V40)
plt.plot(T60, C_V60)
plt.plot(T80, C_V80)
plt.plot(T100, C_V100)
plt.plot(T140, C_V140)
plt.plot(T160, C_V160)
plt.grid('on')
plt.legend(['L=40', 'L=60', 'L=80', 'L=100', 'L=140', 'L=160'])
plt.xlabel('Temperature')
plt.ylabel('$C_{V}$')
plt.figure('Susceptibility')
plt.plot(T40, chi40)
plt.plot(T60, chi60)
plt.plot(T80, chi80)
plt.plot(T100, chi100)
plt.plot(T140, chi140)
plt.plot(T160, chi160)
plt.grid('on')
plt.legend(['L=40', 'L=60', 'L=80', 'L=100', 'L=140', 'L=160'])
plt.xlabel('Temperature')
plt.ylabel('$\\langle\\chi\\rangle$')

plt.show()
