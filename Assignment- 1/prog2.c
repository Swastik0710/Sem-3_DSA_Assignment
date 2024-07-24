////Write a program to delete an element in an array at any position.
#include<stdio.h>
int main() {
  int n, pos, value;
  printf("Enter the size of the array: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter %d elements: \n", n);
  for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
  }
  printf("Enter the position to delete an element: ");
  scanf("%d", &pos);
  if (pos < 0 || pos > n) {
      printf("Invalid position !");
      return 1;
  }
  for (int i = pos; i < n-1; i++) {
      arr[i] = arr[i+1];
  }
  n--;
  printf("The array after deletion is: \n");
  for (int i = 0; i < n; i++) {
      printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
