placas.pdf: placas.txt grafica.py

	python grafica.py

placas.txt: a.out

	./a.out > placas.txt

a.out: placas.cpp

	g++ placas.cpp
