// STL
#include <fstream>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string>
#include <vector>
#include <regex>
#include <stack>
#include <sstream>
#include <limits>

// Lexi

#include "../lexical_analysis/includes/reader.hpp"
#include "../lexical_analysis/includes/lexer_rules.hpp"
#include "../lexical_analysis/includes/lexer.hpp"

// Synthetic

#include "includes/balancer.hpp"

// EzAquarii (attempting to phase out as much as possible)

#include "includes/scanner.h"
#include "src/parser.hpp"
#include "includes/interpreter.h"

std::map<std::string, std::regex> tokenMap = {
  {"COMMENT", std::regex("(\\!.*\\!)")},
  {"KEYWORD", std::regex("(int|float|bool|true|false|(end)?if|else|then|while(end)?|do(end)?|for(end)?|(in|out)put|and|or|not)")},
  {"IDENTIFIER", std::regex("(\\w+)")},
  {"SEPARATORS", std::regex("(\\(|\\)|\\{|\\}|\\[|\\]|\"|\'|\\,)")},
  {"ASSIGNMENT", std::regex("(\\={1})")},
  {"OPERATORS", std::regex("(\\+|-|\\*|\\/|>|<|>=|<=|&+|\\|+|%|^!$|\\^)")},
  {"TERMINATORS", std::regex("(\\;|\\$)")}
};

std::map<lexeme, double> symbolTable = {

};

bool isFloat(std::string input){
  std::istringstream iss(input);
  double f;
  iss >> std::noskipws >> f;
  return iss.eof() && !iss.fail();
}


int main(){
  sourceFile src("inputs/assignment.le");
  EzAquarii::Interpreter interpreter;

  EzAquarii::Parser::symbol_type example_element = EzAquarii::Parser::make_ID("HelloWorld", EzAquarii::location()); 
  return 0;

  // check if the is even balanced before getting lexemes
  balancer B;
  const auto[state, line, lineno] = B.is_file_balanced(src);
  if(!state){
    std::cerr << "[-] File " << src.get_path() << " is not balanced" << std::endl;
    std::cerr << lineno << ": " << line << std::endl;
    return 1;
  } else {
    return 0;
  }

  lexerRules rules = lexerRules(tokenMap);

  lexer lex = lexer(rules, src);
  lex.processFile();

  /*
   * Since we have to do processing here again, it's O(n), where n is the amount of lexemes
   * Un-needed processing can be achieved if Lexi was changed but that is beyond the scope of the requirements
  */

  for(auto token : lex.get_tokens()){
    std::string tag = token.get_tag();
    std::string content = token.get_substring();

    if(tag == "IDENTIFIER"){
      
    }
  }

  return 0;
}
