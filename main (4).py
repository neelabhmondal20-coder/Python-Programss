def calculate_span(arr):
    n = len(arr)
    span = [0] * n
    stack = []

    for i in range(n):
        # Calculate span for arr[i]
        while stack and arr[stack[-1]] <= arr[i]:
            stack.pop()
        
        if not stack:
            span[i] = i + 1  # No higher price before
        else:
            span[i] = i - stack[-1]  # Difference of indices
        
        stack.append(i)  # Push current index onto stack

    return span

# Example usage
arr1 = [100, 80, 60, 70, 60, 75, 85]
print(calculate_span(arr1))  # Output: [1, 1, 1, 2, 1, 4, 6]

arr2 = [10, 4, 5, 90, 120, 80]
print(calculate_span(arr2))  # Output: [1, 1, 2, 4, 5, 1]
