import matplotlib.pyplot as plt
import numpy as np
import matplotlib as mpl
from mpl_toolkits.mplot3d import Axes3D
import os

# planets = ["0.txt", "1.txt", "2.txt", "3.txt",
# "4.txt", "5.txt", "6.txt", "7.txt", "8.txt", "9.txt"]

planets = ["0.txt", "1.txt", "2.txt", "3.txt"]
step = np.arange(-1, 1, step=0.5)
# params = {'legend.fontsize': 'large', 'axes.labelsize': 'large',
#           'axes.titlesize': 'large', 'xtick.labelsize': 'large',
#           'ytick.labelsize': 'large'}


# mpl.rcParams.update(params)
mpl.rcParams['xtick.labelsize'] = 15


fig = plt.figure()
ax = fig.gca(projection='3d')

for i in planets:
    x = []
    y = []
    z = []
    with open(i, "r") as file:
        # next(file)
        for line in file:
            col = line.split()
            x.append(float(col[0]))
            y.append(float(col[1]))
            z.append(float(col[2]))
    # os.remove(i)  # Include to delete files when plotting the Solar System
    ax.plot(x, y, z)
    ax.set_xlabel('x [AU]', size=15)
    ax.set_ylabel('y [AU]', size=15)
    ax.set_zlabel('z [AU]', size=15)
    # ax.set_xlim(-1, 1)
    # ax.set_ylim(-1, 1)
    # ax.set_zlim(-1, 1)
    # ax.set_xticks(step)
    # ax.set_yticks(step)
    # ax.set_zticks(step)

    # ax.set_xlim(-1, 1)
    # ax.set_ylim(-1, 1)
    # ax.set_zlim(-1, 1)
    # ax.set_xticks(step)
    # ax.set_yticks(step)
    # ax.set_zticks(step)
    ax.legend(['Sun', 'Mercury', 'Venus', 'Earth', 'Mars',
               'Jupiter', 'Saturn', 'Uranus', 'Neptune', 'Pluto'], fontsize=15)


plt.show()
