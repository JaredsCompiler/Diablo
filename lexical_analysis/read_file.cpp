#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// This program is just simply reading a file line by line into a std::vector

int main(){
  std::ifstream sourceFile;
  std::vector<std::string> content;

  sourceFile.open("./source.c");
  if(!sourceFile.is_open()){
    std::cerr << "file cannot be opened" << std::endl;
  }
  for(std::string line; getline(sourceFile, line);){
    content.push_back(line);
  }
  for(auto line : content){
    std::cout << line << std::endl;
  }
  return 0;
}
