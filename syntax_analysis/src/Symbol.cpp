#include "../includes/Symbol.hpp"

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

bool Symbol::isDefined(){ return !(this->value == std::numeric_limits<long long int>::infinity()); }

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
}

void Symbol::setValue(unsigned long long int v){
  this->value = v;
}
