#include <stdio.h>

int countZeros(int A[][1000], int N) {
    int row = 0, col = N - 1;
    int count = 0;

    while (row < N && col >= 0) {
        if (A[row][col] == 0) {
            // All elements from col 0 to current col are zero
            count += (col + 1);
            row++; // move to next row
        } else {
            col--; // move left
        }
    }
    return count;
}

int main() {
    int N;
    scanf("%d", &N);

    int A[1000][1000]; // max N is 1000
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("%d\n", countZeros(A, N));
    return 0;
}
