class Node:
    def __init__(self, data):
        self.data = data
        self.next = None  # Points to next head node
        self.bottom = None  # Points to sub-linked list


# Merge two sorted linked lists (using bottom pointers)
def merge(a, b):
    if a is None:
        return b
    if b is None:
        return a

    if a.data < b.data:
        result = a
        result.bottom = merge(a.bottom, b)
    else:
        result = b
        result.bottom = merge(a, b.bottom)

    result.next = None  # Ensure 'next' is not used
    return result


# Flatten the linked list
def flatten(root):
    if root is None or root.next is None:
        return root

    # Flatten the li
