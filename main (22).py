# Node class for linked list
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Function to reverse linked list
def reverseLinkedList(head):
    prev = None
    curr = head
    while curr:
        next_node = curr.next
        curr.next = prev
        prev = curr
        curr = next_node
    return prev  # New head after reversal

# Helper function to create linked list from list of values
def createLinkedList(values):
    if not values:
        return None
    head = Node(values[0])
    curr = head
    for val in values[1:]:
        curr.next = Node(val)
        curr = curr.next
    return head

# Helper function to print linked list
def printLinkedList(head):
    curr = head
    while curr:
        print(curr.data, end=" ")
        curr = curr.next
    print()

# Example usage
values = [2, 7, 10, 9, 8]
head = createLinkedList(values)
head = reverseLinkedList(head)
printLinkedList(head)
