def spiral_traversal(mat):
    if not mat:
        return []
    
    result = []
    top, left = 0, 0
    bottom, right = len(mat) - 1, len(mat[0]) - 1
    
    while top <= bottom and left <= right:
        # Traverse from Left to Right
        for i in range(left, right + 1):
            result.append(mat[top][i])
        top += 1
        
        # Traverse from Top to Bottom
        for i in range(top, bottom + 1):
            result.append(mat[i][right])
        right -= 1
        
