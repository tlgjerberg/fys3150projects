import matplotlib.pyplot as plt
import numpy as np


plt.style.use('ggplot')
fig, ax = plt.subplots()
files = ["eigenvectors_e_opt_0_05.txt", "eigenvectors_e_opt_0_5.txt",
         "eigenvectors_e_opt_1.txt", "eigenvectors_d.txt"]
for i in files:
    rho = []
    eigenvec = []
    with open(i, "r") as file:
        for line in file:
            col = line.split()
            rho.append(float(col[0]))
            eigenvec.append(float(col[1]))

    rho_array = np.array(rho)
    eigenvec_array = np.array(eigenvec)

    ax.plot(rho_array, eigenvec_array)

    # plt.hold('on')
plt.legend(["$\\omega_r = 0.05 $", "$\\omega_r = 0.5$",
            "$\\omega_r = 1$", "Non-interacting"], loc='best')
ax.set_title(
    "Ground state of electrons in a H.O. potential")
ax.set_xlabel("$\\rho$")
ax.set_ylabel("u($\\rho$)")
plt.show()
