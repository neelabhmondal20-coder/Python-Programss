#include <stdio.h>

int findLargest(int arr[], int size) {
    int largest = arr[0]; // Assume the first element is the largest

    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i]; // Update largest if current element is greater
        }
    }

    return largest;
}

int main() {
    int arr[] = {1, 8, 7, 56, 90}; // Example input
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    int largest = findLargest(arr, size);
    printf("The largest element is: %d\n", largest);

    return 0;
}
