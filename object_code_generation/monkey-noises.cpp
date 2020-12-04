#include <iostream>
#include <limits>
#include <string>
#include <vector>

namespace Seminal {

  class Instruction {
    public:
      Instruction();
      Instruction(std::string, int, int);
      friend std::ostream& operator<<(std::ostream& out, const Instruction& instruction);

    private:
      std::string operator_;
      int quantifier;
      int position;
  };

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

  //////////////////////////////////////////////////

  class Assembler {
    public:
      Assembler();
      Instruction pop();
      Instruction peek();

      void push(Instruction);

      friend std::ostream& operator<<(std::ostream& out, const Assembler& assembler);
    private:
      std::vector<Instruction> instructions;
  };

  /*
   * Constructor
  */

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

};

int main(){
  Seminal::Assembler ass = Seminal::Assembler();
  Seminal::Instruction instr = Seminal::Instruction();
  ass.push(instr);
  std::cout << instr << std::endl;
  std::cout << ass << std::endl;
  return 0;
}
