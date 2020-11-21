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

// EZAquarii

#include "includes/scanner.h"
#include "src/parser.hpp"
#include "includes/interpreter.h"

// Lexi

#include "../lexical_analysis/includes/reader.hpp"

// Synthetic

#include "includes/balancer.hpp"

using namespace Synthetic;
using namespace std;

int conduct_one(std::string test){
    //sourceFile src(test);

    //balancer B;
    //const auto[state, line, lineno] = B.is_file_balanced(src);
    //if(!state){
      //std::cerr << "[-] File " << src.get_path() << " is not balanced" << std::endl;
      //std::cerr << lineno << ": " << line << std::endl;
      //return EOF;
    //}

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
      "inputs/keywords.txt",
      "inputs/multiplication.txt",
      "inputs/variables.txt",
      "inputs/while.txt"
    };
    for(auto test : unitTests){
      int result = conduct_one(test);
      if(result == EOF){ return; }
    }
}

int main(int argc, char **argv) {
    conduct_one("inputs/boolean.txt");
    conduct_one("inputs/conditionals.txt");
    return 0;
}
