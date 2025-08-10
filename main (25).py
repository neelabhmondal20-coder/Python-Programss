def josephus(n, k):
    # Base case: only one person left
    if n == 1:
        return 1
    # Recursive step: position shifts due to elimination
    return (josephus(n - 1, k) + k - 1) % n + 1


# Example usage
print(josephus(3, 2))  # Output: 3
print(josephus(5, 3))  # Output: 4
