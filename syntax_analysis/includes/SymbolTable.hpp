#pragma once
#include <map>
#include <string>
#include "Symbol.hpp"

class SymbolTable {
  public:
    SymbolTable();
    
    void insert(std::string, Symbol&);
    Symbol obtain(std::string);

  private:
    std::map<std::string, Symbol> map;
    long long int currentAddress;
    long long int baseAddress;
};
