def find_celebrity(mat):
    n = len(mat)
    
    # Step 1: Find the potential celebrity
    candidate = 0
    for i in range(1, n):
        if mat[candidate][i] == 1:
            candidate = i
    
    # Step 2: Verify if the candidate is a celebrity
    for i in range(n):
        if i != candidate:
            if mat[candidate][i] == 1 or mat[i][candidate] == 0:
                return -1
    
    return candidate

# Example usage:
mat1 = [[1, 1, 0], [0, 1, 0], [0, 1, 1]]
print(find_celebrity(mat1))  # Output: 1

mat2 = [[1, 1], [1, 1]]
print(find_celebrity(mat2))  # Output: -1

mat3 = [[1]]
print(find_celebrity(mat3))  # Output: 0
