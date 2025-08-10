# Node class for linked list
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


# Reverse a linked list
def reverseLinkedList(head):
    prev = None
    curr = head
    while curr:
        next_node = curr.next
        curr.next = prev
        prev = curr
        curr = next_node
    return prev


# Function to add two numbers represented by linked lists
def addTwoLists(head1, head2):
    # Reverse both lists to start addition from least significant digit
    head1 = reverseLinkedList(head1)
    head2 = reverseLinkedList(head2)

    carry = 0
    dummy = Node(0)
    curr = dummy

    # Add corresponding digits
    while head1 or head2 or carry:
        val1 = head1.data if head1 else 0
        val2 = head2.data if head2 else 0

        total = val1 + val2 + carry
        carry = total // 10
        curr.next = Node(total % 10)
        curr = curr.next

        if head1:
            head1 = head1.next
        if head2:
            head2 = head2.next

    # Reverse result back
    result = reverseLinkedList(dummy.next)

    # Remove leading zeros (except if result is 0)
    while result and result.data == 0 and result.next:
        result = result.next

    return result


# Helper function to create linked list from list
def createL
