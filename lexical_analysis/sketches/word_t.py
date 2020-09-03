#!/usr/bin/env python3.8

import re

# assume string ignores whitespace

filters = {
    "COMMENT": re.compile("(^\!.*\!)")
}

class Lexeme():
    def __init__(self, tag: str, line_number: int, regex_match):
        self.line_number = line_number
        self.begin, self.end = regex_match.span()
        self.tag = tag

    def __repr__(self):
        return f"""
Line NO: {self.line_number}
Begin: {self.begin}
End: {self.end}
Odd coordinates: content[{self.line_number}][({self.begin}, {self.end})]"""

with open("source.txt", "r") as fp:
    contents = fp.readlines()

collection = []
for x, line in enumerate(contents):
    for expression in filters:
        match = filters[expression].match(line)
        if(match and expression != "COMMENT"):
            collection.append(Lexeme(expression, x, match))

for element in collection:
    l, s, e = element.line_number, element.begin, element.end
    print(contents[l][s:e])
