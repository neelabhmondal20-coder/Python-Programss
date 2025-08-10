# Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Function to detect and remove loop
def removeLoop(head):
    slow = head
    fast = head
    loop_exists = False

    # Detect loop using Floyd's algorithm
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            loop_exists = True
            break

    # If loop exists, remove it
    if loop_exists:
        slow = head
        # If loop starts at head
        if slow == fast:
            while fast.next != slow:
                fast = fast.next
        else:
            while slow.next != fast.next:
                slow = slow.next
                fast = fast.next
        fast.next = None
    return True  # Always true because operation completed

# Helper function to create linked list with optional loop
def createLinkedList(values, pos):
    if not values:
        return None
    head = Node(values[0])
    curr = head
    loop_node = None

    for i in range(1, len(values)):
        curr.next = Node(values[i])
        curr = curr.next
        if i + 1 == pos:  # 1-based
