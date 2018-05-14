placas.pdf: datos.txt grafica.py

	python grafica.py

datos.txt: a.out

	./a.out > datos.txt

a.out: placas.cpp

	g++ placas.cpp
