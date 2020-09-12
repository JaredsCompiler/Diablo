#include <iostream>
#include "../lexical_analysis/includes/reader.hpp"

int main(){
  sourceFile src("sin.cpp");
  for(auto line : src.get_content()){
    std::cout << line << std::endl;
  }
  return 0;
}
