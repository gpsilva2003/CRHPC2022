#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int primo (long int n) {
	long int i;
       
	for (i = 3; i < (int)(sqrt(n) + 1); i+=2) 
	     if (n%i == 0) 
	         return 0;
	return 1;
}

int main(int argc, char *argv[]) { /* primos_seq.c  */
	int total=0;
	long int i, n;

	if (argc < 2) {
            printf("Valor inválido! Entre com o valor do maior inteiro\n");
       	    return 0;
    	} else {
            n = strtol(argv[1], (char **) NULL, 10);
    	}

	for (i = 3; i <= n; i += 2) 	
	     if(primo(i) == 1) total++;
		
    	total += 1;    /* Acrescenta o dois, que também é primo */
	printf("Quant. de primos entre 1 e n: %d \n", total);
	total  = (long int)  n /(log(n)-(1.08366)); 
	printf("Quant. aprox. de primos entre 1 e n: %d \n", total);
	return(0);
}
