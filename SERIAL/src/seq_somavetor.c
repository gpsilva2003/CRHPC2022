#include <stdlib.h>
    
int main(int argc, char *argv[]) { /* seq_somavetor.c   */
int A[6]={2, 4, 6, 8, 16, 20};
int B[6] ={3, 5, 7, 9, 11, 17};
int C[6];
    for (int i = 0; i < 6; ++i)
        C[i] = A[i] + 8*B[i];
    return(0);
}
