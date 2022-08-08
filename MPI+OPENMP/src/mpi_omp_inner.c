#include "mpi.h"
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 100000000
int main(int argc, char* argv[]) {

int my_rank, num_proc;
double* a_local;
double* b_local;
double prod_local, prod_total;
double init,end;
int thread_status;
long int i;

	MPI_Init_thread(&argc, &argv,MPI_THREAD_FUNNELED,&thread_status);
    	if (thread_status!=MPI_THREAD_FUNNELED) {
        	printf("Failed to initialize MPI_THREAD_FUNNELED\n");
        	exit(-1);
    	}

	MPI_Comm_rank (MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size (MPI_COMM_WORLD, &num_proc);
        a_local = (double*)malloc (N*sizeof(double));
        b_local = (double*)malloc (N*sizeof(double));
	
	for (i=0; i<N; i++) {
		a_local[i] = (double)i+1;
		b_local[i] = 2*(double)i+1;
    	}
        
	prod_local = 0.0;
        init = omp_get_wtime();
#pragma omp parallel for private(i) shared(a_local, b_local) reduction(+:prod_local) num_threads(8)
	for (i=0; i < N; i++) {
		prod_local += a_local[i] * b_local[i];
    	}
    	printf("Local dotProduct = %le  s\n", prod_local);
	MPI_Reduce (&prod_local, &prod_total, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	if (my_rank == 0) {
	        end = omp_get_wtime();
    		printf("dotProduct = %lf  time = %f s\n", prod_total, end-init);
  	} 
	MPI_Finalize ();
	return (0);
}
