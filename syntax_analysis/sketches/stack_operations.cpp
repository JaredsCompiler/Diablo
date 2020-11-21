#include <iostream>
#include <limits>
#include <stack>
#include <type_traits>

enum compare_code {
  eLess,
  eGreater,
  eLessEqual,
  eGreaterEqual,
  eExplicitCompare,
  eDoubleAnd,
  eDoubleOr,
  eCompNotFound
};

enum arthimetic_code {
  eAdd,
  eSub,
  eDiv,
  eMul,
  eMod,
  eInc,
  eDec,
  eMathNotFound
};

compare_code compareHash(std::string str){
  if(str == ">"){ return eGreater; }
  if(str == "<"){ return eLess; }
  if(str == ">="){ return eGreaterEqual; }
  if(str == "<="){ return eLessEqual; }
  if(str == "=="){ return eExplicitCompare; }
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

template <typename T>
T compute(T a, T b, std::string s){
  // set to inf
  T val = std::numeric_limits<T>::infinity();
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
    //case eInc:
      //val = a
  }
  return val;
}

template <typename T>
bool compare(T a, T b, std::string c){
  T val = std::numeric_limits<bool>::infinity();
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
  }
  return val;
}

template <typename K>
K calculate(std::stack<K>* st_, std::stack<std::string>* operands){

  K inf = std::numeric_limits<K>::infinity();

  if(st_->size() <= operands->size()){ return inf; }

  while(!st_->empty() && !operands->empty()){
    K op_1 = st_->top();
    st_->pop();
    if(st_->empty()){
      st_->push(op_1);
      break;
    }
    K op_2 = st_->top();
    st_->pop();

    std::string operator_ = operands->top();
    operands->pop();

    K val = compute(op_1, op_2, operator_);

    if(val == inf){
      return val;
    } else {
      st_->push(val);
    }
  }
  return st_->top();
}

template <typename T, typename U>

bool Foo(){
  /*
   * Check if two types are the same
   */
  return std::is_same<T, U>::value;
}

int main(){
  std::stack<size_t> st_;
  std::stack<std::string> opr_;

  std::cout << compare(true, false, "&&") << std::endl;

  return 0;
  
  for(size_t i = 0; i < 10; ++i){
    st_.push(i);
  }
  for(int i = 0; i < 9; ++i){
    opr_.push("+");
  }
  size_t resultant = calculate(&st_, &opr_);
  if(resultant == std::numeric_limits<size_t>::infinity()){
    std::cerr << "this has failed" << std::endl;
  } else {
    std::cout << "this has passed with result of " << resultant << std::endl;
  }
  return 0;
}
