#include <iostream>
#include <omp.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int  const nl=2;
	int  const nc=3;
	float A[nl][nc], B[nl][nc], C[nl][nc];
	
	for( int i=0; i<nl; i++){
		for (int j=0; j<nc; j++){
			A[i][j] = i+1 + j+1;
			B[i][j] = i+1 + j+1;
		}	
	}
	
	printf("\n\nA= \n");
	for (int i=0; i<nl; i++){
		for (int j=0; j<nc; i++){
			printf("%5d", A[i][j]);
		}
		printf("\n");
	}

	printf("\n\nB= \n");
	for (int i=0; i<nl; i++){
		for (int j=0; j<nc; i++){
			printf("%5d", B[i][j]);
		}
		printf("\n");
	}
	
	//Realizando a soma das matrizes Via Processamento Paralelo
	#pragma omp parallel //fork
	{
		#pragma omp for
		for(int i =0; i<nl; i++){
			for (int j=0; j<nc; i++){
				C[i][j]= A[i][j] + B[i][j];
			}
		}
		
	} //join
	
	// Imprimindo o resultado
	printf("\n\nC= \n");
	for (int i=0; i<nl; i++){
		for (int j=0; j<nc; i++){
			printf("\n%5d", i, i, C[i][j]);
		}
	}
	
	return 0;
}
