class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.top = None

    def push(self, x):
        new_node = Node(x)
        new_node.next = self.top
        self.top = new_node

    def pop(self):
        if self.top is None:
            return -1
        popped_value = self.top.data
        self.top = self.top.next
        return popped_value

# Function to process the input queries
def process_queries(queries):
    stack = Stack()
    output = []
    
    for query in queries:
        if query[0] == 1:  # Push operation
            stack.push(query[1])
        elif query[0] == 2:  # Pop operation
            output.append(stack.pop())
    
    return output

# Example usage
input_queries_1 = [[1, 2], [1, 3], [2], [1, 4], [2]]
output_1 = process_queries(input_queries_1)
print(output_1)  # Output: [3, 4]

input_queries_2 = [[2], [1, 4], [1, 5], [2]]
output_2 = process_queries(input_queries_2)
print(output_2)  # Output: [-1, 5]
