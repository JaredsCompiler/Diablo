#!/usr/bin/env python3.8

import re

symbolTable = {
    "a": 1,
    "b": 2,
    "c": 3
}

class Lexeme:
    def __init__(self, content, tag, lookup=None):
        self.content = content
        self.tag = tag
        self.lookup = lookup


# lexical analysis process, condensed for simplicity
string = "a + b + c"
operator_re = re.compile("\+|\-")
operand_re = re.compile("\w+")
container = string.split()


operators, operands = [], []

for c in container:
    if(operator_re.match(c)):
        operators.append(Lexeme(c, "OPERATOR"))
    elif(operand_re.match(c)):
        try:
            operands.append(Lexeme(c, "IDENTIFIER", symbolTable[c]))
        except KeyError:
            print(f'{c} has not been defined in the symbol table')
            quit()



a, b, op = operands.pop(), operands.pop(), operators.pop()
print(eval(f'{a.lookup} {op.content} {b.lookup}'))
# print(operators.pop(), operands.pop())
