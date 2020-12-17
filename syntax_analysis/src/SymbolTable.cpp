#include "../includes/SymbolTable.hpp"

SymbolTable::SymbolTable(){
  this->map = std::map<std::string, Symbol>();
  this->currentAddress = 0;
  this->baseAddress = 5000; // we will assume that our symbol table lives in the memory space spanning from 5000 to inf
}

void SymbolTable::insert(Symbol& symbol, bool update_mem){
  symbol.setLocation(this->baseAddress + this->currentAddress);
  this->map[symbol.name_()] = symbol;
  if(update_mem){
    this->currentAddress+=4;
  }
}

Symbol SymbolTable::obtain(std::string pattern){
  for (auto it = this->map.begin(); it != map.end(); ++it){
    if (it->first == pattern){ return it->second; }
  }
  // not found
  return Symbol();

}


std::ostream& operator<<(std::ostream& out, const SymbolTable& symbolTable){
  out << "Identifier\t" << "Memory Location\t\t" << "Type\t\t" << "Value\n";
  for(auto symbol : symbolTable.map){
    out << symbol.first << "\t\t\t" << symbol.second.location_() << "\t\t" << symbol.second.type_() << "\t\t" << symbol.second.value_() <<  "\n";
  }

  return out;
}

long long int SymbolTable::sizeOfSymbol(Symbol s){
  std::string label = s.type_();
  if(label == "int"){ return 4; }
  if(label == "bool"){ return 1; }
}
