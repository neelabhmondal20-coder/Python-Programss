def eval_rpn(arr):
    stack = []
    
    for token in arr:
        if token in "+-*/":
            b = stack.pop()
            a = stack.pop()
            if token == '+':
                stack.append(a + b)
            elif token == '-':
                stack.append(a - b)
            elif token == '*':
                stack.append(a * b)
            elif token == '/':
                # Perform integer division that truncates towards zero
                stack.append(int(a / b))  # Use int() to truncate towards zero
        else:
            # It's a number, push it onto the stack
            stack.append(int(token))
    
    return stack[0]

# Example usage:
arr1 = ["2", "3", "1", "*", "+", "9", "-"]
print(eval_rpn(arr1))  # Output: -4

arr2 = ["100", "200", "+", "2", "/", "5", "*", "7", "+"]
print(eval_rpn(arr2))  # Output: 757
