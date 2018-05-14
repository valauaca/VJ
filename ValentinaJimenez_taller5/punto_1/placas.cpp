#include <iostream>
#include <math.h>
#include "iostream"
#include "fstream"
#include "math.h"

using namespace std;


// declarar conste

int n=511;
double placas[511][511];
float v[511][511];
float v1[511][511];
float L= 5.0;
float h=5.0/512.0;




// inicializa funciones
void iniciar(){

	
	for( int i =0; i<n; i++){

		for (int j= 0; j<n; j++){
			placas[i][j]=0;


		}



	}

	// condici{on inicial
	for( int i =0; i<n; i++)
	{

		placas[i][0]=2;
		placas[i][n-1]=2;
		placas[0][i]=2;
		placas[n-1][0]=2;



	}

	float d=1.0;
	float r=2.0;
	int c= (r/L);
	int w= (d/L);
	int k=n*((0.5)-(0.5)*c);
	int f=n*c;
	int h0= n*((0.5)-(0.5)*w);
	int hf= n*(w);

	for (int i=k; i< k+f; i++){

		placas[h0][i]=1;
		placas[h0+hf][i]=-1;
		

	}

	for (int i=0; i<n; i++){

		for(int j=0; j<n; j++){

			if(placas[i][j]==0 | placas[i][j]==2){


				v[i][j]=0.0;
			}

			else if (placas[i][j]==1){

				v[i][j]=50.0;
			}
			else if(placas[i][j]==-1){

				v[i][j]=-50.0;
			}

			v1[i][j]=v[i][j];

		}


	}


}

void actualizar(){


	for (int i=0; i<n; i++){

		for(int j=0; j<n;j++){

			if(placas[i][j]==0){
				v1[i][j]=v[i][j+1]+v[i][j-1]+v[i+1][j]+v[i-1][j];
				v1[i][j]=v1[i][j]/4.0;
			}

		}
	}

	for(int i=0; i<n; i++){

		for (int j=0; j<n;i++){

			v[i][j]=v1[i][j];
		}
	}


}




	

void imprimir_datos(){

	double campo_E[511][511][2];

	ofstream datos_placas("datos_placas.txt");

	for (int i =0; i<n; i++){

		for (int j=0; j< n; j++){

			datos_placas << v[i][j] << ",";

			if(placas[i][j]!=2){


				campo_E[i][j][0]=(-1)*(v1[i][j]-v1[i][j-1])/h;
				campo_E[i][j][1]=(-1)*(v1[i][j]-v1[i-1][j])/h;

			}
			else{
				campo_E[i][j][0]=0.0;
				campo_E[i][j][1]=0.0;

			}

				
		}
		datos_placas<< endl;
	}

	for(int i=0; i<n; i++){

		for(int j=0; j<n; j++){

			datos_placas << campo_E[i][j][0] << ",";
		}
		datos_placas << endl;

	}

	for (int i=0; i < n; i++){

		for (int j=0; j<n; j++){

			datos_placas << campo_E[i][j][1] << ",";
		}
		datos_placas << endl;
	}


	
}



int main(){



	iniciar();

	int nt= int(0.01*2*n*n); 


	for (int i=0; i< nt; i++){

		actualizar();
	}

	

	imprimir_datos();

	return 0;

}


