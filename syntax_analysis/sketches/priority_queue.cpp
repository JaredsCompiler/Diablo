#include <iostream>

#include <queue>

struct S {
  int p;
  std::string expr;
  S(int pr, std::string e): p(pr), expr(e){}
  bool operator<(const S& s) const{
    return p < s.p;
  }
};


int main(){
  std::priority_queue<S> pq;
  pq.push(S(1, "c"));
  pq.push(S(2, "a + b"));

  while(!pq.empty()){
    std::cout << pq.top().expr << std::endl;
    pq.pop();
  }
  return 0;
}
