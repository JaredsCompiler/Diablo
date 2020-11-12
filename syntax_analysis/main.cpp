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

#include <iostream>
#include <fstream>
#include <vector>

#include "includes/scanner.h"
#include "src/parser.hpp"
#include "includes/interpreter.h"

using namespace EzAquarii;
using namespace std;

int main(int argc, char **argv) {

    //auto example_element = EzAquarii::Parser::make_ID("HelloWorld", EzAquarii::location( [> put location data here if you want <] )); 
    //std::cout << typeid(example_element).name() << std::endl;
    //std::vector<EzAquarii::Parser::symbol_type> container;
    //container.push_back(example_element);
    //return 0;

    Interpreter i;
    std::vector<std::string> unitTests = {
      "inputs/if-branching.txt",
      //"inputs/multiplication.txt"
    };
    for(auto test : unitTests){
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
      }
      file.close();
      std::cout << std::endl;
    }
    return 0;
}
