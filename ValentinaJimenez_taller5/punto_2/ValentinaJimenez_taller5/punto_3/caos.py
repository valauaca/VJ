import numpy as np
import matplotlib.pyplot as plt


datos = np.loadtxt("caos.txt")

x=datos[:,0]
y=datos[:,1]

plt.plot(x,y,color='k', marker='D')
plt.title("q2 Vs p2")
plt.savefig('caos.pdf')
