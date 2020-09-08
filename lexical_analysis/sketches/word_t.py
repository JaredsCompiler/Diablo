#!/usr/bin/env python3.8

import re

# assume string ignores whitespace

filters = {
    "COMMENT": re.compile("(^\!.*\!)"),
    "SEPARATORS": re.compile("(?!\s+)(\W+)"),
    "IDENTIFIER": re.compile("(\w+)(?!,?\s+\w+)*"),
    "KEYWORD": re.compile("(int|float|bool|true|false|(end)?if|else|then|while(end)?|do(end)?|for(end)?|(in|out)put|and|or|not)"),
    "OPERATORS": re.compile("(\+|-|\*|\/|=|>|<|>=|<=|&+|\|+|%|!|\^)")
}

class Lexeme():
    def __init__(self, tag: str, line_number: int, regex_match):
        self.line_number = line_number
        self.begin, self.end = regex_match.span()
        self.tag = tag

    def __repr__(self):
        return f"""
Line NO: {self.line_number}
Span: ({self.begin}, {self.end})
Identifier: {self.tag}
"""

with open("../inputs/source.txt", "r") as fp:
    contents = fp.readlines()

collection = []
for x, line in enumerate(contents):
    for expression in filters:
        match = filters[expression].match(line)

        if(match):
            collection.append(Lexeme(expression, x, match))
            if(expression == "COMMENT"):
                break

for element in collection:
    print(element)
    l, s, e = element.line_number, element.begin, element.end
    string = contents[l][s:e].replace(" ", "\s").replace("\n", "\\n").strip()
    print(string)
