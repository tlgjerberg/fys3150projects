import numpy as np
import sys


# array = np.genfromtext("matrix.txt", "w+")

d = np.array((1, 4, 6, 3))
e = np.array((2, 4, 1))
b = np.array((5, 6, 7, 9))

def Gaussian_elim(n, d, e, b):

    d_new = np.zeros(n)
    b_new = np.zeros(n)


    d_new[0] = d[1]
    for i in range(1, n):
        d_new[i] = d[i] - float(e[i-1]/d[i-1])
        b_new[i] = b[i] - float(b[i-1]/d[i-1])

    return d_new, b_new



d_new = (Gaussian_elim(4, d, e, b)[0])
b_new = (Gaussian_elim(4, d, e, b)[1])

print(d_new, b_new)

u = b_new/d_new

print (u)

# def U(n, d_new, b_new):
#     u = np.zeros(n+1)
#
#     for i in range(n, 1, -1):
#         u[i] = float(b_new[i]/d_new[i])
#
#     return u



# print (U(4, d_new, b_new))
