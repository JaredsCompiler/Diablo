#include "../includes/balancer.hpp"
#include <stack>
#include <string>

bool balancer::is_matching(char a, char b){
  return ((a == '{' && b == '}') ||
         (a == '(' && b == ')') ||
         (a == '[' && b == ']') ||
         ((a == '\'' || a == '\"') && a == b)) ? true : false;

}

bool balancer::is_valid(char c){
  std::string list = "{([\'\"])}";
  for(char k : list){
    if(c == k){ return true; }
  }
  return false;
}

bool balancer::is_balanced(std::string line){
  int i = 0;
  int quote_counter = 0;
  char c = '\0';
  
  std::stack<char> st_;

  while(line[i]){
    c = line[i];
    if(c == '(' || c == '{' || c == '[' || c == '\'' || c == '\"'){
      st_.push(c);
    }
    if(c == ')' || c == '}' || c == ']' || c == '\'' || c == '\"'){
      if(c == '\'' || c == '\"'){ ++quote_counter; }
      if(st_.empty()){ return false; }

      if(!is_matching(st_.top(), c)){ return false; }
      st_.pop();
    }
    ++i;
  }
  if((quote_counter % 2 != 0)){ return false; }
  else if(st_.empty()){ return true; }
  return false;
}

//bool balancer::is_file_balanced(sourceFile src){
  //for(auto line : src.get_content()){
    //if(!is_balanced(line)){ return false; } 
  //}
  //return true;
//}

std::tuple<bool, std::string, int> balancer::is_file_balanced(sourceFile src){
  std::vector<std::string> contents = src.get_content();
  for(int i = 0; i < contents.size(); ++i){
    if(!is_balanced(contents[i])){
      return std::make_tuple(false, contents[i], i);
    }
  }
  return std::make_tuple(true, "", -1);
}
