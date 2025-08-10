#include <stdio.h>

int josephus(int n, int k) {
    int result = 0; // Base case: when there's only one person, they are the survivor

    // Iterate from 2 to n to build up the solution
    for (int i = 2; i <= n; i++) {
        result = (result + k) % i; // Update the position of the survivor
    }

    // Convert to 1-based index
    return result + 1;
}

int main() {
    int n, k;

    // Input the number of people and the step count
    printf("Enter the number of people (n): ");
    scanf("%d", &n);
    printf("Enter the step count (k): ");
    scanf("%d", &k);

    // Get the position of the last person remaining
    int survivor = josephus(n, k);
    printf("The position of the last person remaining is: %d\n", survivor);

    return 0;
}
