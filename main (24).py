# Node class for doubly linked list
class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


def deleteNodeAtPosition(head, x):
    # If list is empty
    if not head:
        return None

    # If deleting the head node
    if x == 1:
        new_head = head.next
        if new_head:
            new_head.prev = None
        return new_head

    curr = head
    count = 1

    # Traverse to the node at position x
    while curr and count < x:
        curr = curr.next
        count += 1

    # If position is invalid
    if not curr:
        return head

    # Adjust pointers to delete the node
    if curr.next:
        curr.next.prev = curr.prev
    if curr.prev:
        curr.prev.next = curr.next

    return head


# Helper function to create a doubly linked list from list
def createDoublyLinkedList(values):
    if not values:
        return None
    head = Node(values[0])
    curr = head
    for val in values[1:]:
        new_node = Node(val)
        curr.next = new_node
        new_node.prev = curr
        curr = new_node
    return head


# Helper function to print a doubly linked list
def printDoublyLinkedList(head):
    curr = head
    while curr:
        print(curr.data, end=" ")
        curr = curr.next
    print()


# Example usage
head = createDoublyLinkedList([1, 5, 2, 9])
head = deleteNodeAtPosition(head, 1)
printDoublyLinkedList(head)  # Output: 5 2 9

head = createDoublyLinkedList([1, 3, 4])
head = deleteNodeAtPosition(head, 3)
printDoublyLinkedList(head)  # Output: 1 3
