#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
#include <math.h>
#include <stdbool.h>


bool primo (int n) {
        int i;

        for (i = 3; i < (int)(sqrt(n) + 1); i+=2)
             if (n%i == 0)
                 return false;
        return true;
}


int main(int argc, char *argv[]) {
	double t_inicial, t_final;
	int cont = 0, total = 0;
	long int i, n;
	int meu_ranque, num_procs, inicio, salto;

	if (argc < 2) {
        	printf("Valor inválido! Entre com um valor do maior inteiro\n");
       	 	return 0;
    } else {
        n = strtol(argv[1], (char **) NULL, 10);
    }

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &meu_ranque);
	MPI_Comm_size(MPI_COMM_WORLD, &num_procs);	
    t_inicial = MPI_Wtime();
    inicio = 3 + meu_ranque*2;
    salto = num_procs*2;
#pragma omp parallel for shared(n,salto,inicio), private(i), reduction(+:cont) num_threads(4) schedule(dynamic, 50000)
	for (i = inicio; i <= n; i += salto) 
	{	
		if(primo(i)) cont++;
	}
	t_final = MPI_Wtime();
		
	if(num_procs > 1) {
		MPI_Reduce(&cont, &total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	} else {
		total = cont;
	}
	
	if (meu_ranque == 0) {
	t_final = MPI_Wtime();
        total += 1;    /* Acrescenta o dois, que também é primo */
		printf("Quant. de primos entre 1 e n: %d \n", total);
		printf("Tempo de execucao: %1.3f \n", t_final - t_inicial);	
 
		printf("Numero de processos: %d \n", num_procs);	 
	}
	MPI_Finalize();
	return(0);
}

