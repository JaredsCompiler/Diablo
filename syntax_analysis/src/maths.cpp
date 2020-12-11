#include <iostream>
#include <limits>
#include <stack>
#include <type_traits>
#include <string>
#include "../includes/maths.hpp"

compare_code compareHash(std::string str){
  if(str == ">"){ return eGreater; }
  if(str == "<"){ return eLess; }
  if(str == ">="){ return eGreaterEqual; }
  if(str == "<="){ return eLessEqual; }
  if(str == "=="){ return eExplicitCompare; }
  if(str == "!="){ return eExplicitCompareReverse; }
  if(str == "&&"){ return eDoubleAnd; }
  if(str == "||"){ return eDoubleOr; }
  return eCompNotFound;
}

arthimetic_code mathHash(std::string str){
  if(str == "+"){ return eAdd; }
  if(str == "-"){ return eSub; }
  if(str == "/"){ return eDiv; }
  if(str == "*"){ return eMul; }
  if(str == "%"){ return eMod; }
  if(str == "++"){ return eInc; }
  if(str == "--"){ return eDec; }
  return eMathNotFound;
}

uint64_t compute(uint64_t a, uint64_t b, std::string s){
  // set to inf
  uint64_t val = std::numeric_limits<uint64_t>::infinity();
  switch(mathHash(s)){
    case eAdd:
      val = (a + b);
      break;
    case eSub:
      val = (a - b);
      break;
    case eDiv:
      if(b == 0){ break; }
      val = (a / b);
      break;
    case eMul:
      val = (a * b);
      break;
    case eMod:
      val = (a % b);
      break;
    case eMathNotFound:
      break;
    case eInc:
    // might be broken
      val = a + 1;
      break;
    case eDec:  
      val = a - 1;
      break;
  }
  return val;

}

bool compare(uint64_t a, uint64_t b, std::string c){
  uint64_t val = std::numeric_limits<bool>::infinity();
  switch(compareHash(c)){
    case eGreater:
      val = (a > b);
      break;
    case eLess:
      val = (a < b);
      break;
    case eGreaterEqual:
      val = (a >= b);
      break;
    case eLessEqual:
      val = (a <= b);
      break;
    case eDoubleAnd:
      val = (a && b);
      break;
    case eDoubleOr:
      val = (a || b);
      break;
    case eExplicitCompare:
      val = (a == b);
      break;
    case eExplicitCompareReverse:
      val = !(a == b);
      break;
    case eCompNotFound:
      break;
  }
  return val;

}

void helloWorld(){ std::cout << "hello world!" << std::endl; }
