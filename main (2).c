#include <stdio.h>

void moveZerosToEnd(int arr[], int size) {
    int count = 0; // Count of non-zero elements

    // Traverse the array and move non-zero elements to the front
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            arr[count++] = arr[i]; // Move non-zero element to the front
        }
    }

    // Fill the remaining array with zeros
    while (count < size) {
        arr[count++] = 0;
    }
}

int main() {
    int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    moveZerosToEnd(arr, size);

    // Print the modified array
    printf("Output: [");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}
