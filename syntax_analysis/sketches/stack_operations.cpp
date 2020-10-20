#include <iostream>
#include <limits>
#include <stack>

template <typename T>
T compute(T a, T b, char s){
  // set to inf
  T val = std::numeric_limits<T>::infinity();
  switch(s){
    case '+':
      val = a + b;
      break;
    case '-':
      val = a - b;
      break;
    case '/':
      if(b == 0){
        std::cerr << "cannot do that!" << std::endl;
        break;
      }
      val = a / b;
      break;
    case '*':
      val = a * b;
      break;
  }
  return val;
}

template <typename K>
K calculate(std::stack<K>* st_, std::stack<char>* operands){

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

    char operator_ = operands->top();
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

template <typename T>

T get_head(std::stack<T>* s){
  T val = s->top();
  s->pop();
  return val;
}

int main(){
  std::stack<size_t> st_;
  std::stack<char> opr_;
  for(size_t i = 0; i < 10; ++i){
    st_.push(i);
  }
  for(int i = 0; i < 9; ++i){
    opr_.push('+');
  }
  size_t resultant = calculate(&st_, &opr_);
  if(resultant == std::numeric_limits<size_t>::infinity()){
    std::cerr << "this has failed" << std::endl;
  } else {
    std::cout << "this has passed with result of " << resultant << std::endl;
  }
  return 0;
}
