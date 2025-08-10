#include <stdio.h>

int findSecondLargest(int arr[], int size) {
    int largest = -1, secondLargest = -1;

    for (int i = 0; i < size; i++) {
        if (arr[i] > largest) {
            secondLargest = largest; // Update second largest
            largest = arr[i];        // Update largest
        } else if (arr[i] > secondLargest && arr[i] < largest) {
            secondLargest = arr[i];  // Update second largest
        }
    }

    return secondLargest;
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int result = findSecondLargest(arr, size);
    
    if (result == -1) {
        printf("The second largest element does not exist.\n");
    } else {
        printf("The second largest element is: %d\n", result);
    }

    return 0;
}
