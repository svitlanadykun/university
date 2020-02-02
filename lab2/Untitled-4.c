#include <stdio.h>
#include <stdlib.h>

int initMatrix(int **, int size);
int printMatrix(int **, int);
int initNewMatrix(int **a, int size, int tempCell, int minRow, int maxRow);
int getMinElementRowNumber(int **, int);
int getSumOfRow(int **, int, int);
void freeMatrix(int **M, int size);

int main(){
    int N;
    printf("Enter size of Matrix\n");
    scanf("%d", &N);

    int **a = malloc(N * sizeof(int*));
    for (int i = 0; i < N; ++i) {
        a[i] = malloc(N * sizeof(int));
    }

    initMatrix(a, N);
    printMatrix(a, N);

    int rowNum = getMinElementRowNumber(a, N);
    int sum = getSumOfRow(a, N, rowNum);
    
    printf("\nThe sum of elements of %d row is equal to %d\n", rowNum, sum);

    freeMatrix(a, N);

    initNewMatrix(a, N);
    
    return 0;


}

void freeMatrix(int **a, int size) {
    for (int i = 0; i < size; ++i) {
        free(a[i]);
    }
    free(a);
}

int initMatrix(int **a, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            a[i][j] = rand() % 100;
        }
    }
    a[size-1][size-1] = -1;
    return 0;
}

int initNewMatrix(int **a, int size, int tempCell, int minRow, int maxRow) {
    for(i = 0; i < size; ++i)    {
        tempCell = matr[minRow][i];
        matr[minRow][i] = matr[maxRow][i];
        matr[maxRow][i] = tempCell;
    return 0;
}

int printMatrix(int **a, int size) {
    for(int i = 0; i < size; i++)
    {
        printf("\n");
        for(int j = 0; j < size; j++)
            printf("%4d", a[i][j]);
    }
    return 0;
}

int getMinElementRowNumber(int **a, int size) {
    int minRow = 0;
    int minCol = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(a[i][j] < a[minRow][minCol]) {
                minRow = i;
                minCol = j;
            }
        }
    }
    return minRow;
}

int getSumOfRow(int **a, int size, int rowNum) {
    int sum = 0;
    for (int j = 0; j < size; ++j) {
        sum += a[rowNum][j];
    }
    return sum;    
}