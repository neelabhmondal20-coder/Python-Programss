def diagonalSum(N, M):
    total = 0
    for i in range(N):
        total += M[i][i]
    return total


# Driver code
T = int(input())
for _ in range(T):
    N = int(input())
    elements = list(map(int, input().split()))
    
    # Converting flat list into NxN matrix
    matrix = []
    for i in range(0, len(elements), N):
        matrix.append(elements[i:i+N])
    
    print(diagonalSum(N, matrix))
