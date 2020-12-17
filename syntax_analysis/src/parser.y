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
%define api.namespace { Synthetic }
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
    #include "../includes/Debugging.hpp"

    #include "../includes/Symbol.hpp"

    using namespace std;

    namespace Synthetic {
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

    // yylex() arguments are defined in parser.y
    static Synthetic::Parser::symbol_type yylex(Synthetic::Scanner &scanner, Synthetic::Interpreter &driver) {
        return scanner.get_next_token();
    }
    
    // you can accomplish the same thing by inlining the code using preprocessor
    // x and y are same as in above static function
    // #define yylex(x, y) scanner.get_next_token()
    #define YYDEBUG 1
    
    using namespace Synthetic;
}

%lex-param { Synthetic::Scanner &scanner }
%lex-param { Synthetic::Interpreter &driver }

%parse-param { Synthetic::Scanner &scanner }
%parse-param { Synthetic::Interpreter &driver }
%locations
%define parse.trace
%define parse.error verbose

%define api.token.prefix {TOKEN_}

/*
* Values of or retrievers
*/

%token ASSIGN "assignment";
%token <std::string> ID "identifier"; // a --> contains the value of 10
%token <float> FLOAT "floatingPoint"; // floating point number
%token <long long int> BOOLEAN "boolean"; // true, false
%token <long long int> NUMBER "number";

/*
* Separators
*/

%token LEFTPAR "leftpar";
%token RIGHTPAR "rightpar";
%token LEFT_CURLY "leftcurly";
%token RIGHT_CURLY "rightcurly";

/*
* Delimiters
*/

%token SEMICOLON "semicolon";
%token COMMA "comma";

/*
* Signaling
*/
%token END 0 "end of file";

/*
* Operators
*/

%token <std::string> GEOMETRIC_OP "geometric_op"; // multiplication and division
%token <std::string> ARITHMETIC_OP "arithmetic_op"; // addition and subtraction
%token <std::string> RELATIONAL_OP "relational_op"; // greater than, etc.
%token <std::string> OPERATOR "operator";
%token <std::string> ID_INC "incrementing";
%token <std::string> ID_DEC "decrementing";

/*
* Reserved words
*/

%token <std::string> KEYWORD "keyword";
%token <std::string> PRIMITIVE_TYPE "primitive_type";

/*
* Control flow
*/

%token <std::string> IF "if";
%token <std::string> ELSE "else";
%token <std::string> THEN "then";
%token <std::string> ENDIF "endif";
%token <std::string> FOR "for";
%token <std::string> FOREND "forend";
%token <std::string> WHILE "while";
%token <std::string> WHILEEND "whileend";
%token <std::string> DO "do";
%token <std::string> DOEND "doend";

/*
* Whitespace and other ignoring things
*/

%token <std::string> COMMENT "comment";

/*
* Types for this language
*/

%type< std::vector<long long int> > expression; // 1 + 1 + 1
%type< bool > condition; // true, false
%type< double > factor; //
%type< std::vector<double> > term; // (1 / 2 + 1)
%type< double > id; // value pointed by ^ 

/*
* Commands to be preserved for the AST (essentially the rules)
*/

%type < Synthetic::Command > command;
%type < Synthetic::Command > assignment;
%type < Synthetic::Command > statement;
%type < std::vector<Synthetic::Command> > statements;
%type < Synthetic::Command > if_statement;
%type < Synthetic::Command > for_statement;
%type < Synthetic::Command > while_statement;

%start program

%%

program :   { driver.clear(); }
        | program command
            {
                /*const Command &cmd = $2;*/
                /*cout << "command parsed, updating AST" << endl;*/
                /*driver.addCommand(cmd);*/
                /*cout << endl << "prompt> ";*/
            }
        | program expression
        {
            /*dout << "command parsed: [expression], updating AST..." << std::endl;*/
            const Command c = Command("expression", $2);
            driver.addCommand(c);

        }
        | program term
        {
            std::vector<long long int> container;

            for(auto element : $2){ container.push_back((long long int)element); }
            
            const Command c = Command("term", container);
            driver.addCommand(c);
        }

        | program id {} // empty rule
        | program assignment {} // empty rule
        | program statements 
        {
            for(auto element : $2){
                driver.addCommand(element);
            }
        }

        | program SEMICOLON
            {
                cout << "*** STOP RUN ***" << endl;
                cout << driver.str() << endl;
            }
        | program condition
            {
                std::vector<long long int> v = {(long long int)$2};
                const Command cmd = Command("condition", v);
                /*cout << "command parsed, updating AST" << endl;*/
                driver.addCommand(cmd);
            }
        | program FLOAT
            {
                std::vector<float> c = {$2};
                const Command cmd = Command("float", c);
                /*cout << "command parsed, updating AST" << endl;*/
                driver.addCommand(cmd);
            }
        ;

/*
* NOTE
* NOT DOCUMENTED, here as a place holder until we get function calls working
* 
* EXAMPLES
* 
* if(expression) <- branch operations
* 
* function(1, 2, 3) <- function with parameters of 1, 2, 3
* 
* These are not apart of the requirements and should be finished at a later date
*/

command : ID LEFTPAR RIGHTPAR // function()
        {
            string &id = $1;
            cout << "ID: " << id << endl;
            $$ = Command(id);
        }
    | KEYWORD
        {
          $$ = Command("keyword");
        }
    | COMMENT
        {
            $$ = Command("comment");
        }
    ;
/*
* a = (a + b)
* a = b
* a = 10
*/

condition : expression RELATIONAL_OP expression 
    {
        dout << "expression (" << $1.back() << ") RELATIONAL_OP (" << $2 << ") expression" <<  $3.back() << std::endl << std::endl;
        long long int a = $1.back();
        long long int b = $3.back();
        // TODO
        // throw error if operator not found or condition does not evaluate
        // make this rule more efficient, duplicate code.
        
        Instruction operation_ =  driver.generateInstruction($2);
        Instruction push_one_ = driver.generateBlankInstruction("PUSHI");
        Instruction push_two_ = driver.generateBlankInstruction("PUSHI");

        push_one_.updateQuantity(a);
        push_two_.updateQuantity(b);

        bool _c = compare(a, b, $2);

        Instruction resultant_ = driver.generateBlankInstruction("PUSHI");
        resultant_.updateQuantity((int)_c);

        driver.addInstruction(push_one_);
        driver.addInstruction(push_two_);
        driver.addInstruction(operation_);
        driver.addInstruction(resultant_);

        $$ = _c;

    }
    | LEFTPAR expression RELATIONAL_OP expression RIGHTPAR
    {
        dout << "LEFTPAR expression (" << $2.back() << ") RELATIONAL_OP (" << $3 << ") expression (" << $4.back() << ") RIGHTPAR" << std::endl << std::endl;

        long long int a = $2.back();
        long long int b = $4.back();
        // TODO
        // throw error if operator not found or condition does not evaluate
        // I KNOW THIS IS DUPLICATE CODE, IT TOO MAKES ME SOB

        Instruction operation_ =  driver.generateInstruction($3);
        Instruction push_one_ = driver.generateBlankInstruction("PUSHI");
        Instruction push_two_ = driver.generateBlankInstruction("PUSHI");

        push_one_.updateQuantity(a);
        push_two_.updateQuantity(b);

        bool _c = compare(a, b, $3);

        Instruction resultant_ = driver.generateBlankInstruction("PUSHI");
        resultant_.updateQuantity((int)_c);

        driver.addInstruction(push_one_);
        driver.addInstruction(push_two_);
        driver.addInstruction(operation_);
        driver.addInstruction(resultant_);

        $$ = _c;
    }
    | BOOLEAN
    {
        dout << "BOOLEAN (" << $1 << ")" << std::endl;
        bool _v = ($1) ? true : false;
        // ahhhh we need to preserve these values
        // using a stack MIGHT invert the calculations, TODO
        // mostly for preserving scope of conditionals in statements
        driver.insertElementForCalculation(_v);
        $$ = _v;
    }
    | LEFTPAR BOOLEAN RIGHTPAR
    {
        dout << "LEFTPAR BOOLEAN (" << $2 << ") RIGHTPAR" << std::endl;
        bool _v = ($2) ? true : false;
        // ahhhh we need to preserve these values
        // mostly for preserving scope of conditionals in statements
        driver.insertElementForCalculation(_v);
        $$ = _v;
    }
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
*/

expression : NUMBER
        {
            dout << "NUMBER (" << $1  << ") ";
            long long int number = $1;
            $$ = std::vector<long long int>();

            Instruction push_one_ = driver.generateBlankInstruction("PUSHI");

            push_one_.updateQuantity((int)number);
            driver.addInstruction(push_one_);
            driver.setDispenseFlag(false);

            $$.push_back(number);
        }
    | expression ARITHMETIC_OP NUMBER
        {
            dout << "<expression> ARITHMETIC_OP (" << $2 << ") NUMBER (" << $3  << ")" << std::endl << std::endl;
            long long int number = $3;
            std::vector<long long int> &args = $1;
            std::string oper = $2;

            long long int top = args.back();

            if(!args.empty()){
                args.pop_back();
                args.push_back(compute(top, number, oper));
            }
            else { args.push_back(number); }

            /*
            * PUSHI $1
            * PUSHI $3
            * ADD
            * ! Leave current value on top of stack !
            */


            Instruction operation_ = driver.generateInstruction($2);

            Instruction push_one_ = driver.generateBlankInstruction("PUSHI");
            Instruction push_two_ = driver.generateBlankInstruction("PUSHI");

            push_one_.updateQuantity(top);
            push_two_.updateQuantity(number);

            if(driver.shouldDispenseFlag()){
                driver.addInstruction(push_one_);
                driver.setDispenseFlag(true);
            }
            driver.addInstruction(push_two_);
            driver.addInstruction(operation_);

            $$ = args;
        }
    | LEFTPAR expression RIGHTPAR
    {
        dout << "LEFTPAR <expression> RIGHTPAR" << std::endl;
        // README
        // Seems that there does not need to be any ASM here, the code gets handled recursively
        $$ = $2;
    }
    
;

id : ID 
     {
        std::cout << "[-] Unused variable " << $1 << " ; will not create any instructions for this line" << std::endl;
        Symbol _S = driver.getSymbol($1);
        if(!_S.isDefined()){
            std::cerr << "[-] " << $1 << " has not been defined" << std::endl;
        } else {
            $$ = _S.value_();
        }
        // TODO
        // Very fancy error handling, rn i'm fighting for my life

        /*dout << "ID ( " << $1 << ")" << std::endl;*/
        /*std::string variable = $1;*/
        /*long long int value = driver.getSymbol(variable);*/
        /*[>double value = get_variable(symbolTable, variable);<]*/
        /*if(value == std::numeric_limits<long long int>::infinity()){*/
            /*char buff[BUFSIZ];*/
            /*snprintf(buff, sizeof(buff), "[ERROR] Variable %s is undefined", variable.c_str());*/
            /*throw VariableNotDeclaredException(buff, __FILE__, __LINE__, __FUNCTION__, "Nothing");*/
        /*} else {*/
            /*dout << "variable [" << variable << "] with value of --> " << "[" << value << "]" << std::endl;*/
        /*}*/
        /*$$ = 1.0;*/
        /*$$ = value;*/
     }
;

assignment : PRIMITIVE_TYPE ID SEMICOLON 
    {
        dout << "PRIMITIVE_TYPE (" << $1 << ") " << "ID (" << $2 << ") " << "SEMICOLON (;)" << std::endl;

        Symbol S = Symbol($1, $2, 0);
        
        Instruction initial_push = driver.generateBlankInstruction("PUSHI");
        initial_push.updateQuantity(0);


        if(S.isDefined()){
            std::cerr << "[-] Variable " << $2 << " has already been defined!" << std::endl;
        } else {
            driver.addSymbol(S, true);
            driver.addInstruction(initial_push);

            auto _S = driver.getSymbol($2);
            Instruction push_val_ = driver.generateBlankInstruction("POPM");
            push_val_.updateQuantity(_S.location_());

            driver.addInstruction(push_val_);
        }
    }

    | PRIMITIVE_TYPE ID ASSIGN expression SEMICOLON
    {
        dout << "PRIMITIVE_TYPE (" << $1 << ") " << "ID (" << $2 << ")" << " ASSIGN (=) expression (" << $4.back() << ") SEMICOLON (;)" << std::endl;
        unsigned long long int value = $4.back();

        Symbol _S = driver.getSymbol($2);
        Symbol S = Symbol($1, $2, value);

        if(_S.isDefined()){
            std::cerr << "[-] Variable " << $2 << " has already been defined!" << std::endl;
        } 
        else if(S.typeMismatch()){
            std::cerr << "[-] Cannot assign " << $2 << " with value of " << value << " ; type mismatch!" << std::endl;
        } else {
            driver.addSymbol(S, true);
            auto _t = driver.getSymbol($2);

            Instruction initial_push = driver.generateBlankInstruction("PUSHM");
            initial_push.updateQuantity(_t.location_());

            driver.addInstruction(initial_push);
        }
    }
    | ID ASSIGN expression SEMICOLON
    {
        dout << "ID (" << $1 << ") ASSIGN (=) expresion (" << $3.back() << ") SEMICOLON (;)" << std::endl;
        long long int value = $3.back();

        Symbol S = driver.getSymbol($1);
        if(!S.isDefined() || S.typeMismatch()){
            std::cerr << "[-] Variable " << $1 << " is undefined " << std::endl;
        } else {
            /*long long int prev = S.value_();*/
            /*std::cout << "[+] Updating " << $1 << " with value of " << prev << " to the value of " << value  << std::endl;*/
            S.setValue(value);
            driver.addSymbol(S, false);

            Instruction initial_push = driver.generateBlankInstruction("PUSHM");
            initial_push.updateQuantity(S.location_());

            driver.addInstruction(initial_push);
        }

    }
    | PRIMITIVE_TYPE ID ASSIGN term SEMICOLON
    {
        dout << "PRIMITIVE_TYPE (" << $1 << ") ID (" << $2 << ") ASSIGN (=) term (" << $4.back() << ") SEMICOLON (;)" << std::endl;
        unsigned long long int value = (unsigned long long int)$4.back();

        Symbol _S = driver.getSymbol($1);
        Symbol S = Symbol($1, $2, value);
        if(_S.isDefined()){
            std::cerr << "[-] Variable " << $2 << " has already been defined!" << std::endl;
        } else if(S.typeMismatch()){
            std::cerr << "[-] Cannot assign " << $2 << " with value of " << value << " ; type mismatch!" << std::endl;
        } else {

            driver.addSymbol(S, true);
            auto _t = driver.getSymbol($2);

            Instruction initial_push = driver.generateBlankInstruction("PUSHM");
            initial_push.updateQuantity(_t.location_());

            driver.addInstruction(initial_push);
        }
    }
    | ID ASSIGN term SEMICOLON
    {
        dout << "ID (" << $1 << ") ASSIGN (=) term (" <<  $3.back() << ") SEMICOLON (;)" << std::endl;

        unsigned long long int value = (unsigned long long int)$3.back();

        Symbol S = driver.getSymbol($1);
        if(!S.isDefined() || S.typeMismatch()){
            std::cerr << "[-] Variable " << $1 << " is undefined " << std::endl;
        } else {
           /*long long int prev = S.value_();*/
           /*std::cout << "[+] Updating " << $1 << " with value of " << prev << " to the value of " << value  << std::endl;*/
            S.setValue(value);
            driver.addSymbol(S, false);

            Instruction initial_push = driver.generateBlankInstruction("PUSHM");
            initial_push.updateQuantity(S.location_());

            driver.addInstruction(initial_push);
        }
    }

;

/*
* ANY AMOUNT OF OF OPERANDS AND OPERATORS

* <Term> -> <Term> * <Factor> | <Term> / <Factor> | <Factor>
* 1 * 12.1231
* 1.5 / 2.12
*/

term : factor {
        dout << "factor (" << $1 << ")" << std::endl;
        double number = $1;
        $$ = std::vector<double>();

        Instruction push_one_ = driver.generateBlankInstruction("PUSHI");

        push_one_.updateQuantity((int)number);
        driver.addInstruction(push_one_);

        $$.push_back(number);
       }
    | term GEOMETRIC_OP factor
        {
            dout << "term (" << $1.back() << ") GEOMETRIC_OP (" << $2 << ") factor (" << $3 << std::endl;
            double number = $3;
            std::vector<double> &args = $1;
            std::string oper = $2;

            double top = args.back();
            if(!args.empty()){
                args.pop_back();
                args.push_back(compute(top, number, oper));
            }
            else { args.push_back(number); }

            Instruction operation_ = driver.generateInstruction($2);

            Instruction push_one_ = driver.generateBlankInstruction("PUSHI");
            Instruction push_two_ = driver.generateBlankInstruction("PUSHI");

            push_one_.updateQuantity((int)top);
            push_two_.updateQuantity(number);

            if(driver.shouldDispenseFlag()){
                driver.addInstruction(push_one_);
                driver.setDispenseFlag(true);
            }

            driver.addInstruction(push_two_);
            driver.addInstruction(operation_);

            $$ = args;
        }
    | LEFTPAR term RIGHTPAR
    {
        dout << "LEFTPAR term (" << $2.back() << ") RIGHTPAR" << std::endl;
        $$ = $2;
    }
    | id
    {
        dout << "id (" << $1 << ")" << std::endl;
        $$ = std::vector<double>($1);
    }
;

factor : id ID
        {
          dout  << "id (" << $1 << ") ID (" << $2 << ")" << std::endl;
          $$ = $1;
        }
        | NUMBER
        {
            dout << "NUMBER (" << $1 << ")" << std::endl;
            $$ = $1;
        }
        | LEFTPAR expression RIGHTPAR
        {
            dout << "LEFTPAR <expression> (" << $2.back() << ") RIGHTPAR" << std::endl;
            $$ = $2.back();
        }
;

statements : statement statements
        | statement
        {
            dout << "<statement> " << std::endl; 
            Synthetic::Command c("statement");
            std::vector<Synthetic::Command> container = {c};
            $$ = container;
        }
;

statement : assignment 
    {
        dout << "<assignment> ";
        $$ = Command("statement");
    }
    | if_statement
    {
        dout  << "<if_statement> ";
        $$ = Command("if_statement");
    }
    | for_statement
    {
        dout << "<for_statement> ";
        $$ = Command("for_statement");
    }
    | while_statement
    {
        dout  << "<while_statement> ";
        $$ = Command("while_statement");
    }
;

if_statement : IF condition THEN statements ENDIF {
    dout << "IF <condition> ";
    dout << " THEN <statements> ";
    dout << " ENDIF" << std::endl;
} // do i need to bubble this up ? 
            | IF condition THEN statements ELSE statements ENDIF {
                dout << "IF <condition>";
                dout << " THEN <statements> ";
                dout << " ELSE <statements> ";
                dout << " ENDIF" << std::endl;
            }
;

for_statement : FOR LEFTPAR PRIMITIVE_TYPE ID ASSIGN expression SEMICOLON ID RELATIONAL_OP expression SEMICOLON ID_INC RIGHTPAR statements FOREND

    {
        /*
        * for (int i = 0; i < 10; ++i)
        *    int value = 0;
        * forend
        */
        dout << " FOR LEFTPAR PRIMITIVE_TYPE (" << $3 << ") ID (" << $4 << ") ASSIGN (=) <expression> ";
        dout << " SEMICOLON (;) ID (" << $8 << ") RELATIONAL_OP (" << $9 << ")" << "<expression> ";
        dout << "  SEMICOLON (;) ID_INC (" << $10.back() << ") RIGHTPAR <statements> ";
        dout << " FOREND " << std::endl;

    }
    | FOR LEFTPAR PRIMITIVE_TYPE ID ASSIGN expression SEMICOLON ID RELATIONAL_OP expression SEMICOLON ID_DEC RIGHTPAR statements FOREND
    {

        /*
        * for (int i = 0; i < 10; --i)
        *    int value = 0;
        * forend
        */
        dout << " FOR LEFTPAR PRIMITIVE_TYPE (" << $3 << ") ID (" << $4 << ") ASSIGN << <expression> " ;
        dout << " SEMICOLON (;) ID (" << $8 << ") RELATIONAL_OP (" << $9 << ") <expression> ";
        dout << " SEMICOLON (;) ID_DEC (--) RIGHTPAR <statements> ";
        dout << " FOREND" << std::endl;
    }
;

while_statement : WHILE condition statements WHILEEND {
    dout << "WHILE <condition> " ;
    dout << " <statements> ";
    dout << " WHILEEND" << std::endl;
}
                | DO statement WHILE condition DOEND {
    dout << " DO <statement> ";
    dout << " WHILE <condition> ";
    dout << " DOEND" << std::endl;
}
                | DO statements WHILE condition DOEND {
    dout << " DO <statements> ";
    dout << " WHILE <condition> ";
    dout << " DOEND" << std::endl;
}
;

%%

// Bison expects us to provide implementation - otherwise linker complains
void Synthetic::Parser::error(const location &loc , const std::string &message) {
        
        // Location should be initialized inside scanner action, but is not in this example.
        // Let's grab location directly from driver class.
	// cout << "Error: " << message << endl << "Location: " << loc << endl;
	
        cout << "Error: " << message << endl << "Error location: " << driver.location() << endl;
}
