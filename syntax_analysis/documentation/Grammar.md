# Grammar

## Assignment

This can go a couple of different ways:

- TERM ASSIGN TERM (x = a)
- TYPE TERM ASSIGN TERM (int x = a)
- TERM ASSIGN TERM OPERATOR TERM (x = a + b)
- TERM ASSIGN LPAREN TERM OPERATOR TERM RPAREN (x = (a + b)) &larr; this can be defined recursively as we don't know how deep the parentheses can go
- TERM ASSIGN LPAREN TERM OPERATOR TERM RPAREN OPERATOR TERM (x = (a + b) + c) &larr; this can be defined recursively as we don't know how deep the parentheses can go and how many terms precede the encapsulated group

## Arithmetic Computation

- TERM OPERATOR TERM (a + b)
    * Let A = TERM OPERATOR TERM
    * `(?P<operand>\w+\s*)(?P<operator>\+|\-\|\/)?` would be the defined regular expression to get an arbitrary amount of operators and operands
