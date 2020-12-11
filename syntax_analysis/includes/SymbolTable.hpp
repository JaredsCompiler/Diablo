#pragma once
#include <map>
#include <string>
#include "Symbol.hpp"

class SymbolTable {
  public:
    SymbolTable();
    
    void insert(Symbol&);
    Symbol obtain(std::string);

    friend std::ostream& operator<<(std::ostream& out, const SymbolTable& symbolTable);
    long long int sizeOfSymbol(Symbol);

  private:
    std::map<std::string, Symbol> map;
    long long int currentAddress;
    long long int baseAddress;
};
