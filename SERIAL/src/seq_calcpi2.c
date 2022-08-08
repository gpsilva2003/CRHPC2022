#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char **argv)

{ 
int n, i;
double  pi, h, x, sum = 0.0;

                printf ("Entre com o número de intervalos: "); 
		scanf("%d", &n);

		if(argc != 2)
   		{
      			printf("Número incorreto de argumentos\n");
      			exit(-1);
   		}


		if (sscanf(argv[1], "%d", &n) != 1)  /*n é fornecido como segundo argumento */

     		{
        		/* 	Erro  */
        		exit(-1);
     		 }

	if (n != 0)
	{ 
		h=1.0/ (double) n;
		for (i=1; i <= n; i++)
		{ 
			x = h * ((double)i - 0.5);
			sum += (4.0/(1.0 + x*x));
		}
	       pi = h* sum;
                printf ("valor aproximado de pi: %.16f \n", pi);
	}
}
