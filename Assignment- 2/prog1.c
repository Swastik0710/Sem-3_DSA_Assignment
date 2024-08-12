//Write a program to insert an element in array at any position and then search any element from the updated array using linear search.
#include<stdio.h>
int main() {
  int n, key, pos, value;
  printf("Enter the size of the array: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter %d elements: \n", n);
  for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
  }
  printf("Enter the position to insert an element: ");
  scanf("%d", &pos);
  if (pos < 0 || pos > n) {
      printf("Invalid position !");
      return 1;
  }
  printf("Enter the value to insert: ");
  scanf("%d", &value);
  for (int i = n; i > pos; i--) {
      arr[i] = arr[i-1];
  }
  arr[pos]= value;
  n++;
  printf("The updated array is: \n");
  for (int i = 0; i < n; i++) {
      printf("%d ", arr[i]);
  }
  printf("\n");
  printf("Enter the key to search: ");
  scanf("%d", &key);
  for (int i = 0; i < n; i++) {
      if (arr[i]==key) {
          printf("Element found at index %d.\n", i);
          return 0;
      }
  }
  printf("Element not found in the array.\n");
  return 0;
}
