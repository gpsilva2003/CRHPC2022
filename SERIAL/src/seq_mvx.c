#include <stdio.h>
#include <stdlib.h>

void mxv(int m, int n, double* A, double* b, double* c);

int main(int argc, char *argv[]) { /* mxv_seq.c  */
double *A,*b,*c;
int i, j, m, n;

    printf("Por favor entre com m e n: ");
    scanf("%d %d",&m,&n);
    printf("\n");
    
    A=(double *)malloc(m*n*sizeof(double));
    b=(double *)malloc(n*sizeof(double));
    c=(double *)malloc(m*sizeof(double));
  
   printf("Atribuindo valor inicial à matriz A e ao vetor b\n");
   for (j = 0; j < n; j++)
        b[j] = 2.0;
   for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
             A[i*n + j] = i;
   printf("Mutiplicando a matriz A com o vetor b\n");
   (void) mxv(m, n, A, b, c);
   
   free(A);
   free(b);
   free(c);
   return(0);
}

void mxv(int m, int n, double* A, double* b, double* c)
{
int i, j;
   for (i = 0; i < m; i++) {
       c[i] = 0.0;
       for (j = 0; j < n; j++)
            c[i] += A[i*n + j]*b[j];
   }
}
