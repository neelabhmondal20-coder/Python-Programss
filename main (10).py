def count_frequencies(arr):
    n = len(arr)
    # Initialize a frequency array with zeros
    frequency = [0] * n
    
    # Count the frequency of each number in arr
    for num in arr:
        frequency[num - 1] += 1  # Increment the count for the number (1-based index)
    
    return frequency

# Example usage
arr1 = [2, 3, 2, 3, 5]
print(count_frequencies(arr1))  # Output: [0, 2, 2, 0, 1]

arr2 = [3, 3, 3, 3]
print(count_frequencies(arr2))  # Output: [0, 0, 4, 0]

arr3 = [1]
print(count_frequencies(arr3))  # Output: [1]
