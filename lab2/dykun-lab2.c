#include <stdio.h>                    
#include <stdlib.h>

int main(){
    int i, j, N, M, min, max;     

    N = 4;
    M = 5;

    int A[N][M]; 

    int** matr;
    for (int i=0; i<N; i++) {
	   for (int j=0; j<M; j++) {
    		A[i][j] = rand() %100 + N-i;
        }
    }
    printf("We have a matrix:\n");
    
    for (int  i = 0; i < N; i++) {
        for (int j=0; j < M; j++) {
        printf("%4d ", A[i][j]);
        }
        printf( "\n" );
    }

    max=(A[0][0]);

    int maxRow = 0;
    int maxCol = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if(A[i][j] > A[maxRow][maxCol]) {
                maxRow = i;
                maxCol = j;

            }
        }
    }

    min=(A[0][0]); 
    
    int minRow = 0;
    int minCol = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if(A[i][j] < A[minRow][minCol]) {
                minRow = i;
                minCol = j;
            }
        }
    }

    printf("Min row: min=%d,\n",minRow);
    printf("max row: max=%d, \n", maxRow);

    for (int i = 0; i < M; ++i) {
        free(A[i]);
    }
    free(A);

    int firstRow, secondRow, rowCount, columnCount, tempCell;

    //new matrix
    A[N][M];
    for(i = 0; i < M; ++i)
    {
        tempCell = matr[minRow][i];
        matr[minRow][i] = matr[maxRow][i];
        matr[maxRow][i] = tempCell;
        for (int j=0; j < M; j++) {
        printf("%4d ", A[i][j]);
        }
        printf( "\n" );
    }

    for (int  i = 0; i < N; i++) {
        for (int j=0; j < M; j++) {
        printf("%4d ", A[i][j]);
        }
        printf( "\n" );
    }

    return 0;
}
