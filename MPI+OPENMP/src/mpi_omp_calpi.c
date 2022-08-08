#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"
#include <omp.h>

int main(int argc, char *argv[]){
const long int N = 10000000000;
const double h = 1.0/N;
const double PI = 3.141592653589793238462643;
double x,sum,pi,time1,time2,mypi; 
long int i;
int myrank,nproc;
int thread_status;

    MPI_Init_thread(&argc, &argv,MPI_THREAD_MULTIPLE,&thread_status);
    if (thread_status!=MPI_THREAD_MULTIPLE) {
	printf("Failed to initialize MPI_THREAD_MULTIPLE\n");
	exit(-1);
    }

    MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
    MPI_Comm_size(MPI_COMM_WORLD,&nproc);
    time1= omp_get_wtime();
    sum = 0.0;
#pragma omp parallel for shared(N,h,myrank,nproc),private(i,x),reduction(+:sum) num_threads(4)
    for (i=myrank; i<=N; i=i+nproc){
	x = h * (double)i;
	sum += 4.0/(1.0+x*x);
    }
    mypi = h*sum;

    MPI_Reduce(&mypi,&pi,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
    time2 = omp_get_wtime();

    if (myrank == 0) 
	    printf("Execution time %f difference %f \n", time2-time1,pi-PI);
    MPI_Finalize();
    return 0;
}
