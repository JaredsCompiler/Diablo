#include <stdio.h>
#include "stack.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


bool is_matching(char a, char b){
   if(a == '{' && b == '}'){ return true; }
   else if(a == '(' && b == ')'){ return true; }
   else if(a == '[' && b == ']'){ return true; }
   else if((a == '\'' || a == '\"') && a == b){ return true; }
   return false;

}

bool is_valid(char c){
  char list[] = "{([\'\"])}";
  for(int i = 0; i < strlen(list); ++i){
    if(list[i] == c){ return true; }
  }
  return false;
}

bool is_balanced(char line[]){
  int i = 0;
  char c;
  struct stack* stack_ = new_stack(strlen(line)+1);
  int quote_counter = 0;
  while(line[i]){
    c = line[i];
    if(c == '(' || c == '{' || c == '[' || c == '\'' || c == '\"'){ 
      push(stack_, c); 
    }
    if(c == ')' || c == '}' || c == ']' || c == '\'' || c == '\"'){
      if(c == '\'' || c == '\"'){ ++quote_counter; }
      if(empty(stack_)){ 
        return false; 
      }

      if(!is_matching(pop(stack_), c)){ 
        return false; 
      }
    }
    ++i;
  }
  if((quote_counter % 2 != 0)){ return false; }
  else if(empty(stack_)){ return true; }
  return false;
}

int main(int argc, const char* argv[]){
  char line[1024];
  char entire_file[10000];
  char c;
  int i;
  if(argc != 2){
    fprintf(stderr, "Usage: %s <input>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  FILE* input = fopen(argv[1], "r");

  while((c = fgetc(input)) != EOF){
    if(!isspace(c) && is_valid(c)){ 
      entire_file[i++] = c;
    }
  }
  if(is_balanced(entire_file)){ fprintf(stdout, "Balanced!\n"); }
  else{ fprintf(stderr, "Not balanced!\n"); }

  return 0;
}
