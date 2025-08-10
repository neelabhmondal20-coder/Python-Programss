class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def insert_sorted_circular(head, data):
    new_node = Node(data)

    # Case 1: Empty list (though constraints say at least 2 nodes)
    if not head:
        new_node.next = new_node
        return new_node

    current = head

    # Case 2: Insert before head (smallest element) or after tail (largest element)
    if data <= head.data:
        # Find last node to maintain circularity
        while current.next != head:
            current = current.next
        current.next = new_node
        new_node.next = head
        return new_node  # New node_
