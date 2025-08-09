def infix_to_postfix(expression):
    precedence = {'+': 1, '-': 1, '*': 2, '/': 2, '^': 3}
    output = []
    stack = []
    
    for char in expression:
        if char.isalnum():  # If the character is an operand (a-z, A-Z, 0-9)
            output.append(char)
        elif char == '(':  # If the character is '(', push it to the stack
            stack.append(char)
        elif char == ')':  # If the character is ')', pop from stack to output until '(' is found
            while stack and stack[-1] != '(':
                output.append(stack.pop())
            stack.pop()  # Pop the '(' from the stack
        else:  # The character is an operator
            while (stack and stack[-1] != '(' and
                   precedence[char] <= precedence[stack[-1]]):
                output.append(stack.pop())
            stack.append(char)

    # Pop all the operators from the stack
    while stack:
        output.append(stack.pop())

    return ''.join(output)

# Example usage
infix_expression1 = "a+b*(c^d-e)^(f+g*h)-i"
print("Postfix Expression:", infix_to_postfix(infix_expression1))

infix_expression2 = "A*(B+C)/D"
print("Postfix Expression:", infix_to_postfix(infix_expression2))

infix_expression3 = "(a+b)*(c+d)"
print("Postfix Expression:", infix_to_postfix(infix_expression3))
