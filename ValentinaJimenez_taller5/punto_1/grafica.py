import numpy as np
from numpy import *

import matplotlib.pyplot as plt

"""
#cargar los datos para la grafica

datos=np.loadtxt('placas.txt')


#para separar las columnas n, 

x1=datos[:,0]
x2=datos[:,1]
x3=datos[:,2]

# linspace para la grafica:

x= np.linspace(-512, 512, 1000)
y= np.linspace(-512, 512, 1000)
a,b= np.meshgrid(x,y)
c,v=np.meshgrid(x,y)

plt.streamplot(a,b,c,v)

plt.imshow(datos)
plt.savefig('placas.pdf')"""
from numpy import *
import matplotlib.pyplot as plt


#metodo tomado de : para usar contourf https://matplotlib.org/api/_as_gen/matplotlib.pyplot.contourf.html. Este metodo lo implemente en el laboratorio con ayuda del profesor desde la pagina anteriormente citada. 


datos = genfromtxt("datos.txt", delimiter=',')
X = ~any(isnan(datos),0)
datos = datos[:,X] 
v = int(size(datos,0)/3)
r=linspace(0,v,v)
h=linspace(0,v,v)
X,Y = meshgrid(r,h)


figura = plt.figure()
plt.contourf(X,Y,datos[:v,:], 40, cmap='ocean_r')
plt.colorbar()
plt.streamplot(X,Y,datos[v:2*v,:],datos[2*v:,:], 1.1, color="navy")

figura.savefig('placas.pdf')
