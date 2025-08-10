#include <stdio.h>

void transposeMatrix(int n, int mat[n][n]) {
    // Create a new matrix to store the transpose
    int transposed[n][n];

    // Fill the transposed matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            transposed[j][i] = mat[i][j]; // Assigning rows to columns
        }
    }

    // Print the transposed matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", transposed[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n; // Size of the matrix
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    // Declare the matrix
    int mat[n][n];

    // Read the matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    // Compute and print the transpose of the matrix
    printf("Transposed Matrix:\n");
    transposeMatrix(n, mat);

    return 0;
}
