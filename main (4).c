#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** mat, int n, int m, int* returnSize) {
    // Allocate memory for the result array
    int* result = (int*)malloc(n * m * sizeof(int));
    *returnSize = 0; // Initialize return size

    // Define the boundaries of the matrix
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    while (top <= bottom && left <= right) {
        // Traverse from left to right along the top row
        for (int i = left; i <= right; i++) {
            result[(*returnSize)++] = mat[top][i];
        }
        top++; // Move the top boundary down

        // Traverse from top to bottom along the right column
        for (int i = top; i <= bottom; i++) {
            result[(*returnSize)++] = mat[i][right];
        }
        right--; // Move the right boundary left

        if (top <= bottom) {
            // Traverse from right to left along the bottom row
            for (int i = right; i >= left; i--) {
                result[(*returnSize)++] = mat[bottom][i];
            }
            bottom--; // Move the bottom boundary up
        }

        if (left <= right) {
            // Traverse from bottom to top along the left column
            for (int i = bottom; i >= top; i--) {
                result[(*returnSize)++] = mat[i][left];
            }
            left++; // Move the left boundary right
        }
    }

    return result; // Return the result array
}

int main() {
    // Example input
    int n1 = 4, m1 = 4;
    int mat1[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    // Convert to a pointer to pointer for function compatibility
    int** matrix1 = (int**)malloc(n1 * sizeof(int*));
    for (int i = 0; i < n1; i++) {
        matrix1[i] = (int*)malloc(m1 * sizeof(int));
        for (int j = 0; j < m1; j++) {
            matrix1[i][j] = mat1[i][j];
        }
    }

    int returnSize1;
    int* result1 = spiralOrder(matrix1, n1, m1, &returnSize1);

    // Print the result for the first example
    printf("Output: [");
    for (int i = 0; i < returnSize1; i++) {
        printf("%d", result1[i]);
        if (i < returnSize1 - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    // Free allocated memory
    free(result1);
    for (int i = 0; i < n1; i++) {
        free(matrix1[i]);
    }
    free(matrix1);

    // Example input 2
    int n2 = 3, m2 = 3;
    int mat2[3][3] = {
        {2, 7, 10},
        {5, 1, 3},
        {4, 2, 8}
    };

    // Convert to a pointer to pointer for function compatibility
    int** matrix2 = (int**)malloc(n2 * sizeof(int*));
    for (int i = 0; i < n2; i++) {
        matrix2[i] = (int*)malloc(m2 * sizeof(int));
        for (int j = 0; j < m2; j++) {
            matrix2[i][j] = mat2[i][j];
        }
    }

    int returnSize2;
    int* result2 = spiralOrder(matrix2, n2, m2, &returnSize2);

    // Print the result for the second example
    printf("Output: [");
    for (int i = 0; i < returnSize2; i++) {
        printf("%d", result2[i]);
        if (i < returnSize2 - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    // Free allocated memory
    free(result2);
    for (int i = 0; i < n2; i++) {
        free(matrix2[i]);
    }
    free(matrix2);

    // Example input 3
    int n3 = 2, m3 = 4;
    int mat3[2][4] = {
        {32, 44, 27, 23},
        {54, 28, 50, 62}
    };

    // Convert to a pointer to pointer for function compatibility
    int** matrix3 = (int**)malloc(n3 * sizeof(int*));
    for (int i = 0; i < n3; i++) {
        matrix3[i] = (int*)malloc(m3 * sizeof(int));
        for (int j = 0; j < m3; j++) {
            matrix3[i][j] = mat3[i][j];
        }
    }

    int returnSize3;
    int* result3 = spiralOrder(matrix3, n3, m3, &returnSize3);

    // Print the result for the third example
    printf("Output: [");
    for (int i = 0; i < returnSize3; i++) {
        printf("%d", result3[i]);
        if (i < returnSize3 - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    // Free allocated memory
    free(result3);
    for (int i = 0; i < n3; i++) {
        free(matrix3[i]);
    }
    free(matrix3);

    return 0;
}
