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
  //{"KEYWORD", std::regex("(int|float|bool|true|false|(end)?if|else|then|while(end)?|do(end)?|for(end)?|(in|out)put|and|or|not)")},
  {"KEYWORD", std::regex("(int)")},
  {"IDENTIFIER", std::regex("(\\w+)")},
  //{"IDENTIFIER", std::regex("(?!\\s+)([a-zA-Z]+)")},
  {"SEPARATORS", std::regex("^(\\(|\\)|\\{|\\}|\\[|\\]|\"|\'|\\,)$")},
  {"OPERATORS", std::regex("(\\+|-|\\*|\\/|=|>|<|>=|<=|&+|\\|+|%|^!$|\\^)")}
};

int main(int argc, const char* argv[]){
  sourceFile source = sourceFile("inputs/2_lines.txt");
  lexerRules rules = lexerRules(tokenMap);

  lexer lex = lexer(rules, source);
  lex.processFile();
  
  printf("TOKENS\t\tLexemes\n\n");

  std::cout << "amount of tokens: " << lex.get_tokens().size() << std::endl;


  for(auto element : lex.get_tokens()){
    std::cout << element.get_tag() << "\t\t" << element.get_substring() << std::endl;
  }

  return 0;
}
