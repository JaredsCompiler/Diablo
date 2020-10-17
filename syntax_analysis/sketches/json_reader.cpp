#include <iostream>
#include <string>

std::string make_space(int size){
  std::string s;
  for(int i = 0; i < size; ++i){ s+=' '; }
  return s;
}

void find_replace(std::string* line, std::string substring){
  size_t index = 0;
  while(true){
    index = line->find(substring, index);
    if(index == std::string::npos){ break; }
    line->replace(index, substring.size(), std::string(substring.size(), ' '));
    index+=substring.size();
  }
}
int main(){
  std::string str("abcxyz");
  find_replace(&str, "abc");
  std::cout << str << std::endl;
  return 0;
}
