#include <stdio.h>
#include <stdlib.h>


 int main() {
    int i, j, N, M;

    N = 4;
    M = 5;

    int A[4][5]=
    {
        {51,67,34,8,78},
        {65,9,6,2,6},
        {76,34,3,54,1},
        {96,38,31,524,5},
    };
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++) 
        printf("%d\t", A[i][j]);
        printf("\n");
    };    

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
    printf("\nMin row is %d\t", minRow);

    int maxRow = 0;
    int maxCol = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if(A[i][j] > A[minRow][minCol]) {
                maxRow = i;
                maxCol = j;
            }
        }
    }
    printf("\nMax row is %d\t", maxRow);


    int temp [5];
    for (int i = 0, j = 0; i < M; i++, j++) {
        temp[i] = A[maxRow][j];
    }

    for (int i = 0; i < M; i++)
    {
        printf("Temp array:%d\t", temp[i]);

    }; 

    for (int j = 0; j < M; j++) {
        A[maxRow][j] = A[minRow][j];
    } 

    for (int j = 0; j < M; j++, i++) {
        A[minRow][j] = temp[i];
    } 

    printf("\nNew matrix:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++) 
        printf("%d\t", A[i][j]);
        printf("\n");
    }; 

}

