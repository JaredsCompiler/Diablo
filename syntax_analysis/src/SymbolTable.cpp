#include "../includes/SymbolTable.hpp"

SymbolTable::SymbolTable(){
  this->map = std::map<std::string, Symbol>();
  this->currentAddress = 0;
  this->baseAddress = 5000; // we will assume that our symbol table lives in the memory space spanning from 5000 to inf
}

void SymbolTable::insert(std::string pattern, Symbol& symbol){
  symbol.setLocation(this->baseAddress + this->currentAddress);
  this->map[pattern] = symbol;
  this->currentAddress+=4;
}

Symbol SymbolTable::obtain(std::string pattern){
  for (auto it = this->map.begin(); it != map.end(); ++it){
    if (it->first == pattern){ return it->second; }
  }
  // not found
  return Symbol();

}
