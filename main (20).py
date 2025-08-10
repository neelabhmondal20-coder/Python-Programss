# Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Function to detect loop
def hasLoop(head):
    slow = head
    fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    return False

# Helper function to create linked list with optional loop
def createLinkedList(values, pos):
    if not values:
        return None
    head = Node(values[0])
    curr = head
    loop_node = None

    # Create linked list
    for i in range(1, len(values)):
        curr.next = Node(values[i])
        curr = curr.next
        if i + 1 == pos:  # Store loop position node
            loop_node = curr

    # If pos == 1, loop back to head
    if pos == 1:
        loop_node = head

    # Connect last node to loop_node if pos != 0
    if pos != 0:
        curr.next = loop_node

    return head

# Example usage:
values = [1, 3, 4]
pos = 2  # 1-based index of loop node, 0 me
