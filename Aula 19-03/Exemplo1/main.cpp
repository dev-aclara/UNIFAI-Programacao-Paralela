#include <iostream>
#include <math.h>
#include <omp.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int const n = 10;
	int ID[n];
	int A[n]; 
	int B[n]; 
	int C[n];
	
	#pragma omp parallel
	{
		int i;
		#pragma omp for
		for (i = 0; i < n; i++){
			ID[i] = omp_get_thread_num();
		}
	}
	#pragma omp parallel
	{
		#pragma omp section nowait
		{
			for(int i=0; i<n; i++) A[i] = i + 10;
		}
		
		#pragma omp section
		{
			for(int i=0; i<n; i++) B[i] = i * 8;
		}
	} // sections
	
	#pragma omp single
	{
		for (int i=0; i<n; i++) C[i] = i + 158;
	}
} // join 
