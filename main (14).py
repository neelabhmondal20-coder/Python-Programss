def transposeMatrix(mat, n):
    # Swap elements across the diagonal
    for i in range(n):
        for j in range(i+1, n):
            mat[i][j], mat[j][i] = mat[j][i], mat[i][j]
    return mat


# Example usage
n = int(input())
mat = [list(map(int, input().split())) for _ in range(n)]

result = transposeMatrix(mat, n)
for row in result:
    print(*row)
