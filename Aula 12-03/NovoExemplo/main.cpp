#include <iostream>
#include <omp.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int const nl=2;
	int const nc=3;
	int A[nl][nc], B[nl][nc], C[nl][nc];
	
	for (int i=0;i<nl;i++){
		for (int j=0;j<nc;j++){
			A[i][j] = i+1 + j+1;
			B[i][j] = i+1 + j+1;
		}
	}
	printf("\n\nA = \n");
	
	for (int i=0;i<nl;i++){
		for(int j=0;j<nc;j++)
		{
			printf("%5d", A[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\nB = \n");
	
	for(int i=0;i<nl;i++){
		for(int j=0; j<nc; j++){
			printf("%5d", B[i][j]);
		}
		printf("\n");
		
	}

	
	#pragma omp parallel
	{
		#pragma omp for
		for(int i=0; i<nl; i++)
		{
			for(int j=0;j<nc;j++)
			{
				C[i][j] = A[i][j] + B[i][j];
			}
		}
	}

	
	printf("\n\nC = \n");
	
	for (int i=0;i<nl;i++){
		for (int j=0;j<nc;j++){
			printf("%5d", C[i][j]);
		}
		printf("\n");
	}
	
	return 0;

}

