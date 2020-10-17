#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <vector>
#include <tuple>

/*
 * Make sure contents of file is balanced
 * AUTHOR: Jared Dyreson
 * TODO
 * Make this a class
*/

class balancer {
  public:
    bool is_matching(char, char);
    bool is_valid(char);
    bool is_balanced(std::string);

    bool is_file_balanced(std::vector<std::string>); // needs to be changed to sourceFile to prevent extraneous code
};

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

//bool balancer::is_file_balanced(std::vector<std::string> contents){
  //// (true, line, lineno)
  //for(auto line : contents){
    //if(!is_balanced(line)){ return false; } 
  //}
  //return true;
//}

std::tuple<bool, std::string, int> balancer::is_file_balanced(std::vector<std::string> contents){
  for(int i = 0; i < contents.size(); ++i){
    if(!is_balanced(contents[i])){
      return std::make_tuple(false, contents[i], i);
    }
  }
  return std::make_tuple(true, "", -1);
}

int main(){

  std::ifstream file;
  file.open("example.le");
  std::vector<std::string> contents;
  for(std::string line; getline(file, line);){
    contents.push_back(line);
  }
  file.close();

  balancer B;

  bool check = B.is_file_balanced(contents);
  if(!check){
    std::cout << "passed" << std::endl;
  }

  return 0;
}
