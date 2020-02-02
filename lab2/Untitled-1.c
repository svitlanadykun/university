#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, columns, m,n;         
    int i, j;          
    int k, new_rows;            
    int min,new,c;          
    int temp;          
    srand(time(NULL));
    
    printf("Enter number of rows and columns separated by spaces\n");
    scanf("%d%d", &rows,&columns);
    int matrix[rows][columns];
    for (int i = 0; i <= rows; ++i) {
        for (int j = 0; j < columns; ++j) matrix[i][j] = rand() % 100;     //заповнення матриці випадковими числами  від 0 до 99
        };
    printf("Matrix before sorting:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf( "%d ", matrix[i][j]);
            }
        printf("\n");
    }
    printf("\nEnter number of column you would like to sort\n");
    scanf("%d", &k);
    if(k < 0 || k > (columns)) {
        printf("Such column does not exist \n");
        return(0);
    };
    k--; //зменшуємо індекс на 1 так як в масиві лічильник елементів починається з 0
    new_rows = rows;
    do 
    {
        for (i = 0;  i < new_rows - 1; ++i)
        {
            if (matrix[i][k] < matrix[i + 1][k])
            {
                temp = matrix[i][k];
                matrix[i][k] = matrix[i + 1][k];
                matrix[i + 1][k] = temp;
            }
        }
        new_rows = new_rows - 1;
        // Прохід зправа наліво перемістить найменший елемент на його правильне місце на початку
        for (i= rows - 1, c = 0; i > c; --i)
        {
            if(matrix[i][k] > matrix[i - 1][k])
            {
                new = matrix[i - 1][k];
                matrix[i - 1][k] = matrix[i][k];
                matrix[i][k] = new;
            }
        }
       c = c + 1;
    } while (new_rows != 0 && c != 0);
        
    printf("\n");
    printf("Sorted matrix:");
    printf("\n");
    // виведення матриці в консоль
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
           printf( "%d ", matrix[i][j]);
        }
        printf("\n");
    }
return(0);
}