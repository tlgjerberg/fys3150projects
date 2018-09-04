import matplotlib.pyplot as plt
import numpy as np

file = open("sol_array.txt", "r")

num_list = []
analyical_list = []

for line in file:
    col = line.split()
    num_list.append(float(col[0]))
    analyical_list.append(float(col[1]))

num_array = np.array(num_list)
analyical_array = np.array(analyical_list)


n = len(num_array)

x = np.linspace(0, 1, n)

plt.plot(x, num_array, x, analyical_array)
plt.legend(["Numerical", "Analyical"])
plt.show()
