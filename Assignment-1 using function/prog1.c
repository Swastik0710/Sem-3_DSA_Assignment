//Write a program to insert an element in an array at any position.
#include <stdio.h>

void inputArray(int arr[], int n) {
    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++) {
        printf("-> ");
        scanf("%d", &arr[i]);
    }
}

int insertElement(int arr[], int n, int pos, int value) {
    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return n; 
    }

    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    return n + 1; 
}

void printArray(int arr[], int n) {
    printf("The updated array is: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, pos, value;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n + 1];  

    inputArray(arr, n);

    printf("Enter the position to insert an element (0 to %d): ", n);
    scanf("%d", &pos);

    printf("Enter the value to insert: ");
    scanf("%d", &value);

    n = insertElement(arr, n, pos, value);

    printArray(arr, n);

    return 0;
}
