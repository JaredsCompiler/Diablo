#include "../includes/Instruction.hpp"
#include <limits>

Instruction::Instruction(){
  this->operator_ = "<EMPTY>";
  this->quantifier = std::numeric_limits<int>::infinity();
  this->position = std::numeric_limits<int>::infinity();
}

Instruction::Instruction(std::string s, int l, int p){
  this->operator_ = s;
  this->quantifier =  l;
  this->position = p;

  /*
   * 1 PUSHI 0
   * 1 <- position
   * PUSHI <- operator_
   * 0 <- quantifier
  */

}

Instruction::Instruction(std::string s, int p){
  this->operator_ = s;
  this->position = p;
  this->quantifier = std::numeric_limits<int>::infinity();
}

std::ostream& operator<<(std::ostream& out, const Instruction& instruction){
  std::string q_ = (instruction.quantifier == std::numeric_limits<int>::infinity() && instruction.quantifier != 0) ? std::string(" ") : std::to_string(instruction.quantifier);
  out << instruction.operator_ << "\t" << q_;

  return out;
}

std::string Instruction::getOperator(){
  return this->operator_;
}

void Instruction::updateQuantity(int val){
  this->quantifier = val;
}

void Instruction::updateOperator(std::string s){
  this->operator_ = s;
}

