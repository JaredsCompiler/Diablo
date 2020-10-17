#include "../includes/variable.hpp"

template <class T>

//template<typename Base, typename X>

variable<T>::variable(lexeme lex, T type){
  this->lex = lex;
  this->type = type;
}

//inline bool variable::instanceof(const X*){
   //return is_base_of<Base, X>::value;
//}
