import matplotlib.pyplot as plt
import numpy as np

file = open("eigenvectors.txt", "r")

rho = []
eigenvalues = []


for line in file:
    col = line.split()
    rho.append(col[0])
    eigenvalues.append(float(col[1]))

rho_array = np.array(rho)
eigenvalues_array = np.array(eigenvalues)


plt.plot(rho_array, eigenvalues_array, "-o")
plt.grid("on")
plt.legend(["eigenvalues"])
plt.xlabel("rho")
plt.ylabel("lambda")
plt.show()
