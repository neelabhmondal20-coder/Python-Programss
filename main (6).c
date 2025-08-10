#include <stdio.h>

void diagonalSum(int N, int M[N][N]) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += M[i][i]; // Add the principal diagonal element
    }
    printf("%d\n", sum); // Print the sum of diagonal elements
}

int main() {
    int T; // Number of test cases
    scanf("%d", &T);
    
    while (T--) {
        int N;
        scanf("%d", &N);
        
        // Declare the matrix
        int M[N][N];
        
        // Read the matrix elements
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &M[i][j]);
            }
        }
        
        // Compute and print the sum of diagonal elements
        diagonalSum(N, M);
    }
    
    return 0;
}
