#pragma once

#include <iostream>
#include <string>

class Instruction {
  public:
    Instruction();
    Instruction(std::string, int, int);
    friend std::ostream& operator<<(std::ostream& out, const Instruction& instruction);
    std::string getOperator();

  private:
    std::string operator_;
    int quantifier;
    int position;
};
