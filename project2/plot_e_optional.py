import matplotlib.pyplot as plt
import numpy as np


for i in ["eigenvectors_e_opt_0_05.txt", "eigenvectors_e_opt_0_5.txt", "eigenvectors_e_opt_1.txt", "eigenvectors_e_opt_5.txt", "eigenvectors_d.txt"]:
    rho = []
    eigenvec = []
    with open(i, "r") as file:
        for line in file:
            col = line.split()
            rho.append(float(col[0]))
            eigenvec.append(float(col[1]))

    rho_array = np.array(rho)
    eigenvec_array = np.array(eigenvec)

    plt.style.use('ggplot')
    fig, ax = plt.subplots()
    ax.plot(rho_array, eigenvec_array, label='$\\omega_r = $')

    plt.legend(loc='best')
    ax.set_title("Ground state of a harmonic oscillator potential")
    ax.set_xlabel("$\\rho$")
    ax.set_ylabel("u($\\rho$)")

plt.show()
