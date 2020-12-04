#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Instruction.hpp"

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
