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

std::ostream& operator<<(std::ostream& out, const Instruction& instruction){
  out << instruction.position << "  " << instruction.operator_ << "\t" << instruction.quantifier;

  return out;
}
