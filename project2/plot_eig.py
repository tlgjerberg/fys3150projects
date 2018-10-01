import matplotlib.pyplot as plt
import numpy as np

"""Script for plotting eigenvalues as a function of omega_r and logarithmic
    plot of iterations as a function of n"""

rho = []
eigenvec = []

n = [10, 20, 50, 100, 200, 300]
iter = [138, 663, 4319, 17664, 70859, 160084]

with open("eigenvectors_e.txt", "r") as file:
    # next(file)
    for line in file:
        col = line.split()
        rho.append(float(col[0]))
        eigenvec.append(float(col[1]))

rho_array = np.array(rho)
eigenvec_array = np.array(eigenvec)

plt.style.use('ggplot')
fig, ax = plt.subplots()

ax.plot(rho_array, eigenvec_array, label='Ground state')
plt.legend(loc='best')
# ax.set_title("Energy ground states for different $\\omega_r$")
# ax.set_xlabel("$\\omega_r$")
# ax.set_ylabel("E($\\omega_r$)")
ax.set_title("Ground state of a harmonic oscillator potential")
ax.set_xlabel("$\\rho$")
ax.set_ylabel("u($\\rho$)")

plt.style.use('ggplot')

fig, ax = plt.subplots()
ax.plot(np.log(n), np.log(iter))
ax.set_title("Logarithmic plot of iterations against dimension n")
ax.set_xlabel("log(n)")
ax.set_ylabel("log(iterations)")
plt.show()
