#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>


using namespace std;



// declarar varibales
	

double a= 1.0/(2.0*sqrt(2.0));
double e= pow(10.0,-3);


// funciones

double dq1( double p1);

double dq2( double p2);

double dp1 (double q1);

double dp2( double q2, double q1);

void runge_kutta (double *q1n0, double *p1n0, double *q2n0, double *p2n0, double h);

//inicializar funcines

double dq1(double p1){

	return p1;

}

double dq2(double p2){

	return p2;

}

double dp1(double q1){

	double w;
	double z;

	w= (-2.0*q1);
	z= pow(4.0*q1*q1+e*e, 3.0/2.0);
	dp1dt= w/z;

	return dp1dt;
}


double dp2(double q2, double q1){

	double y;
	double u;
	double l;
	double k;
	double v;
	l = (q1-q2);
	k= (q1+q2);

	y = l/(pow((l*l)+e*e/4.0, 3.0/2.0));
	u= k/ (pow((k*k)+e*e/4.0, 3.0/2.0));
	dp2dt = y-u;
	

	return dp2dt;
}



void runge_kutta (double *q1n0, double *p1n0, double *q2n0, double *p2n0, double h){

	double q1n, p1n, q2n, p2n;

	q1n=*q1n0;
	p1n=*p1n0;
	q2n=*q2n0;
	p2n=*p2n0;

// para q
	double k1q1, k2q1, k3q1, k4q1;
// para q1
	double k1q2, k2q2, k3q2, k4q2;
// para p
	double k1p1, k2p1, k3p1, k4p1;
// para p1
	double k1p2, k2p2, k3p2, k4p2;


// constantes

	k1q1 = dq1 ( p1n );
	k1p1 = dp1 ( q1n );
	k1q2 = dq2 ( p2n );
	k1p2 = dp2 ( q2n, q1n );

	k2q1 = dq1 ( p1n + h/2.0 * k1q1 );
	k2p1 = dp1 ( q1n + h/2.0 * k1p1 );
	k2q2 = dq2 ( p2n + h/2.0 * k1q2 );
	k2p2 = dp2 ( q1n + h/2.0 * k1p1, q2n + h/2.0 * k1p2 );

	k3q1 = dq1 ( p1n + h/2.0 * k2q1 );
	k3p1 = dp1 ( q1n + h/2.0 * k2p1 );
	k3q2 = dq2 ( p2n + h/2.0 * k2q2 );
	k3p2 = dp2 ( q1n + h/2.0 * k2p1, q2n + h/2.0 *k2p2 );

	k4q1 = dq1 ( p1n +  k3q1 * h );
	k4p1 = dp1 ( q1n + k3p1 * h );
	k4q2 = dq2 ( p2n +  k3q2 * h );
	k4p2 = dp2 ( q1n + k3p1 * h, q2n + k3p1 * h );

// solucion de ecuaciones

	q1n = q1n + (h/6.0) * ( k1q1 + 2.0 * k2q1 + 2.0 * k3q1 + k4q1);
	p1n = p1n + (h/6.0) * ( k1p1 + 2.0 * k2p1 + 2.0 * k3p1 + k4p1);
	q2n = q2n + (h/6.0) * ( k1q2 + 2.0 * k2q2 + 2.0 * k3q2 + k4q2 );
	p2n = p2n + (h/6.0) * ( k1p2 + 2.0 * k2p2 + 2.0 * k3p2 + k4p2 );

	*q1n0=q1n;
	*p1n0=p1n;
	*q2n0=q2n;
	*p2n0=p2n;

}

	


int main (){

	double dt=0.006;
	double t= 3000.0;
	double n = t/dt;
	double a= 1.0/(2.0*sqrt(2.0));
	
	double q1=a;
	double q10=a;
	double q2=-a;
	double p1=0;
	double p2=0;


	for (int i=0; i<n; i++){

		cout << q2n << " " << p2n << endl;

		q1n=*q1n0;
		p1n=*p1n0;
		q2n=*q2n0;
		p2n=*p2n0;

	// para q
		double k1q1, k2q1, k3q1, k4q1;
	// para q1
		double k1q2, k2q2, k3q2, k4q2;
	// para p
		double k1p1, k2p1, k3p1, k4p1;
	// para p1
		double k1p2, k2p2, k3p2, k4p2;


	// constantes

		k1q1 = dq1 ( p1n );
		k1p1 = dp1 ( q1n );
		k1q2 = dq2 ( p2n );
		k1p2 = dp2 ( q2n, q1n );

		k2q1 = dq1 ( p1n + h/2.0 * k1q1 );
		k2p1 = dp1 ( q1n + h/2.0 * k1p1 );
		k2q2 = dq2 ( p2n + h/2.0 * k1q2 );
		k2p2 = dp2 ( q1n + h/2.0 * k1p1, q2n + h/2.0 * k1p2 );

		k3q1 = dq1 ( p1n + h/2.0 * k2q1 );
		k3p1 = dp1 ( q1n + h/2.0 * k2p1 );
		k3q2 = dq2 ( p2n + h/2.0 * k2q2 );
		k3p2 = dp2 ( q1n + h/2.0 * k2p1, q2n + h/2.0 *k2p2 );

		k4q1 = dq1 ( p1n +  k3q1 * h );
		k4p1 = dp1 ( q1n + k3p1 * h );
		k4q2 = dq2 ( p2n +  k3q2 * h );
		k4p2 = dp2 ( q1n + k3p1 * h, q2n + k3p1 * h );

	// solucion de ecuaciones

		q1n = q1n + (h/6.0) * ( k1q1 + 2.0 * k2q1 + 2.0 * k3q1 + k4q1);
		p1n = p1n + (h/6.0) * ( k1p1 + 2.0 * k2p1 + 2.0 * k3p1 + k4p1);
		q2n = q2n + (h/6.0) * ( k1q2 + 2.0 * k2q2 + 2.0 * k3q2 + k4q2 );
		p2n = p2n + (h/6.0) * ( k1p2 + 2.0 * k2p2 + 2.0 * k3p2 + k4p2 );

		*q1n0=q1n;
		*p1n0=p1n;
		*q2n0=q2n;
		*p2n0=p2n;

		runge_kutta (&q1n, &p1n, &q2n, &p2n, h);
	}
	return 0;


}



