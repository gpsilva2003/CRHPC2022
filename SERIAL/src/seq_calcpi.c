#include <stdio.h>
#define N 1000000000

int main(int argc, char *argv[]) { /* calcpi_seq.c  */
double pi = 0.0f; 
long i;
    for (i = 0; i < N; i++) {
         double t = (double) ((i+0.5)/N);
         pi += 4.0/(1.0+t*t);
    }
    printf("pi = %f\n",pi/N);
    return(0);
}
