#include <stdio.h>

void inputElements(int n, int arr[]) {
    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++) {
        printf("-> ");
        scanf("%d", &arr[i]);
    }
}

int deleteElement(int arr[], int n, int pos) {
    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return n; 
    }

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    return n - 1; 
}

void printArray(int arr[], int n) {
    printf("The array after deletion is: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, pos;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    inputElements(n, arr);

    printf("Enter the position to delete an element (0 to %d): ", n - 1);
    scanf("%d", &pos);

    n = deleteElement(arr, n, pos);

    printArray(arr, n);

    return 0;
}
