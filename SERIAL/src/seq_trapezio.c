#include <stdio.h> 
#include <math.h>
float f(float x) {   /* Calcula f(x). */
float return_val; 
   return_val=exp(x);
   return return_val; 
} 
int main(int argc, char *argv[]) {  /* trapezio_seq.c  */
float integral;   /* integral armazena resultado final */ 
float a, b;       /* a, b -  limite esquerdo e direito da função */ 
int   i,n;        /* n - número de trapezóides */ 
float x, h;       /* h - largura da base do trapezóide */ 

   printf("Entre a, b, e n \n"); 
   scanf("%f %f %d", &a, &b, &n); 
   h = (b-a)/n; 
   integral = (f(a) + f(b))/2.0; 
   x = a; 
   for (i = 1; i < n; i++) {
        x += h; 
        integral += f(x); 
   } 
   integral *= h; 
   printf("Com n = %d trapezóides, a estimativa \n", n); 
   printf("da integral de %f até %f = %f\n", a, b, integral); 
   return 0;
} 
