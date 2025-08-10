# Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Function to delete x-th node
def deleteNode(head, x):
    # If deleting the head node
    if x == 1:
        return head.next
    
    current = head
    count = 1
    
    # Traverse to the (x-1)th node
    while current is not None and count < x - 1:
        current = current.next
        count += 1
    
    # If current is valid and has a next node, skip the x-th node
    if current is not None and current.next is not None:
        current.next = current.next.next
    
    return head

# Utility to print linked list
def printList(head):
    temp = head
    while temp:
        print(temp.data, end=" -> " if temp.next else "")
        temp = temp.next
    print()

# Example usage
head = Node(1)
head.next = Node(3)
head.next.next = Node(4)

x = 3
head = deleteNode(head, x)
printList(head)  # Output: 1 -> 3

head2 = Node(1)
head2.next = Node(5)
head2.next.next = Node(2)
head2.next.next.next = Node(9)

x = 2
head2 = deleteNode(head2, x)
printList(head2)  # Output: 1 -> 2 -> 9
