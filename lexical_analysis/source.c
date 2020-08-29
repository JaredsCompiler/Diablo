#include <stdio.h>

// this is a comment

int main(){
  // block 1
  int a = 1;
  return 0;
  if(condition){
    // block 2
    printf("something here");
    if(anotherCondition){
      // block 3
      a++;
    }
  }
  return 0;
}

// blocks should be evaluated in the following order: 3 2 1 
