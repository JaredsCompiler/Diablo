#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>

#include "lexical_analysis/includes/reader.hpp"
//#include "includes/lexer_rules.hpp"
//#include "includes/lexer.hpp"
//#include "includes/lexeme.hpp"

const char* AUTHORS[] = {
  "Jared Dyreson",
  "Chris Nutter"
};

const char* INSTITUTION = "California State University Fullerton";

int main(int argc, const char* argv[]){
  sourceFile source = sourceFile("lexical_analysis/inputs/source.txt");
  for(auto line : source.get_content()){
    std::cout << line << std::endl;
  }
  return 0;
}
