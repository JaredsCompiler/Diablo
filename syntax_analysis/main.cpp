/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014 Krzysztof Narkiewicz <krzysztof.narkiewicz@ezaquarii.com>
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 * 
 */

// STL

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

// EZAquarii

#include "includes/scanner.h"
#include "src/parser.hpp"
#include "includes/interpreter.h"

// Lexi

#include "../lexical_analysis/includes/reader.hpp"

// Synthetic

#include "includes/balancer.hpp"

// Seminal

#include "includes/Assembler.hpp"
#include "includes/Instruction.hpp"
#include "includes/Symbol.hpp"
#include "includes/SymbolTable.hpp"

#define DEBUG 1

using namespace Synthetic;
using namespace std;

const char* AUTHORS[] = {
  "Jared Dyreson",
  "Chris Nutter"
};

int showhelp = 0, showversion = 0, conductall = 0;

const char* INSTITUTION = "California State University Fullerton";

void conduct_all(void);
void setoption(const char* arg, const char* s, const char* t, int* value);
void init(int argc, const char* argv[]);
void help(void);
void version(void);
int conduct_one(std::string test);

void version(){
  printf(
    "Synthetic Grammar Checking (%s) 1.0\n"
    "Copyright (C) 2020 Comrade Software Foundation, Inc.\n"
    "MIT License\n"
    "This is free software, and provided as is without warranty\n"
    "Written by %s and %s\n",
  INSTITUTION, AUTHORS[0], AUTHORS[1]); 
}

void help(){
  printf(
    "Usage: ./synthetic [input]\n"
  );
}

void setoption(const char* arg, const char* s, const char* t, int* value) {
    
  if ((strcmp(arg, s) == 0) || ((t != NULL && strcmp(arg, t) == 0))) { *value = 1; }
    
}

void init(int argc, const char* argv[]) {

  while (argc-- > 0) {
    const char* arg = *argv;

    setoption(arg, "-v",    "--version",   &showversion);
    setoption(arg, "-h",    "--help",      &showhelp);
    setoption(arg, "-a",    "--all",       &conductall);

}

  // ================================= //

  if (showversion)  { version();  exit(0); }
  if (showhelp)     { help();     exit(0); }
  if (conductall)   { conduct_all(); exit(0); }                    

}

// ================================================================ //

int conduct_one(std::string test){
    Interpreter i;
    std::cout << "[+] Conducting test at location: " << test << std::endl;
    std::ifstream file;
    file.open(test);
    i.switchInputStream(&file);
    try{
      int res = i.parse();
      if(res > 0){
        std::cerr << "[-] Test at location: " << test << " has failed!" << std::endl;
        file.close();
        return 1;
      } else {
        std::cout << i.str() << std::endl;
      }
    }
    catch(DiabloBaseException& e){
      std::cout << e.what() << std::endl;
      return EOF;
    }
    file.close();
    std::cout << std::endl;
    return 0;
}

void conduct_all(){
    std::vector<std::string> unitTests = {
      "inputs/addition.txt",
      "inputs/assignment.txt",
      "inputs/boolean.txt",
      "inputs/comments.txt",
      "inputs/floating-point.txt",
      "inputs/for.txt",
      "inputs/functions.txt",
      "inputs/if-branching.txt",
      "inputs/integers.txt",
      "inputs/multiplication.txt",
      "inputs/variables.txt",
      "inputs/while.txt"
    };
    for(auto test : unitTests){
      int result = conduct_one(test);
      if(result == EOF){ return; }
    }
}

/*int main(int argc, char **argv) {
    conduct_one("inputs/boolean.txt");
    conduct_one("inputs/conditionals.txt");
    return 0;
}*/

// ================================================================ //
//

void testing(){
    Assembler ass = Assembler();
    Instruction instr = Instruction();
    ass.push(instr);
    std::cout << instr << std::endl;
    std::cout << ass << std::endl;
    Symbol s = Symbol("int", "value", 24);
    SymbolTable table = SymbolTable();

    if(!s.typeMismatch()){
      table.insert(s);
      std::cout << "inserted " << s.name_() << " with value of " << s.value_() << " at the location of " << s.location_() << std::endl;
    } else {
      std::cout << "could not insert, there was a type mismatch from " << s.type_() << " to value of " << s.value_() << std::endl;
    }

    std::cout << ass.getInstruction("+") << std::endl;
    std::cout << ass.getInstruction("-") << std::endl;
    std::cout << ass.getInstruction("*") << std::endl;
    std::cout << ass.getInstruction("/") << std::endl;
    std::cout << ass.getInstruction("<") << std::endl;
    std::cout << ass.getInstruction("<=") << std::endl;
    std::cout << ass.getInstruction(">=") << std::endl;
    std::cout << ass.getInstruction(">") << std::endl;
    std::cout << ass.getInstruction("!=") << std::endl;

    std::cout << table << std::endl;
}

int main(int argc, const char* argv[]) {

    //testing();

    if(argc < 2){
        help();
        return 1;
    }

    init(--argc, ++argv);
    conduct_one(argv[0]);

    return 0;

}

