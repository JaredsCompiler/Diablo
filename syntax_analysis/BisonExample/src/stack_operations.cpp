#include <string>
#include <limits>
#include <map>
#include <iostream>

#include "../includes/stack_operations.hpp"

double get_variable(std::map<std::string, double> container, std::string term){
  for (auto it = container.begin(); it != container.end(); ++it){
    if (it->first == term){
      return it->second;
    }
  }
  return std::numeric_limits<double>::infinity();
}

void peetr(){
  std::cout << "h" << std::endl;
}
