#include <iostream>
#include <string>
#include <limits>
#include <map>

class Symbol {
  public:
    Symbol();
    Symbol(std::string, std::string, long long int);

    bool typeDeclared();
    bool typeMismatch();

    long long int value_();
    std::string type_();
    std::string name_();
    unsigned long long int location_();

    void setLocation(unsigned long long int);

    private:
      std::string type;
      std::string name;
      long long int value;
      bool typeIsDelcared;
      unsigned long long int location;

};

Symbol::Symbol(){
  this->type = "<EMPTY>";
  this->name = "<EMPTY>";
  this->value = std::numeric_limits<long long int>::infinity();
  this->typeIsDelcared = false;
  this->location = 0;
}

Symbol::Symbol(std::string type, std::string name, long long int value){
  this->type = type;
  this->name = name;
  this->value = value;
  this->typeIsDelcared = true;
  this->location = 0;
}

bool Symbol::typeDeclared(){ return this->typeIsDelcared; }

bool Symbol::typeMismatch(){
  bool a = (this->type == "bool" && (this->value == 0 || this->value == 1)); // is it a boolean?
  bool b = (this->type == "int" && (this->value != std::numeric_limits<long long int>::infinity())); // is it a valid number, given it's an int?
  bool f = (a || b) && (this->typeIsDelcared);

  return (f) ? false : true; // if the condition is true, then there is no type mismatch, else false
}

long long int Symbol::value_(){ return this->value; }
std::string Symbol::type_(){ return this->type; }
std::string Symbol::name_(){ return this->name; }
unsigned long long int Symbol::location_(){ return this->location; }

void Symbol::setLocation(unsigned long long int loc){
  this->location = loc;
  std::cout << this->location << std::endl;
}


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

int main(){
  Symbol s = Symbol("int", "value", 24);
  SymbolTable table = SymbolTable();
  if(!s.typeMismatch()){
    table.insert("value", s);
    std::cout << "inserted " << s.name_() << " with value of " << s.value_() << " at the location of " << s.location_() << std::endl;
  } else {
    std::cout << "could not insert, there was a type mismatch from " << s.type_() << " to value of " << s.value_() << std::endl;
  }
  return 0;
}
