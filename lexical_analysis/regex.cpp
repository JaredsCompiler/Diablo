#include <iostream>
#include <regex>

// Brackets, braces or parenthesis regex -> ((\(|\))|(\{|\})|(\[|\]))
// Comments regex -> (\!.*\!)
// assignment regex -> (\w+\s+\=\s+\w+\$\;?)
// good god does importing the regex module cause insane compile times
// it appears that C++ uses the ECMA engine which can be accessed on regex 101 using ECMAScript (which might or might not work)

int main(){
  std::map<std::string, std::regex> tokenMap = {
    {"COMMENT", std::regex("(\\!.*\\!)")},
    {"IDENTIFIER", std::regex("(^[a-zA-Z].*\\$?\\;?)")},
    {"KEYWORD", std::regex("(int|float|bool|true|false|(end)?if|else|then|while(end)?|do(end)?|for(end)?|(in|out)put|and|or|not)")},
    {"SEPARATORS", std::regex("((\\'|\\(|\\)|\\{|\\}|\\[|\\]|\\,|\\.|\\:|\\;|\\s)+)")},
    {"OPERATORS", std::regex("(\\*|\\+|\\-|\\=|\\/|\\>|\\<|\\%)")}
  };
  return 0;
}
