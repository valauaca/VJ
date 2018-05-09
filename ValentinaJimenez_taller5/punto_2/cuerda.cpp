#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <stdio.h>

using namespace std;

double p=10.0;
double t=40.0;
double l=100.0;
double ymax=1.0;
double ymin=0.0;
double dx=0.01;
double x=0.0;
double a= sqrt(t/p);
double dt=0.01;
int n=(1.0/dx) + 1.0;
double w = (a*a*dt*dt)/(dx*dx);


// funciones

void llenar ( double *m);
void avance (double *m, double *M, double *Mnuevo);
void actualizar (double*m, double*M, double *Mnuevo);
void imprime (double*m);

// inicializar

void llenas(double*m){
	
	for (int i=0; i<n; i++){

		if (x<0.8*l){
			m[i]=(1.25*x)/l;
		}
		else{
			m[i]=5.0-(5.0*x/l);
		}
		x= i*dx;

	}

}

void avance (double *m, double *M, double *Mnuevo){

	for(int i=1; i<n; i++){
		Mnuevo[i]=w*(M[i+1]+m[i-1])-2.0*(M[i])*(w-1.0)-m[i];
	}

}

void actualizar (double*m, double*M, double *Mnuevo){
	
	for (int i =0; i<n; i++){

		m[i]=M[i];
		M[i]=Mnuevo[i];
	}


}

void imprime (double*m){

	for (int i=0; i<n; i++){
		cout << i*dx << " "<< m[i] << endl;
	}

}



int main(){

	double *m1, *m2, *m3;

	m1 = new double[n];
	m2 = new double[n];
	m3 = new double[n];

	llenas(m1);
	llenas(m2);

	for (int i=0; i<n; i++){


		m1[0]=0;
		m2[0]=0;

		m1[n-1]=0;
		m2[n-1]=0;

		avance(m1, m2, m3);
		actualizar(m1, m2, m3);
		imprime(m2);

	}




	return 0;
}




