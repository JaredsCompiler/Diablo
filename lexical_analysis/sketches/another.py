#!/usr/bin/env python3.8

import re

test_list = ["(^\!.*\!)", "(\w+)"]

filters = {
    "COMMENT": re.compile(""),
    # "SEPARATORS": re.compile("(?!\s+)(\W+)"),
    "IDENTIFIER": re.compile("(\w+)"),
    "KEYWORD": re.compile("(int|float|bool|true|false|(end)?if|else|then|while(end)?|do(end)?|for(end)?|(in|out)put|and|or|not)"),
    "OPERATORS": re.compile("(\+|-|\*|\/|=|>|<|>=|<=|&+|\|+|%|!|\^)")
}

temp = '(?:% s)' % '|'.join(test_list) 
test_str = "int match"
match = re.findall(temp, test_str)
print(temp)
for m in match:
    print(m)
if(match):
    print(match)

