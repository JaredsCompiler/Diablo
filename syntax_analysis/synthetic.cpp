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

#include "includes/variable.hpp"
#include "includes/balancer.hpp"

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

double get_variable(std::map<lexeme, double> aMap, lexeme l1){
  for (auto it = aMap.begin(); it != aMap.end(); ++it){
    if (it->first == l1){
      return it->second;
    }
  }
  return std::numeric_limits<double>::infinity();
}

int main(){
  std::stack<lexeme> operands;
  std::stack<lexeme> operators;
  sourceFile src("inputs/assignment.le");

  // check if the is even balanced before getting lexemes
  balancer B;
  const auto[state, line, lineno] = B.is_file_balanced(src);
  if(!state){
    std::cerr << "File is not balanced" << std::endl;
    std::cerr << lineno << ": " << line << std::endl;
    return 1;
  }

  lexerRules rules = lexerRules(tokenMap);

  lexer lex = lexer(rules, src);
  lex.processFile();

  for(auto token : lex.get_tokens()){
    std::string tag = token.get_tag();
    if(tag == "IDENTIFIER" || tag == "NUMBER"){
      operands.push(token);
    } else if(tag == "OPERATOR" || tag == "ASSIGNMENT"){
      operators.push(token);
    }
  }

  // TODO
  //while(!operands.empty() && !operands.empty()){
    //lexeme op1 = operands.top();
    //operands.pop();
    //lexeme op2 = operands.top();
    //operands.pop();

    //lexeme operator_ = operators.top();
    //operators.pop();

    //if(operator_.get_tag() == "ASSIGNMENT"){
      //std::string substring = op1.get_substring();
      //if(isFloat(substring)){
        //symbolTable[op2] = std::stod(substring);
      //}
    //}
  //}

  //for(auto element : symbolTable){
    //lexeme token = element.first;
    //double value = element.second;
    //std::cout << token.get_substring() << " -> " << value << std::endl;
  //}
  return 0;
}
