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
    #include <stack>
    #include <stdint.h>
    #include <string>
    #include <type_traits>
    #include <vector>

    #include "command.h"
    #include "hello_world.h"
    #include "includes/maths.hpp"

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
    #include <iostream>
    #include "scanner.h"
    #include "parser.hpp"
    #include "interpreter.h"
    #include "location.hh"
    
    // yylex() arguments are defined in parser.y
    static EzAquarii::Parser::symbol_type yylex(EzAquarii::Scanner &scanner, EzAquarii::Interpreter &driver) {
        return scanner.get_next_token();
    }
    
    // you can accomplish the same thing by inlining the code using preprocessor
    // x and y are same as in above static function
    // #define yylex(x, y) scanner.get_next_token()
    
    using namespace EzAquarii;
    vector<uint64_t> container;
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
%token <std::string> STRING  "string";
%token <uint64_t> NUMBER "number";
%token LEFTPAR "leftpar";
%token RIGHTPAR "rightpar";
%token SEMICOLON "semicolon";
%token COMMA "comma";
%token ASSIGN "assignment";
%token <std::string> OPERATOR "operator";

%type< EzAquarii::Command > command;
%type< EzAquarii::Command > subcommand;
%type< std::vector<uint64_t> > arguments;
%type< std::vector<uint64_t> > values;

%start program

%%

program :   {
                cout << "*** RUN ***" << endl;
                cout << "Type function with list of parmeters. Parameter list can be empty" << endl
                     << "or contain positive integers only. Examples: " << endl
                     << " * function()" << endl
                     << " * function(1,2,3)" << endl
                     << "Terminate listing with ; to see parsed AST" << endl
                     << "Terminate parser with Ctrl-D" << endl;
                
                cout << endl << "prompt> ";
                
                driver.clear();
            }
        | program command
            {
                const Command &cmd = $2;
                cout << "command parsed, updating AST" << endl;
                driver.addCommand(cmd);
                cout << endl << "prompt> ";
            }
        | program SEMICOLON
            {
                cout << "*** STOP RUN ***" << endl;
                cout << driver.str() << endl;
            }
        | program subcommand
            {
                cout << "doing that math shit" << endl;
                const Command &cmd = $2;
                cout << "command parsed, updating AST" << endl;
                driver.addCommand(cmd);
            }

        ;


command : STRING LEFTPAR RIGHTPAR
        {
            string &id = $1;
            cout << "ID: " << id << endl;
            $$ = Command(id);
        }
    | STRING LEFTPAR arguments RIGHTPAR
        {
            string &id = $1;
            const std::vector<uint64_t> &args = $3;
            cout << "function: " << id << ", " << args.size() << endl;
            $$ = Command(id, args);
        }
    /*| NUMBER PLUS NUMBER command*/
        /*{*/
            /*cout << $1 << "+" << $3 << endl;*/
            /*print_mess();*/
            /*$$ = Command("Hello");*/
        /*}*/
    ;


subcommand : values
        {

            /*std::vector<uint64_t> &args = $1;*/
            $$ = Command("subcommand", $1);
            /*$$ = std::vector<uint64_t>();*/
            /*$$.push_back(number);*/

        }
        /*| values NUMBER OPERATOR NUMBER values {*/
            /*std::cout << "helo" << std::endl;*/
        /*}*/
        /*| values OPERATOR values*/
        /*{*/
            /*std::vector<uint64_t> AB;*/
            /*std::vector<uint64_t> &A = $1;*/
            /*std::vector<uint64_t> &B = $3;*/

            /*AB.reserve( A.size() + B.size() ); // preallocate memory*/
            /*AB.insert( AB.end(), A.begin(), A.end() );*/
            /*AB.insert( AB.end(), B.begin(), B.end() );*/
            /*A = AB;*/
        /*}*/
        /*| values NUMBER OPERATOR NUMBER*/
        /*{*/

            /*uint64_t n1 = $2;*/
            /*uint64_t n2 = $4;*/

            /*std::vector<uint64_t> &args = $1;*/
            /*$$.push_back(n1);*/
            /*$$.push_back(n2);*/
            /*$$ = args;*/
        /*} */
    ;

values : NUMBER
        {
            uint64_t number = $1;
            std::vector<uint64_t> &args = $$;
            args.push_back(number);
            $$ = args;
        }
    | values OPERATOR NUMBER OPERATOR NUMBER
        {
            uint64_t n1 = $3;
            uint64_t n2 = $5;
            uint64_t resultant;

            std::string oper1 = $2;
            std::string oper2 = $4;

            std::vector<uint64_t> &args = $1;

            if(!args.empty()){
                uint64_t top = args.back();
                args.pop_back();
                /*args.push_back(compute(top, n1, oper1));*/
                args.push_back(top + n1);
                /*args.push_back(top + resultant);*/
            } else {
                args.push_back(resultant);
            }
            /*resultant = compute(resultant, n2, oper2);*/
            resultant = resultant + n2;
            /*if(oper2 == "+"){*/
                /*resultant = resultant + n2;*/
            /*}*/
            args.push_back(resultant);
            /*char oper = $4;*/
            /*switch(oper){*/
               /*case '+':*/
                    /*resultant = n1 + n2;*/
                    /*break;*/
            /*}*/
            /*args.push_back(n1);*/
            /*args.push_back(n2);*/
            $$ = args;
        }
    | values OPERATOR NUMBER
        {
            uint64_t n1 = $3;
            uint64_t resultant;
            std::vector<uint64_t> &args = $1;
            std::string oper = $2;
            if(!args.empty()){
                uint64_t top = args.back();
                args.pop_back();
                /*if(oper == "+"){*/
                    /*args.push_back(top + n1);*/
                /*}*/
                args.push_back(top + n1);
                /*args.push_back(compute(top, n1, oper));*/
                /*helloWorld();*/
                std::cout << compute(1, 1, "+");
            }
            else { args.push_back(n1); }
            $$ = args;
        }
    ;

arguments : NUMBER
        {
            uint64_t number = $1;
            $$ = std::vector<uint64_t>();
            $$.push_back(number);
            cout << "first argument: " << number << endl;
        }
    | arguments COMMA NUMBER
        {
            uint64_t number = $3;
            std::vector<uint64_t> &args = $1;
            args.push_back(number);
            $$ = args;
            cout << "next argument: " << number << ", arg list size = " << args.size() << endl;
        }
    ;
    
%%

// Bison expects us to provide implementation - otherwise linker complains
void EzAquarii::Parser::error(const location &loc , const std::string &message) {
        
        // Location should be initialized inside scanner action, but is not in this example.
        // Let's grab location directly from driver class.
	// cout << "Error: " << message << endl << "Location: " << loc << endl;
	
        cout << "Error: " << message << endl << "Error location: " << driver.location() << endl;
}
