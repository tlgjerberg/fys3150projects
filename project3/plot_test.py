import matplotlib.pyplot as plt
import numpy as np
import matplotlib as mpl
from mpl_toolkits.mplot3d import Axes3D
import os

planets = ["0.txt", "1.txt", "2.txt", "3.txt", "4.txt", "5.txt"]


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
    os.remove(i)
    ax.plot(x, y, z, label='parametric curve')
    ax.legend()


plt.show()
