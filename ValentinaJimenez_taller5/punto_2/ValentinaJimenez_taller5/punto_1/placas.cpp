#include "iostream"
#include "fstream"


using namespace std;

int main()
{

// declarar constantes

	int** placas= new int *[512];

	for (int i=0; i<512; i++){

		placas[i]=new int[512];
	}


	double** V_inicial= new double *[512];

	for (int i=0; i<512; i++){

		V_inicial[i]=new double[512];
	}


	double** V_final= new double *[512];

	for (int i=0; i<512; i++){

		V_final[i]=new double[512];
	}

	double L = 5.0;
	float d = 1.0;
	float l = 2.0;
	double h = 0.009765625;
	int n=511;

// inicializar las matrices

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			placas[i][j] = 0; 
		}
	}

// condiciones iniciales

	for (int i = 0; i < n; ++i)
	{

		placas[0][i] = 2;
		placas[n-1][0] = 2;
		placas[i][0] = 2; 
		placas[i][n-1] = 2; 
 
	}

	

	int j0 = n*((0.5)-l/(2*L));
	int Dj = n*(l/L);

	int i0 = n*((0.5)-d/(2*L));
	int Di = n*(d/L);

	for (int j = j0; j < j0+Dj; ++j)
	{
		placas[i0][j] = 1;
		placas[i0+Di][j] = -1;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(placas[i][j]==0 | placas[i][j]==2)
			{ 
				V_inicial[i][j] = 0.0;
			}
			else if (placas[i][j]==1)
			{
				V_inicial[i][j] = 50.0;
			}
			else if (placas[i][j]==-1)
			{
				V_inicial[i][j] = -50.0;
			}

			V_final[i][j] = V_inicial[i][j];
		}
	}

// actualiza y suavizado

	int u= int(0.01*2*n*n);

	for (int k = 0; k < u; ++k)
	{
		for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(placas[i][j]==0)
			{ 
				V_final[i][j] = V_inicial[i][j+1] + V_inicial[i][j-1] + V_inicial[i+1][j] + V_inicial[i-1][j];
				V_final[i][j] = V_final[i][j]/4.0;
			}
		}

	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			V_inicial[i][j] = V_final[i][j];
		}

	}
	}

// inicializa campo electrico

	double campo_E[511][511][2];


// imprimir los datos 

	ofstream datos("datos.txt"); // para enviar los datos a un archivo .txt
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			datos << V_inicial[i][j] << ",";

			if (placas[i][j]!=2)
			{ 
				campo_E[i][j][0] = -( V_final[i][j]-V_final[i][j-1] )/h;
				campo_E[i][j][1] = -( V_final[i][j]-V_final[i-1][j] )/h;
			}else
			{
				campo_E[i][j][0] = 0.0;
				campo_E[i][j][1] = 0.0;
			}	
		}
		datos << endl;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			datos << campo_E[i][j][0] << ",";
		}
		datos << endl;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			datos << campo_E[i][j][1] << ",";
		}
		datos << endl;
	}

	return 0;
}




