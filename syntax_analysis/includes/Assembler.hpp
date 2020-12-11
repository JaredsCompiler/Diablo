#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "Instruction.hpp"
#include "maths.hpp"

class Assembler {
  public:
    Assembler();
    Instruction pop();
    Instruction peek();

    void push(Instruction);
    std::string getInstruction(std::string);

    friend std::ostream& operator<<(std::ostream& out, const Assembler& assembler);

  private:
    std::vector<Instruction> instructions;
};
