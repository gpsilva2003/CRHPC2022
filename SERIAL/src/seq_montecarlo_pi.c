/*
 *
 * Autor: Adrian Statescu mergesortv@gmail.com http://adrianstatescu.com
 *
 * Descrição:  Programa em C Program para computar o valor de PI usando o método de Monte Carlo.
 *
 * Licença MIT 
 *
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SEED time(NULL)

int main() {

 srand( SEED );
 int i, count, n=1000000000;
 double x,y,z,pi;

 printf("n = %d \n", n);

 count = 0;

 for(i = 0; i < n; ++i) {
     x = (double)rand() / RAND_MAX;
     y = (double)rand() / RAND_MAX;
     z = x * x + y * y;
     if( z <= 1 ) count++;
 }

 pi = (double) count / n * 4;
 printf("Aproximação de PI é = %g", pi);
 return(0);
}
