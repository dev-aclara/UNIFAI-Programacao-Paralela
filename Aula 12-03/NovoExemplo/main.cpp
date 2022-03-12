#include <iostream>
#include <math.h>
#include <omp.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int tamanho, inicio, fim;
	int const n = 10;
	int ID[n];
	float A[n], B[n], C[n];
	
	// Alimentar os vetores A e B com valores quaisquer
	for(int i=0; i<n; i++)
	{
		A[i] = i + 1;
		B[i] = i + 1;
		ID[i] = -1;
	}
	
	printf("\nTotal de Threads disponiveis: %d" , omp_get_max_threads());
	
	printf("\n\nSoma de Vetores:\n\n");
	
	#pragma omp parallel
	{
		int i;
		#pragma omp for
		for (i = 0; i < n; i++){
			C[i] = A[i] + B[i];
			ID[i] = omp_get_thread_num();
		}
	}
	
	#pragma omp parallel //fotrk
	{
		int id = omp_get_thread_num();
		int nt = omp_get_num_threads();
		
		if (nt > n){ // Número de threads maior que o de posição de vetores
			if ( id <= n-1)
			{
				tamanho = 1;
				inicio = id;
				fim = id;
			}
			else
			{
				inicio = 0;
				fim = -1;
				tamanho = 0;
			}
		}
		else // nt > n
		{
			// Número de thread <=n
			tamanho = n / nt;
			inicio = id * tamanho;
			fim = inicio + tamanho - 1;
			
			if ( id == nt-1)
			{
				fim = n-1;
				tamanho = fim - inicio + 1;
			}
		} // nt <= n
		
		for(int i = inicio; i <=fim; i++){
			C[i] = A[i] + B[i];
		}	
	}//join
	
	// Imprimindo o resultado
	for (int i=0; i<n; i++)
	{
		printf("\nA [%d] + B[%d] = %10.2f  Thread id = %d", i, i, C[i], ID[i]);
	}
	

	return 0;
}
