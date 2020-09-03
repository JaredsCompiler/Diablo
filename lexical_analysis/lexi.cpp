#include <iostream>
#include <stdio.h>

#include "includes/reader.hpp"

const char* AUTHORS[] = {
  "Jared Dyreson",
  "Chris Nutter"
};

const char* INSTITUTION = "California State University Fullerton";


void print_version(){
  printf(
    "lexi (%s) 1.0\n"
    "Copyright (C) 2020 Free Software Foundation, Inc.\n"
    "License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>."
    "This is free software: you are free to change and redistribute it.\n"
    "There is NO WARRANTY, to the extent permitted by law.\n"
    "Written by %s and %s\n",
  INSTITUTION, AUTHORS[0], AUTHORS[1]); 
}

int main(int argc, const char* argv[]){
  auto f = sourceFile("source.txt");
  auto contents = f.get_content();
  std::cout << contents[0][0] << std::endl;
  //f.print_contents();
  return 0;
}
