//Write a program to insert elements in a 2D array and display the elements.
#include<stdio.h>
int inputElement( int rows, int cols, int array[rows][cols]){
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i+1, j+1);
            scanf("%d", &array[i][j]);
        }
    }
}

void printArray(int rows, int cols, int array[rows][cols]){
    printf("The elements of the 2D array are:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    int array[rows][cols];

    inputElement(rows, cols, array);
    printArray(rows, cols, array);

    return 0;
}