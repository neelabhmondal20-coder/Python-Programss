def second_largest(arr):
    # Initialize the largest and second largest to None
    largest = second = None
    
    for number in arr:
        # Update largest and second largest accordingly
        if largest is None or number > largest:
            second = largest
            largest = number
        elif number != largest:  # Ensure it's not equal to the largest
            if second is None or number > second:
                second = number
    
    # If second is still None, it means there is no second largest
    return second if second is not None else -1

# Test cases
print(second_largest([12, 35, 1, 10, 34, 1]))  # Output: 34
print(second_largest([10, 5, 10]))              # Output: 5
print(second_largest([10, 10, 10]))             # Output: -1
