#include <iostream>
#include <math.h>

using namespace std;


// declarar conste


double L= 5.0;
double l= 2.0;
double d=1.0;
double h=5.0/512.0;
int tam= L/h;
int N= 2*tam*tam;
double v0=100.0;


// funciones

void V( int tam, double **MV, double d, double h, double l, double L, double v0, double k, double **MV0);
void actualiza( int tam, double **MV, double **MV0);


void inicializarE(int tam, double **MEx, double **MEy);
void campo(double **MEx, double **MEy, double **MV, double tam, double h);


// inicializa funciones

void V( int tam, double **MV, double d, double h, double l, double L, double v0, double k, double **MV0){

	double z=L-d;
	double x=L+d;
	double c= L-l;
	double s=c/(2*h);
	double f=(c+2*l)/2*h;
	int h0= z/(2*h);
	int hf= x/(2*h);

	
	for( int i =s; i<f; i++){

		for (int j= hf; j<f; j++){
			MV[i][j]=v0/2.0;


		}



	}

	for( int i =s; i<f; i++){

		for (int j= h0; j<f; j++){
			MV[i][j]=-1.0*v0/2.0;


		}



	}

	for (int i=1; i< (tam-1); i++){

		for (int j=1; j< (tam-1); j++){
			double g;
			double y;

			g=(MV0[i+1][j] + MV0[i][j+1] + MV[i-1][j]+ MV[i][j-1])/4.0;
			y= g- MV0[i][j];

			MV[i][j]=MV0[i][j] +k*y;

		}

	}
}

	

void inicializarE(int tam, double **MEx, double **MEy){

	for (int i =0; i<(tam-2.0); i++){

		for (int j=0; j< (tam-2.0); j++){
			MEx[i][j]=0;
			MEy[i][j]=0;
		}
	}
}


void actualiza( int tam, double **MV, double **MV0){


	
	// actualiza 

	for (int i=0; i<tam; i++){
		for (int j=0; j< tam; j++){
			MV0[i][j]=MV[i][j];
		} 
	}


}


void campo(double **MEx, double **MEy, double **MV, int tam, double h){

	double r= 2*h;
	for (int i=1; i< (tam-2.0); i++){

		for (int j=0; j< (tam-2.0); j++){

			MEx[i][j]=(MV[i-1][j]-MV[i+1][j])/r;
			MEy[i][j]=(MV[i][j+1]-MV[i][j-1])/r;

			cout << MV[i][j] <<" "<< MEy[i][j] << " " << MEx[i][j]<< endl; 
		}
	}


}


int main(){



	//POR QUEEE
	double k=1.1;

	double **MV;
	double **MV0;
	double **MEx;
	double **MEy;

	MV=new double *[tam];
	MV0= new double *[tam];

	MEx=new double*[tam-2];
	MEy=new double*[tam-2];

	// llenar matriz V y V0

	for (int i=0; i< tam; i++){

		MV[i]=new double[tam];
		MV0[i]= new double[tam];
	}

	//lenar matriz Ex y Ey

	for (int i=0; i< (tam-2);i++){

		MEx[i]= new double[tam-2];
		MEy[i]= new double[tam-2];
	}
	

	inicializarE(tam, MEx, MEy);
	for (int i=0; i< 100; i++){
	
		V(tam, MV, d, h, l, L, v0, k, MV0);
		actualiza(tam, MV, MV0);

	}

	campo (MEx, MEy, MV, tam, h);

	return 0;

}


