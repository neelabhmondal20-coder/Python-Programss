# Node definition
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Function to insert in the middle
def insertInMiddle(head, x):
    new_node = Node(x)
    
    # If the list is empty
    if head is None:
        return new_node
    
    # If there is only one node
    if head.next is None:
        head.next = new_node
        return head

    # Find middle using slow and fast pointers
    slow = head
    fast = head
    while fast.next and fast.next.next:
        slow = slow.next
        fast = fast.next.next

    # Insert
