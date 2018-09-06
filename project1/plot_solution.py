import matplotlib.pyplot as plt
import numpy as np

file = open("sol_array.txt", "r")

x_list = []
num_list = []
analyical_list = []

for line in file:
    col = line.split()
    x_list.append(col[0])
    num_list.append(float(col[1]))
    analyical_list.append(float(col[2]))

x = np.array(x_list)
num_array = np.array(num_list)
analyical_array = np.array(analyical_list)

plt.plot(x, num_array, x,  analyical_array)
plt.legend(["Numerical", "Analyical"])
plt.show()
