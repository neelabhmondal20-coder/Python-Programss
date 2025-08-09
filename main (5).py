def next_greater_element(arr):
    n = len(arr)
    result = [-1] * n  # Initialize the result array with -1
    stack = []  # Stack to keep track of the next greater elements

    for i in range(n - 1, -1, -1):  # Traverse the array from right to left
        # Pop elements from the stack that are less than or equal to the current element
        while stack and stack[-1] <= arr[i]:
            stack.pop()
        
        # If the stack is not empty, the top element is the next greater element
        if stack:
            result[i] = stack[-1]
        
        # Push the current element onto the stack
        stack.append(arr[i])
    
    return result

# Example usage
arr1 = [1, 3, 2, 4]
print(next_greater_element(arr1))  # Output: [3, 4, 4, -1]

arr2 = [6, 8, 0, 1, 3]
print(next_greater_element(arr2))  # Output: [8, -1, 1, 3, -1]

arr3 = [10, 20, 30, 50]
print(next_greater_element(arr3))  # Output: [20, 30, 50, -1]

arr4 = [50, 40, 30, 10]
print(next_greater_element(arr4))  # Output: [-1, -1, -1, -1]
