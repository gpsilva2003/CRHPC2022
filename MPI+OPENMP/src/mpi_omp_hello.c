#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
#include <omp.h>

int main(int argc, char *argv[])
{
    int numprocs, rank, namelen;
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int iam = 0, np = 1, thread_status;

    MPI_Init_thread(&argc, &argv,MPI_THREAD_MULTIPLE,&thread_status);
    	if (thread_status!=MPI_THREAD_MULTIPLE) {
        	printf("Failed to initialize MPI_THREAD_MULTIPLE\n");
        	exit(-1);
    	}

    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Get_processor_name(processor_name, &namelen);

    #pragma omp parallel default(shared) private(iam, np) num_threads(3)
    {
        np = omp_get_num_threads();
        iam = omp_get_thread_num();
        printf("Hybrid: Hello from thread %d out of %d from process %d out of %d on %s\n", iam, np, rank, numprocs, processor_name);
    }

    MPI_Finalize();

    return 0;
}
