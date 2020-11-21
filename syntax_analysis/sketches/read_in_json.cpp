#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <regex>

int main(){
  std::ifstream ifile("regexes.json");
  std::regex grabber("(\\\"(.*)\\\")");
  std::string identifier;
  std::string regex_;

  for(std::string line; getline(ifile, line);){
    std::istringstream iss(line);
    iss >> identifier >> regex_;

    auto it = std::sregex_iterator(identifier.begin(), identifier.end(), grabber);
    std::smatch sm = *it;
    std::cout << sm.str(1) << std::endl;
    //std::cout << identifier << std::endl;
    //std::cout << regex_ << std::endl;
  }
}
