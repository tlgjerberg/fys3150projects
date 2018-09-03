import numpy as np
import matplotlib.pyplot as plt

n = 100

h = 1./n

x = np.linspace(0, 1, n+1)

def f_func(x):
    f = 100.0*np.exp(-10*x)
    return f


f = f_func(x)
f_hat = f*h**2

b = np.ones(n)*(2)
a = c = np.ones(n)*(-1)

b_tilde = np.zeros(n+1)
f_tilde = np.zeros(n+1)

b_tilde[0] = b_tilde[n] = 2

for i in range(0, n):
    b_tilde[i] = b[i] - float((a[i-1]*c[i-1])/b_tilde[i-1])
    f_tilde[i] = f_hat[i] - float((a[i-1]*f_tilde[i-1])/b_tilde[i-1])

v = np.zeros(n+1)

v[0] = v[n] = 0

for j in range(n-1, 0, -1):
    v[j] = (f_tilde[j] - c[j]*v[j+1])/b_tilde[j]

def closed_form(x):
    return 1 - (1 - np.exp(-10))*x - np.exp(-10*x)

#
#
plt.plot(x, closed_form(x), x, v)
plt.legend(["Analyical", "Numerical"])
plt.show()
