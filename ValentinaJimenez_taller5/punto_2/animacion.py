

"""## solo pdf

d= np.loadtxt("cuerda.txt")
x=d[:,0]
y=d[:,1]
plt.plot(x,y, c="k")
plt.savefig("cuerda.png")"""


"""#cargar los datos para la grafica
import numpy as np
import matplotlib.pyplot as plt
import imageio"""

"""cuerda=np.genfromtxt("c.txt",delimiter=" ")

n=np.shape(cuerda)[0]-1"""

"""
nombres=[]
m=1
while m <=n:
    plt.figure(figsize=(12,8))
    plt.plot(cuerda[0,:],cuerda[m,:],c="k")
    plt.ylabel("p")
    plt.xlabel("tiempo")
    plt.xlim(-0.1, 100.1)
    plt.ylim(-1.1, 1.1)
    nombre=str(m)+".png"
    plt.savefig(nombre)
    nombres.append(nombre)
    m=m+1
"""
"""

lista = []
for nombre in nombres:
    lista.append(imageio.imread(nombre))
imageio.mimsave("cuerda.gif", lista, duration= 0.2)"""


from numpy import genfromtxt, size, shape
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.animation import FuncAnimation

U = genfromtxt('cue.txt', delimiter=' ')
frms,points = shape(U)

def one_frame(i):
	Ui = U[i,:]
	plt.cla()
	plt.plot(Ui, c='k')
	plt.ylim([-2.0,2.0])

fig = plt.figure()
anim = FuncAnimation(fig, one_frame, frames=int(frms/2), interval=10)
anim.save('cuerda.gif', writer='imagemagick', fps=int(frms/4))



