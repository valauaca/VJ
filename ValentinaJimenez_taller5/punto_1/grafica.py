import numpy as np

import matplotlib.pyplot as plt


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
plt.savefig('placas.pdf')
