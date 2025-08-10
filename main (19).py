# Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Function to search key in linked list
def searchKey(head, key):
    current = head
    while current:
        if current.data == key:
            return True
        current = current.next
    return False

# Example usage
head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(4)

key = 3
if searchKey(head, key):
    print("true")
else:
    print("false")
