import numpy as np
import imageio
import os
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib.animation import FuncAnimation

## solo pdf

d= np.loadtxt("cuerda.txt")
x=d[:,0]
y=d[:,1]
plt.plot(x,y, c="k")
plt.savefig("cuerda.png")


#cargar los datos para la grafica

datos=np.genfromtxt('cuerda.txt', delimiter=" ")



n= np.shape(datos)[0]-1


arra=[]

for i in range(1,n):

	plt.figure(figsize=(18,9))
	plt.plot(datos[0,:],datos[i,:], c="b")
	plt.xlabel('x')
	plt.ylabel('a')
	plt.ylim(-1.1,1.1)
	plt.xlim(-0.1,100.1)
	nom= str(i) +'.png'
	plt.savefig(nom)



	arra.append(nom)
lista=[]
for i in arra:

	lista.append(imageio.imread(i))



imageio.mimsave('cuerda.gif', lista, duration=0.1)



