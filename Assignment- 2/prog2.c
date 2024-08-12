//Write a program to search any element from an array using binary search technique.
#include<stdio.h>
int main() {
  int n, target;
  printf("Enter the size of the array: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter %d elements: \n", n);
  for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
  }
  printf("Enter the target element: ");
  scanf("%d", &target);
  int left = 0, right = n-1, mid;
  while (left <= right) {
      mid = (left + right)/2;
      if (arr[mid] == target) {
          printf("Element found at index %d.\n", mid);
          return 0;
      }
      else if (arr[mid] < target) {
          left = mid + 1;
      }
      else {
          right = mid - 1;
      }
  }
  printf("Element not found in the array.\n");
  return 0;
}
