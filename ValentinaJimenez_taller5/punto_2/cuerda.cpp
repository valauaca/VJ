#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>


using namespace std;


double avance(double cp, double cuerda1, double cuerda2, double cuerda3){

	double cuerda_actual;

	cuerda_actual=cuerda1+((0.5)*cp*(cuerda2+cuerda3-2.0*cuerda1));

	return cuerda_actual;


}
double actualiza ( double cp, double cuerda1, double cuerda2, double cuerda3, double cuerda4){

	double cuerda_actual;

	cuerda_actual=2.0*cuerda1-cuerda2+cp*(cuerda3+cuerda4-2.0*cuerda1);

	return cuerda_actual;

}

int main(){


	double L=100;
	int n=501; //OJO
	double p=10;
	double T=40;
	double t=200.0;
	double dx= L/(n);
	double c=sqrt(T/p);
	double dt= 0.0001*dx/c;
	double cuerda[n];
	double cuerda1[n];
	double cp= dt*dt*c*c;
	double x[n];
	double cuerdaA;

//condiciones iniciales

for (int i=0; i<n; i++){

		double a=i*dx;
		cout<< a <<" ";


}
cout<<"\n";

for(int i=0; i<n; i++){

		double a=(i*dx);
		if(a<=0.8*L){

			cuerda[i]=1.25*a/L;

		
		}
		else{
	
			cuerda[i]=5.0-(5.0*a/L);

		}
		cout<< cuerda[i] <<" ";

	}
cout<<"\n";



for (int j=0; j<(200/dt); j++){


	if(j==0){

		cuerda1[0]=0;
		cuerda1[n]=0;
		for(int i=1; i<n-1; i++){

			cuerda1[i]=cuerda[i]+((0.5)*cp*(cuerda[i+1]+cuerda[i-1]-2.0*cuerda[i]));


		}
	}
	else{


		for (int i=1; i< n-1; i++){

			double cuerda_actual=cuerda1[i];

			cuerda1[i]=2.0*cuerda1[i]-cuerda[i]+cp*(cuerda1[i+1]+cuerda1[i-1]-2.0*cuerda1[i]);

			cuerda[i]=cuerda_actual;
		}

		if(j%(int(200/dt)/50)==0){

			for (int i=0; i<n; i++){

				cout<< cuerda1[i] <<" ";
			}

		cout << "\n";

		}
	}

}




	return 0;
}
