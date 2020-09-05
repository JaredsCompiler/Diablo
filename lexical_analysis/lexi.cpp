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
    "Copyright (C) 2020 Free Software Foundation, Inc.\n"
    "License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>."
    "This is free software: you are free to change and redistribute it.\n"
    "There is NO WARRANTY, to the extent permitted by law.\n"
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
  auto f = sourceFile("source.txt");
  auto contents = f.get_content();
  std::vector<std::string>::iterator begin = contents.begin();
  std::vector<std::string>::iterator end = contents.end();
  auto rules = lexerRules(tokenMap);

  auto lex = lexer(rules, f, begin, end);
  
  std::vector<lexeme> lexeme_collection;

  for(auto i = lex.get_begin(); i != lex.get_end(); ++i){
    for(auto& identifier : tokenMap){
      auto match = lex.span(*i, identifier.second);
      for(auto tup : match){
        auto position = (i - lex.get_begin());
        const auto[alpha,omega] = tup;
        lexeme_collection.emplace_back(lexeme(position, alpha, omega, lex.get_begin(), identifier.first));
      }
    }
  }

  for(auto element : lexeme_collection){
    std::cout << element << std::endl;
  }

  return 0;
}
