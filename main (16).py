# Node definition
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Function to insert at end
def insertAtEnd(head, x):
    new_node = Node(x)
    
    # If list is empty
    if head is None:
        return new_node
    
    # Traverse to the last node
    current = head
    while current.next:
        current = current.next
    
    # Link new node at the end
    current.next = new_node
    return head

# Utility to print linked list
def printList(head):
    temp = head
    while temp:
        print(temp.data, end="->" if temp.next else "")
        temp = temp.next
    print()

# Example usage:
head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(4)
head.next.next.next.next = Node(5)

x = 6
head = insertAtEnd(head, x)
printList(head)  # Output: 1->2->3->4->5->6
