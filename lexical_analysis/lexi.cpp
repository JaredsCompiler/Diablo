#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>

#include "includes/reader.hpp"
#include "includes/lexer_rules.hpp"
#include "includes/lexer.hpp"
#include "includes/lexeme.hpp"

const char* AUTHORS[] = {
  "Jared Dyreson",
  "Chris Nutter"
};

const char* INSTITUTION = "California State University Fullerton";

void print_version(){
  printf(
    "lexi (%s) 1.0\n"
    "Copyright (C) 2020 Comrade Software Foundation, Inc.\n"
    "MIT License"
    "This is free software, and provided as is without warranty\n"
    "Written by %s and %s\n",
  INSTITUTION, AUTHORS[0], AUTHORS[1]); 
}

std::map<std::string, std::regex> tokenMap = {
  {"COMMENT", std::regex("(\\!.*\\!)")},
  {"IDENTIFIER", std::regex("(^[a-zA-Z].*\\$?\\;?)")},
  {"KEYWORD", std::regex("(int|float|bool|true|false|(end)?if|else|then|while(end)?|do(end)?|for(end)?|(in|out)put|and|or|not)")},
  {"SEPARATORS", std::regex("((\\'|\\(|\\)|\\{|\\}|\\[|\\]|\\,|\\.|\\:|\\;|\\s)+)")},
  {"OPERATORS", std::regex("(\\*|\\+|\\-|\\=|\\/|\\>|\\<|\\%)")}
};

int main(int argc, const char* argv[]){
  sourceFile source = sourceFile("inputs/source.txt");
  lexerRules rules = lexerRules(tokenMap);

  lexer lex = lexer(rules, source);
  lex.processFile();

  for(auto element : lex.get_tokens()){
    std::cout << element << std::endl;
  }

  return 0;
}
