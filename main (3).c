#include <stdio.h>
#include <stdlib.h>

int* countFrequency(int* arr, int size) {
    // Create a result array initialized to 0
    int* result = (int*)calloc(size, sizeof(int));
    
    // Count the frequency of each number in arr
    for (int i = 0; i < size; i++) {
        result[arr[i] - 1]++; // Increment the count for the number arr[i]
    }
    
    return result;
}

int main() {
    // Example input
    int arr1[] = {2, 3, 2, 3, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    
    int* result1 = countFrequency(arr1, size1);
    
    // Print the result for the first example
    printf("Output: [");
    for (int i = 0; i < size1; i++) {
        printf("%d", result1[i]);
        if (i < size1 - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    
    // Free the allocated memory
    free(result1);
    
    // Example input 2
    int arr2[] = {3, 3, 3, 3};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int* result2 = countFrequency(arr2, size2);
    
    // Print the result for the second example
    printf("Output: [");
    for (int i = 0; i < size2; i++) {
        printf("%d", result2[i]);
        if (i < size2 - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    
    // Free the allocated memory
    free(result2);
    
    // Example input 3
    int arr3[] = {1};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    
    int* result3 = countFrequency(arr3, size3);
    
    // Print the result for the third example
    printf("Output: [");
    for (int i = 0; i < size3; i++) {
        printf("%d", result3[i]);
        if (i < size3 - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    
    // Free the allocated memory
    free(result3);
    
    return 0;
}
