#include <iostream>
#include <string>
#include <re>
#include <map>


std::map<std::string, std::regex> tokenMap = {
  {"COMMENT", std::regex("(\\!.*\\!)")},
  {"IDENTIFIER", std::regex("(^[a-zA-Z].*\\$?\\;?)")},
  {"KEYWORD", std::regex("(int|float|bool|true|false|(end)?if|else|then|while(end)?|do(end)?|for(end)?|(in|out)put|and|or|not)")},
  {"SEPARATORS", std::regex("(((\\(|\\)|\\[|\\]|\\{|\\}|\\'|\"){1})|(\\s+))")},
  {"OPERATORS", std::regex("(\\+|-|\\*|\\/|=|>|<|>=|<=|&+|\\|+|%|^!$|\\^)")}
};

void parseLine(std::string line, int lineno){
  int counter = 0;
  int max_passes = 5;
  while(string && counter < max_passes){
    for(auto expression : map)
  }
}
