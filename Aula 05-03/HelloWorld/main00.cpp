#include <iostream>
#include <omp.h>

// # diretiva de um compilador

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	printf("\n\nOpenMP: Hello world!!!\n");
	
	int n_threads;
	
	n_threads = omp_get_max_threads();
	
	printf("\nNumero de Threads (nucleos): %d \n\n", n_threads);
	
	#pragma omp parallel
	{
		int id_thread = omp_get_thread_num(); // identificaçã da Thread
		printf("%d", id_thread);
	}
	
	return 0;
}
