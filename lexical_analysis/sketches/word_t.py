#!/usr/bin/env python3.8

import re

class MessageException(Exception):
    def __init__(self, message):
        if not (isinstance(message, str)):
            raise ValueError
        self.message = message

class LexingError(MessageException):
    def __init__(self, message):
        super().__init__(message)

# assume string ignores whitespace

filters = {
    "COMMENT": re.compile("(^\!.*\!)"),
    # "SEPARATORS": re.compile("(?!\s+)(\W+)"),
    "IDENTIFIER": re.compile("(\w+)(?!,?\s+\w+)*"),
    "KEYWORD": re.compile("(int|float|bool|true|false|(end)?if|else|then|while(end)?|do(end)?|for(end)?|(in|out)put|and|or|not)"),
    "OPERATORS": re.compile("(\+|-|\*|\/|=|>|<|>=|<=|&+|\|+|%|!|\^)")
}

class Lexeme():
    def __init__(self, tag: str, line_number: int, regex_match):
        self.line_number = line_number
        self.begin, self.end = regex_match.span()
        self.tag = tag
    def packed_repr(self):
        return (self.line_number, self.begin, self.end)

    def __repr__(self):
        return f"""
Line NO: {self.line_number}
Span: ({self.begin}, {self.end})
Identifier: {self.tag}
"""

with open("../inputs/source.txt", "r") as fp:
    contents = fp.readlines()

collection = []

max_passes = len(list(filters.keys()))

def parseLine(string: str, lineno: int):
    counter = 0
    while(string and counter < max_passes):
        for expression in filters:
            match = filters[expression].match(string)

            if(match):
                x, y = match.span()
                string = re.sub(match.group(), '', string)
                collection.append(Lexeme(expression, lineno, match))
            else:
                counter+=1
    print(string)
    # if(string):
        # raise LexingError(f'String \"{string}\" still contains expressions that could not be identified')

for x, line in enumerate(contents):
    parseLine(line.strip(), x)
for element in collection:
    print(element)
    lineno, begin, end = element.packed_repr()
    print(f'Substring: {contents[lineno][begin:end]}')

