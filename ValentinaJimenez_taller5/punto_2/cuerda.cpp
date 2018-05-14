#include <iostream>
#include <math.h>
using namespace std;

// declarar constantes


double L = 100.0;
double t = 200.0;
double p = 10.0;
double c = sqrt(40.0/p);

void inicializa(double* cuerda, double dx, int n);
void evoluciona(double* cuerda1, double* cuerda_actual, double* cuerda0, int n, double dx, double dt, double c);
void imprime(double* cuerda, int n); 


int main(){

  double dx = 1.0;
  double dt = 0.1;

  int pasos_x = L/dx + 1;
  int pasos_t = t/dt +1;
  
// cuerda nueva
  double *cuerda1=new double[pasos_x];
//cuerda inicial
  double *cuerda0= new double[pasos_x];
//cuerda actual
  double *cuerda_actual= new double[pasos_x];

  inicializa(cuerda0,dx, pasos_x);
  inicializa(cuerda_actual,dx, pasos_x);

  //Frontera

  cuerda1[0] =0;
  cuerda1[pasos_x-1] =0;
  
  for(int i = 1; i<pasos_t;i++){
    if(i !=0 && i%30 ==0){
      imprime(cuerda0,pasos_x);
    }

    evoluciona(cuerda1, cuerda_actual, cuerda0, pasos_x, dx, dt, c);
  }
  return 0;
}
  



//funcion para inicializar valores y dar condiciones iniciales


void inicializa(double* cuerda, double dx, int n){

	for (int i=0; i<n; i++){
		double x =  i*dx;
       		if(x <= 0.8*L){
	 		cuerda[i] = 1.25*x/L;
       		}
      		else{
	  		cuerda[i] = 5.0-(5.0*x/L);
		}
		cout<<cuerda[i]<<" ";
    	}
 	 cout<<endl;
}

// funcion que marca los pasos de la cuerda


void evoluciona(double* cuerda1, double* cuerda_actual, double* cuerda0, int n, double dx, double dt, double c){
  double new_dx = dx *dx;
  double new_dt = dt * dt;
  double k = (new_dt/new_dx)*c*c;

  for (int i = 1; i<n-1; i++){
    cuerda1[i] = (k*(cuerda_actual[i+1]-2.0*cuerda_actual[i]+cuerda_actual[i-1])) + 2*cuerda_actual[i] - cuerda0[i];
  }  

for (int i = 0; i<n; i++){
    cuerda0[i] = cuerda_actual[i];
    cuerda_actual[i] = cuerda1[i];
  }
}


// funcion que imprime los valores de la cuerda actual 

void imprime(double* cuerda, int n){
  for (int i = 0; i<n;i++){
    cout<< cuerda[i]<<" ";
  }
  cout<<endl;
}

