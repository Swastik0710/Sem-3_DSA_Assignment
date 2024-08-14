//Write a program to sort the all elements of an array in ascending order using insertion sort technique.
#include<stdio.h>
int main()
{
  int size, key;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  int arr[size];
  printf("\nEnter %d elements: \n",size);
  for (int i = 0; i < size; i++) {
      scanf("%d", &arr[i]);
  }
  for (int i = 1; i < size; i++) {
    key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
  printf("Sorted array (in ascending order): \n");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
