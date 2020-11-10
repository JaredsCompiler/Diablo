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

%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0"
%defines
%define api.parser.class { Parser }

%define api.token.constructor
%define api.value.type variant
%define parse.assert
%define api.namespace { EzAquarii }
%code requires
{

    #include <iostream>
    #include <limits>
    #include <map>
    #include <stack>
    #include <stdint.h>
    #include <string>
    #include <type_traits>
    #include <vector>

    #include "../includes/command.h"
    #include "../includes/maths.hpp"
    #include "../includes/stack_operations.hpp"
    #include "../includes/DiabloExceptions.hpp"

    using namespace std;

    namespace EzAquarii {
        class Scanner;
        class Interpreter;
    }



}
// Bison calls yylex() function that must be provided by us to suck tokens
// from the scanner. This block will be placed at the beginning of IMPLEMENTATION file (cpp).
// We define this function here (function! not method).
// This function is called only inside Bison, so we make it static to limit symbol visibility for the linker
// to avoid potential linking conflicts.
%code top
{
    #include <cstdio>
    #include <iostream>
    #include <regex>
    #include <tuple>

    #include "../includes/scanner.h"
    #include "../src/parser.hpp"
    #include "../includes/interpreter.h"
    #include "../src/location.hh"

    #include "../../lexical_analysis/includes/reader.hpp"
    #include "../../lexical_analysis/includes/lexer_rules.hpp"
    #include "../../lexical_analysis/includes/lexer.hpp"


    std::map<std::string, std::regex> tokenMap = {
        {"COMMENT", std::regex("(\\!.*\\!)")},
        {"KEYWORD", std::regex("(int|float|bool|true|false|(end)?if|else|then|while(end)?|do(end)?|for(end)?|(in|out)put|and|or|not)")},
        {"IDENTIFIER", std::regex("(\\w+)")},
        {"SEPARATORS", std::regex("(\\(|\\)|\\{|\\}|\\[|\\]|\"|\'|\\,)")},
        {"ASSIGNMENT", std::regex("(\\={1})")},
        {"OPERATORS", std::regex("(\\+|-|\\*|\\/|>|<|>=|<=|&+|\\|+|%|^!$|\\^)")},
        {"TERMINATORS", std::regex("(\\;|\\$)")}
    };

    sourceFile src("/tmp/small.txt");
    lexerRules rules = lexerRules(tokenMap);

    lexer lex = lexer(rules, src);
    /*lex->processFile();*/

    /*static EzAquarii::Parser::symbol_type yylex(EzAquarii::Scanner &scanner, EzAquarii::Interpreter &drive) {*/
        /*auto token = lex.get_next_token();*/
        /*std::string tag = token.get_tag();*/
        /*std::string content = token.get_substring();*/
        /*std::string* ptr = &tag;*/
        /*const auto[s, e] = token.get_slice();*/

        /*if(tag == "SEPARATORS" && content == "("){*/
            /*return EzAquarii::Parser::make_LEFTPAR(EzAquarii::location(ptr));*/
        /*} else{*/
            /*return scanner.get_next_token();*/
        /*}*/
    /*}*/
    // yylex() arguments are defined in parser.y
    static EzAquarii::Parser::symbol_type yylex(EzAquarii::Scanner &scanner, EzAquarii::Interpreter &driver) {
        std::cout << "giving next token!" << std::endl;
        return scanner.get_next_token();
    }
    
    // you can accomplish the same thing by inlining the code using preprocessor
    // x and y are same as in above static function
    // #define yylex(x, y) scanner.get_next_token()
    
    using namespace EzAquarii;

    std::map<std::string, double> symbolTable = {
        {
          "a", 10
        }
    };
}

%lex-param { EzAquarii::Scanner &scanner }
%lex-param { EzAquarii::Interpreter &driver }

%parse-param { EzAquarii::Scanner &scanner }
%parse-param { EzAquarii::Interpreter &driver }
%locations
%define parse.trace
%define parse.error verbose

%define api.token.prefix {TOKEN_}

%token END 0 "end of file"
%token <std::string> ID "identifier"; // a --> contains the value of 10
%token <long long int> NUMBER "number";
%token LEFTPAR "leftpar";
%token RIGHTPAR "rightpar";
%token SEMICOLON "semicolon";
%token COMMA "comma";
%token ASSIGN "assignment";
%token <std::string> GEOMETRIC_OP "geometric_op"; // multiplication and division
%token <std::string> ARITHMETIC_OP "arithmetic_op"; // addition and subtraction
%token <std::string> OPERATOR "operator";

%type< std::vector<long long int> > expression; // 1 + 1 + 1
%type< std::vector<double> > term; // (1 / 2 + 1)
%type< double > id; // value pointed by ^ 

%start program

%%

program :   { driver.clear(); }
        /*| program command*/
            /*{*/
                /*[>const Command &cmd = $2;<]*/
                /*cout << "command parsed, updating AST" << endl;*/
                /*[>driver.addCommand(cmd);<]*/
                /*cout << endl << "prompt> ";*/
            /*}*/
        | program expression
        {
            std::cout << "program expression" << std::endl;
            for(auto element : $2){
                std::cout << element << std::endl;
            }
        }
        | program term
        {
            for(auto element : $2){
                std::cout << element << std::endl;
            }
        }
        | program id {
            std::cout << $2 << std::endl;
        }
        | program SEMICOLON
            {
                cout << "*** STOP RUN ***" << endl;
                cout << driver.str() << endl;
            }
        | program assignmentRule
            {
                std::cout << "assigning" << std::endl;
                for(auto it = symbolTable.begin(); it != symbolTable.end(); ++it){
                    std::cout << it->first << " -> " << it->second << std::endl;
                }
            }
        ;

/*
* EXAMPLES
* 
* if(expression) <- branch operations
* 
* function(1, 2, 3) <- function with parameters of 1, 2, 3
* 
* These are not apart of the requirements and should be finished at a later date
*/

/*command : STRING LEFTPAR RIGHTPAR // function()*/
        /*{*/
            /*string &id = $1;*/
            /*cout << "ID: " << id << endl;*/
            /*$$ = Command(id);*/
        /*}*/
    /*| STRING LEFTPAR expression RIGHTPAR // function(1, 2, 3, 4)*/
        /*{*/
            /*string &id = $1;*/
            /*const std::vector<long long int> &args = $3;*/
            /*cout << "function: " << id << ", " << args.size() << endl;*/
            /*[>$$ = Command(id, args);<]*/
        /*}*/
    /*| LEFTPAR expression RIGHTPAR*/
        /*{*/
           /*[>$$ = Command("filler", $2);<]*/
        /*}*/
    /*| expression*/
        /*{*/
          /*$$ = Command("filler", $1);*/
        /*}*/
    /*;*/
/*
* a = (a + b)
* a = b
* a = 10
*/

assignmentRule : ID ASSIGN term
        {
            const std::vector<double> cont = $3;
            long long int val = cont.back();
            std::map<std::string, double>::iterator it = symbolTable.find($1);
            if(it != symbolTable.end()){
                std::cout << "updating value " << $1 << " with value of " << symbolTable[$1] << " to value of " << val << std::endl;
            } else {
                std::cout << "inserting " << $1 << " with value of " << val << std::endl; 
            }
            symbolTable[$1] = val;
        }
        | assignmentRule ID ASSIGN LEFTPAR expression RIGHTPAR
        {
            std::cout << $2 << " = (" << $5.back() << ")" << std::endl;
            symbolTable[$2] = $5.back();
        }
        | assignmentRule ID ASSIGN expression 
        {
            std::cout << $2 << " = (" << $4.back() << ")" << std::endl;
            symbolTable[$2] = $4.back();
        }
        | id
        {
            std::cout << "got value of " << $1 << std::endl;
        }
        /*{*/
            /*// place the value of said variable onto the stack*/
            /*std::string variable = $1;*/
            /*long long int gottem = get_variable(symbolTable, variable);*/
            /*if(gottem == std::numeric_limits<long long int>::infinity()){*/
                /*std::cerr << "we could not find " << $1 << std::endl;*/
            /*} else {*/
                /*std::cout << $1 << " has a value of " << gottem << std::endl;*/
            /*}*/

        /*}*/
    ;

/*
* a + b => 10 + 10
* a => 10
*/



/*
* ANY AMOUNT OF OF OPERANDS AND OPERATORS
* 
* <Expression> -> <Expression> + <Term> | <Expression> - <Term> | <Term>
* 1 + 2
* 1 + 2 + 3
* 1 + 2 * 3
* 1 + 3 / 5
*/

expression : NUMBER
        {
            std::cout << "arguments: " << "number " << "(" << $1 << ")" << std::endl;
            long long int number = $1;
            $$ = std::vector<long long int>();
            $$.push_back(number);
        }
    | expression ARITHMETIC_OP NUMBER
        {
            long long int number = $3;
            std::vector<long long int> &args = $1;
            std::string oper = $2;

            if(!args.empty()){
                long long int top = args.back();
                args.pop_back();
                args.push_back(compute(top, number, oper));
            }
            else { args.push_back(number); }
            $$ = args;
        }
    | LEFTPAR expression RIGHTPAR
    {
        std::cout << "got to " << "(" << "expression" << ")" << std::endl;
        $$ = $2;
    }
    /*| expression id ARITHMETIC_OP NUMBER*/
    /*{*/
        /*
        * a + 10 , where a => 10. Therefore 20 should lie on the top of the stack
        */
        /*long long int value = $1.back();*/
        /*std::vector<long long int> &args = $1;*/
        /*args.push_back(compute(value, $4, $3));*/
        /*$$ = args;*/
    /*}*/

    ;

id : ID 
     {
        std::string variable = $1;
        double value = get_variable(symbolTable, variable);
        if(value == std::numeric_limits<double>::infinity()){
            char buff[BUFSIZ];
            snprintf(buff, sizeof(buff), "[ERROR] Variable %s is undefined", variable.c_str());
            throw VariableNotDeclaredException(buff, __FILE__, __LINE__, __FUNCTION__, "Nothing");
        }
        $$ = value;
     }
;

/*
* ANY AMOUNT OF OF OPERANDS AND OPERATORS

* <Term> -> <Term> * <Factor> | <Term> / <Factor> | <Factor>
* 1 * 12.1231
* 1.5 / 2.12
*/

term : NUMBER {

        std::cout << "arguments: " << "number " << "(" << $1 << ")" << std::endl;
        double number = $1;
        $$ = std::vector<double>();
        $$.push_back(number);
       }
    | term GEOMETRIC_OP NUMBER
        {
            double number = $3;
            std::vector<double> &args = $1;
            std::string oper = $2;

            if(!args.empty()){
                double top = args.back();
                args.pop_back();
                args.push_back(compute(top, number, oper));
            }
            else { args.push_back(number); }
            $$ = args;
        }
%%

// Bison expects us to provide implementation - otherwise linker complains
void EzAquarii::Parser::error(const location &loc , const std::string &message) {
        
        // Location should be initialized inside scanner action, but is not in this example.
        // Let's grab location directly from driver class.
	// cout << "Error: " << message << endl << "Location: " << loc << endl;
	
        cout << "Error: " << message << endl << "Error location: " << driver.location() << endl;
}
