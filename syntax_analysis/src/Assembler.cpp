#include "../includes/Assembler.hpp"

Assembler::Assembler(){
  this->instructions = std::vector<Instruction>();
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

void Assembler::push(Instruction instruction){
  this->instructions.push_back(instruction);
}

std::ostream& operator<<(std::ostream& out, const Assembler& assembler){
  for(auto instruction : assembler.instructions){
    out << instruction;
  }

  return out;
}
