#include <stdio.h>

// Function to print the matrix
void printMatrix(int n, int mat[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to rotate the matrix by 90 degrees anti-clockwise
void rotate90AntiClockwise(int n, int mat[][n]) {
    // Step 1: Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // Swap mat[i][j] with mat[j][i]
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    // Step 2: Reverse each column
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n / 2; i++) {
            // Swap mat[i][j] with mat[n - 1 - i][j]
            int temp = mat[i][j];
            mat[i][j] = mat[n - 1 - i][j];
            mat[n - 1 - i][j] = temp;
        }
    }
}

int main() {
    // Example 1: 3x3 matrix
    printf("Example 1 Input:\n");
    int mat1[3][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}
    };
    printMatrix(3, mat1);
    
    rotate90AntiClockwise(3, mat1);

    printf("\nExample 1 Output:\n");
    printMatrix(3, mat1);

    // Example 2: 2x2 matrix
    printf("\nExample 2 Input:\n");
    int mat2[2][2] = {
        {1, 2},
        {3, 4}
    };
    printMatrix(2, mat2);

    rotate90AntiClockwise(2, mat2);

    printf("\nExample 2 Output:\n");
    printMatrix(2, mat2);

    return 0;
}
