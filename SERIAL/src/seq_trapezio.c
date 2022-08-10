#include <stdio.h> 
#include <math.h>
double  f(float x) {   /* Calcula f(x). */
double return_val; 
   return_val=exp(x);
   return return_val; 
} 
int main(int argc, char *argv[]) {  /* trapezio_seq.c  */
double integral;   /* integral armazena resultado final */ 
double a=0.0, b=1.0;       /* a, b -  limite esquerdo e direito da função */ 
long int   i,n=500000000;        /* n - número de trapezóides */ 
double x, h;       /* h - largura da base do trapezóide */ 

//   printf("Entre a, b, e n \n"); 
//   scanf("%f %f %d", &a, &b, &n); 
   h = (b-a)/n; 
   integral = (f(a) + f(b))/2.0; 
   x = a; 
   for (i = 1; i < n; i++) {
        x += h; 
        integral += f(x); 
   } 
   integral *= h; 
   printf("Com n = %ld trapezóides, a estimativa \n", n); 
   printf("da integral de %f até %f = %f\n", a, b, integral); 
   return 0;
} 
