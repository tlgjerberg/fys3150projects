import matplotlib.pyplot as plt
import numpy as np
import matplotlib as mpl
from mpl_toolkits.mplot3d import Axes3D

planets = ["earth_pos.txt", "sun_pos.txt", "jupiter_pos.txt"]


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

    ax.plot(x, y, z, label='parametric curve')
    ax.legend()


plt.show()
