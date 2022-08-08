#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int main( int argc, char* argv[] ) /* acc_data.c  */
{
int n = 40000000;                  /* tamanho dos vetores  */
double *restrict a;                /* vetores de entrada */
double *restrict b;
double *restrict c;                /* vetor de saída */
size_t bytes = n*sizeof(double);   /* tamanho em bytes de cada vetor */

 
    /*  Alocação de memória para cada vetor */
    a = (double*)malloc(bytes);
    b = (double*)malloc(bytes);
    c = (double*)malloc(bytes);

    /* Atribui os valores iniciais para os vetores de entrada */ 
    for (int i = 0; i < n; i++) {
         a[i] = sin(i)*sin(i);
         b[i] = cos(i)*cos(i);
    }
 
    double soma = 0.0;
    /*  Soma os elementos de cada vetor e salva o resultado no vetor C e realiza a redução */
        for(int i = 0; i < n; i++) {
            c[i] = a[i] + b[i];
            soma += c[i];
        }
 
    soma = soma/(double)n;
    printf("resultado final: %f\n", soma);
    /* Libera a memória alocada */
    free(a);
    free(b);
    free(c);
 
    return 0;
}
