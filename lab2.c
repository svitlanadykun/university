#include <stdio.h>
#include <stdlib.h>


 int main() {
    int i,j,min,max,imin,imax,jmax,jmin,N,M;

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
    printf("%d\t", minRow);

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
    printf("%d\t", maxRow);

    int temp [5];
    for (int i = 0; i < M; ++i) {
        temp[i] = A[maxRow][j];
    }
    for (int i = 0; i < M; i++)
    {
        printf("%d\t", temp[i]);

    };  
       for (i = 0; i < M; i++) {
            printf("%4d ", temp[i]);

     }

    



// int getMinElementRowNumber(int **a, int size) {
//     int minRow = 0;
//     int minCol = 0;
//     for (int i = 0; i < size; ++i) {
//         for (int j = 0; j < size; ++j) {
//             if(a[i][j] < a[minRow][minCol]) {
//                 minRow = i;
//                 minCol = j;
//             }
//         }
//     }
//     return minRow;
// }


}