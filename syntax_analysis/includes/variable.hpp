#pragma once

#include "../../lexical_analysis/includes/lexeme.hpp"

template <class T>

class variable {
  private:
    lexeme lex;

    //template<typename Base, typename X>

    T type;
  public:
    variable(lexeme, T);
    // https://www.tutorialspoint.com/cplusplus-equivalent-of-instanceof
    //inline bool instanceof(const X*);
};
