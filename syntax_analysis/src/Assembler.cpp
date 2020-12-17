#include "../includes/Assembler.hpp"

Assembler::Assembler(){
  this->instructions = std::vector<Instruction>();
  this->location = 0;
}

/*
 * Manipulation
*/

 Instruction Assembler::pop(){
 Instruction instruction = this->instructions.back();
 this->instructions.pop_back();
 return instruction;
}

Instruction Assembler::peek() {
  return this->instructions.back();
}

size_t Assembler::location_(){
  return this->location;
}

void Assembler::updateLocation(int pos){
  this->location = pos;
}

void Assembler::push(Instruction instruction){
  this->instructions.push_back(instruction);
}

bool Assembler::shouldDispenseInstruction(){
  return this->_should_dispense;
}

void Assembler::setDispense(bool fl){
  this->_should_dispense = fl;
}

std::ostream& operator<<(std::ostream& out, const Assembler& assembler){
  for(size_t i = 0; i < assembler.instructions.size(); ++i){
    out << i << " " << assembler.instructions[i] << std::endl;
  }

  return out;
}

std::string Assembler::getInstruction(std::string str){
  arthimetic_code ac = mathHash(str);
  compare_code cc = compareHash(str);
  std::string value = "NIL";

  if(ac == eMathNotFound && cc == eCompNotFound){ return value; }

  if(ac != eMathNotFound){
    switch(ac){
      case eAdd:
        value = "ADD";
        break;
      case eSub:
        value = "SUB";
        break;
      case eMul:
        value = "MUL";
        break;
      case eDiv:
        value = "DIV";
        break;
      case eMathNotFound:
        break;
    }
  } else {
    switch(cc){
      case eGreater:
        value = "GRT";
        break;
      case eLess:
        value = "LES";
        break;
      case eGreaterEqual:
        value = "GEQ";
        break;
      case eLessEqual:
        value =  "LEQ";
        break;
      case eExplicitCompare:
        value = "EQU";
        break;
      case eExplicitCompareReverse:
        value = "NEQ";
        break;
      case eCompNotFound:
        break;
    }
  }

  return value;

}
