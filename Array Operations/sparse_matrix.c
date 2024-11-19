//Write a program to check whether a matrix is sparse or not.
#include<stdio.h>
int main() {
  int rows, cols, count = 0;
  int matrix[10][10];
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  printf("Enter the number of columns: ");
  scanf("%d", &cols);
  printf("Enter the elements of the matrix: \n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      scanf("%d", &matrix[i][j]);
      if (matrix[i][j] == 0) {
        count++;
      }
    }
  }
  if (count > (rows*cols)/2) {
    printf("The matrix is sparse.\n");
  }
  else {
     printf("The matrix is not sparse.\n");
  }
  return 0;
}
