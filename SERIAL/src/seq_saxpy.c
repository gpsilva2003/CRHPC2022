#include <stdlib.h>
void saxpy(long int n, float a, float * restrict x, float * restrict y)
{
    for (long int i = 0; i < n; ++i)
        y[i] = a*x[i] + y[i];
}
    
int main(int argc, char *argv[]) { /* acc_saxpy.c   */
long int n = 1<<26; // alguns milhões de floats
float *x = (float*)malloc(n*sizeof(float));
float *y = (float*)malloc(n*sizeof(float));
    for (long int i = 0; i < n; ++i) {
        x[i] = 2.0f;
        y[i] = 1.0f;
    }
    saxpy(n, 3.0f, x, y);
    free(x);
    free(y);
    return(0);
}
