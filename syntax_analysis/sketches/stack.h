#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// https://www.techiedelight.com/stack-implementation/
// This helped me make a stack because C does not have data structures...wooo

struct stack{
  int max_, top_;
  int *container_;
};

struct stack* new_stack(int size_){
  struct stack *s = (struct stack*)malloc(sizeof(struct stack));
  s->max_ = size_; 
  s->top_ = -1;
  s->container_  = (int*)malloc(sizeof(int) * size_);
  return s;
}

bool empty(struct stack* s){ return (s->top_ == -1); }
bool is_full(struct stack* s){ return (s->top_ == s->max_ -1); }

int pop(struct stack *s){
  if(empty(s)){
    fprintf(stderr, "[-] Underflow exception!\n");
    exit(EXIT_FAILURE);
  }
  return s->container_[s->top_--];
}
void push(struct stack* s, int content){
  if(is_full(s)){
    fprintf(stderr, "[-] Overflow exception!\n");
    return;
  }
  s->container_[++s->top_] = content;
}

int peek(struct stack* s){
  if(empty(s)){
    fprintf(stderr, "[-] Underflow exception!\n");
    exit(EXIT_FAILURE);
  }
  return s->container_[s->top_];
}
