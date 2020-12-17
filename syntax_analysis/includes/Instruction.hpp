#pragma once

#include <iostream>
#include <string>

class Instruction {
  public:
    Instruction();  // empty bones
    Instruction(std::string, int, int); // content
    Instruction(std::string, int); // no content

    friend std::ostream& operator<<(std::ostream& out, const Instruction& instruction);
    std::string getOperator();

    void updateQuantity(int);
    void updateOperator(std::string);

  private:
    std::string operator_;
    int quantifier;
    int position;
};
