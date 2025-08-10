def find_largest(arr):
    # Check if the array is empty
    if not arr:
        return None  # or raise an exception if preferred

    largest = arr[0]  # Assume the first element is the largest
    for num in arr[1:]:
        if num > largest:
            largest = num  # Update largest if current element is greater
    return largest

# Example usage
if __name__ == "__main__":
    # Test cases
    arr1 = [1, 8, 7, 56, 90]
    print("Input:", arr1)
    print("Output:", find_largest(arr1))  # Output: 90

    arr2 = [5, 5, 5, 5]
    print("Input:", arr2)
    print("Output:", find_largest(arr2))  # Output: 5

    arr3 = [10]
    print("Input:", arr3)
    print("Output:", find_largest(arr3))  # Output: 10
