import numpy as np
import matplotlib.pyplot as plt

# with open("energy.dat", "rb") as binary_file:
#     # Read the whole file at once
#     data = binary_file.read()
#     # print(data)

file = "energy.dat"
array = np.fromfile(file, dtype="int32", count=-1)


mcs = np.linspace(0, len(array), len(array))

plt.plot(mcs, array)
plt.show()
