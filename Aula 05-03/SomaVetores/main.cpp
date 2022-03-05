#include <iostream>
#include <math.h>
#include <omp.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int const n = 10;
	float A[n], B[n], C[n];
	
	// Alimentar os vetores A e B com valores quaisquer
	for(int i=0; i<n; i++)
	{
		A[i] = i * sin(i);
		B[i] = A[i] - cos(i*i);
	}
	
	// Realizando a soma dos vetores
	/*for(int i=0; i<n; i++){
		C[i] = A[i] + B[i];
	}*/
	
	// Realizando a soma dos vetores em paralela utilizando OpenMP
	#pragma op parallel
	{
		int id = omp_get_thread_num();
		int nt = omp_get_num_threads();
		
		int tamanho = n / nt;
		
		int inicio = id * tamanho;
		int fim = inicio + tamanho - 1;
		
		for(int i=inicio; i<=fim; i++)
		{
			C[i] = A[i] + B[i];
		}
	}//join
	
	// Imprimindo o resultado
	for (int i=0; i<n; i++)
	{
		printf("\nA [%d] + B[%d] = %10.3f", i, i, C[i]);
	}

	return 0;
}
