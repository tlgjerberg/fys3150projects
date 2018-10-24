import matplotlib.pyplot as plt
import numpy as np
import matplotlib as mpl
from mpl_toolkits.mplot3d import Axes3D
import os

planets = ["0.txt", "1.txt", "2.txt", "3.txt",
           "4.txt", "5.txt", "6.txt", "7.txt", "8.txt", "9.txt"]


mpl.rcParams['legend.fontsize'] = 10

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
    ax.set_xlabel('x [AU]')
    ax.set_ylabel('y [AU]')
    ax.set_zlabel('z [AU]')
    ax.legend(['Sun', 'Mercury', 'Venus', 'Earth', 'Mars',
               'Jupiter', 'Saturn', 'Uranus', 'Neptune', 'Pluto'])


plt.show()
