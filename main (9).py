def move_zeros(arr):
    # Pointer for the position of the last non-zero element
    last_non_zero_index = 0
    
    # Iterate through the array
    for i in range(len(arr)):
        if arr[i] != 0:
            # If the current element is not zero, we need to move it to the last_non_zero_index
            arr[last_non_zero_index] = arr[i]
            last_non_zero_index += 1
    
    # After all non-zero elements have been moved, fill the rest of the array with zeros
    for i in range(last_non_zero_index, len(arr)):
        arr[i] = 0

# Example usage
arr1 = [1, 2, 0, 4, 3, 0, 5, 0]
move_zeros(arr1)
print(arr1)  # Output: [1, 2, 4, 3, 5, 0, 0, 0]

arr2 = [10, 20, 30]
move_zeros(arr2)
print(arr2)  # Output: [10, 20, 30]

arr3 = [0, 0]
move_zeros(arr3)
print(arr3)  # Output: [0, 0]
