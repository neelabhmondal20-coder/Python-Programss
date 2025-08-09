/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

class MyStack:
    def __init__(self):
        self.stack = []
    def push(self, x):
        self.stack.append(x)
    def pop(self):
        if not self.stack:
            return -1
        return self.stack.pop()
def process_queries(oper):
    my_stack = MyStack()
    output = []
    for i in range(len(oper)):
        if oper[i][0] == 1:  # Push operation
            my_stack.push(oper[i][1])
        elif oper[i][0] == 2:  # Pop operation
            output.append(my_stack.pop())
    return output