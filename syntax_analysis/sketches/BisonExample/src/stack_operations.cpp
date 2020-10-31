#include <string>
#include <limits>
#include <map>
#include <iostream>

#include "../includes/stack_operations.hpp"

uint64_t get_variable(std::map<std::string, uint64_t> container, std::string term){
  for (auto it = container.begin(); it != container.end(); ++it){
    if (it->first == term){
      return it->second;
    }
  }
  return std::numeric_limits<uint64_t>::infinity();
}

void peetr(){
  std::cout << "h" << std::endl;
}
