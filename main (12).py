def rotate_anticlockwise(mat):
    n = len(mat)
    
    # Step 1: Transpose the matrix
    for i in range(n):
        for j in range(i, n):
            mat[i][j], mat[j][i] = mat[j][i], mat[i][j]
    
    # Step 2: Reverse each column
    for col in range(n):
        for row in range(n // 2):
            mat[row][col], mat[n - 1 - row][col] = mat[n - 1 - row][col], mat[row][col]
    
    return mat


# Example usage:
mat1 = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8]
]
rotate_anticlockwise(mat1)
print(mat1)
# Output: [[2, 5, 8], [1, 4, 7], [0, 3, 6]]

mat2 = [
    [1, 2],
    [3, 4]
]
rotate_anticlockwise(mat2)
print(mat2)
# Out
