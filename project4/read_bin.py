import numpy as np
import matplotlib.pyplot as plt


file = "energy.dat"
array = np.fromfile(file, dtype="int32", count=-1)


mcs = np.linspace(0, len(array), len(array))

plt.hist(array[100:], 50)
plt.figure()
plt.plot(mcs, array)
plt.xlabel('Monte Carlo cycles')
plt.ylabel('<E>')
plt.show()
