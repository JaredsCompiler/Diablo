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

%{
	#include <iostream>
	#include <cstdlib>
	#include "scanner.h"
	#include "interpreter.h"
	#include "parser.hpp"
	#include "location.hh"

	using namespace std;

	// Original yyterminate() macro returns int. Since we're using Bison 3 variants
	// as tokens, we must redefine it to change type from `int` to `Parser::semantic_type`
	#define yyterminate() Synthetic::Parser::make_END(Synthetic::location());

	// This will track current scanner location.
	// Action is called when length of the token is known.
	#define YY_USER_ACTION m_driver.increaseLocation(yyleng);
	
	// !!!WARNING!!!
	// Location API is used, but the location is not initialized, 'cause I'm lazy. When making
	// a token with make_{something} method you can pass detailed token location. Current location
	// is accessible with m_driver.location() method. All puzzle elements are there - just
	// pass location value in every action code block below. I'm going to waste more time writing
	// this excuse than putting this boilerplate below...
	//
	// Location class can be found in location.hh and posistion.hh files. It's just a bit too much
	// boilerplate for this small example. Bummer.

/*[a-zA-Z]+      { */
                /*cout << "Scanner: identifier [" << yytext << "]" << endl;*/
                /*return Synthetic::Parser::make_ID(yytext, Synthetic::location( [> put location data here if you want <] )); */
            /*}*/

%}

%option nodefault
%option noyywrap
%option c++
%option yyclass="Scanner"
%option prefix="Synthetic_"

%%



input|output {
                cout << "Scanner: keyword [" << yytext << "]" << endl;
                return Synthetic::Parser::make_KEYWORD(yytext, Synthetic::location());
            }

true|false {
    cout << "Scanner: boolean [" << yytext << "]" << endl;
    long long int value = (strcmp(yytext, "true") == 0) ? 1 : 0;
    return Synthetic::Parser::make_BOOLEAN(value, Synthetic::location());
}

int|float|bool {
            cout << "Scanner: type [" << yytext << "]" << endl;
            return Synthetic::Parser::make_PRIMITIVE_TYPE(yytext, Synthetic::location());
}

if {
        cout << "Scanner: if statement" << endl;
        return Synthetic::Parser::make_IF(yytext, Synthetic::location());
}

else {
        cout << "Scanner: else statement" << endl;
        return Synthetic::Parser::make_ELSE(yytext, Synthetic::location());
}

then {
    cout << "Scanner: then statement" << endl;
    return Synthetic::Parser::make_THEN(yytext, Synthetic::location());
}

endif {
    cout << "Scanner: endif statement" << endl;
    return Synthetic::Parser::make_ENDIF(yytext, Synthetic::location());
}

for {
    cout << "Scanner: for" << endl;
    return Synthetic::Parser::make_FOR(yytext, Synthetic::location());
}

forend {
    cout << "Scanner: forend" << endl;
    return Synthetic::Parser::make_FOREND(yytext, Synthetic::location());
}

while {

    cout << "Scanner: while" << endl;
    return Synthetic::Parser::make_WHILE(yytext, Synthetic::location());
}

whileend {

    cout << "Scanner: whileend" << endl;
    return Synthetic::Parser::make_WHILEEND(yytext, Synthetic::location());
}

do {
    return Synthetic::Parser::make_DO(yytext, Synthetic::location());
}

doend {
    return Synthetic::Parser::make_DOEND(yytext, Synthetic::location());
}

[a-z|A-Z][a-zA-Z0-9]*  {
                cout << "Scanner: identifier [" << yytext << "]" << endl;
                return Synthetic::Parser::make_ID(yytext, Synthetic::location());
            }

\+\+[a-z|A-Z][a-zA-Z0-9]*|[a-z|A-Z][a-zA-Z0-9]*\+\+  {
                cout << "Scanner: incrementing [" << yytext << "]" << endl;
                return Synthetic::Parser::make_ID_INC(yytext, Synthetic::location());
            }

\-\-[a-z|A-Z][a-zA-Z0-9]*|[a-z|A-Z][a-zA-Z0-9]*\-\-  {
                cout << "Scanner: decrementing [" << yytext << "]" << endl;
                return Synthetic::Parser::make_ID_DEC(yytext, Synthetic::location());
            }

\!.*\!      {
                cout << "Scanner: comment [" << yytext << "]" << endl;
                return Synthetic::Parser::make_COMMENT(yytext, Synthetic::location());
            }

            
\(          {
                cout << "Scanner: '('" << endl;
                /*cout << "Location is: " << Synthetic::location() << endl;*/
                return Synthetic::Parser::make_LEFTPAR(Synthetic::location());
            }
            
\)          { 
                cout << "Scanner: ')'" << endl;
                return Synthetic::Parser::make_RIGHTPAR(Synthetic::location());
            }
\{  {

                cout << "Scanner: '{'" << endl;
                return Synthetic::Parser::make_LEFT_CURLY(Synthetic::location());
}
            
\}  {

                cout << "Scanner: '}'" << endl;
                return Synthetic::Parser::make_RIGHT_CURLY(Synthetic::location());
}
;           {
                cout << "Scanner: ';'" << endl;
                return Synthetic::Parser::make_SEMICOLON(Synthetic::location());
            }
            
,           {
                cout << "Scanner: ','" << endl;
                return Synthetic::Parser::make_COMMA(Synthetic::location());
            }
[\+|\-]{1}   {
                    cout << "Arithmetic operator recieved: " <<  yytext << endl;
                    return Synthetic::Parser::make_ARITHMETIC_OP(yytext, Synthetic::location());
                }

[\*|\/]   {
                    cout << "Geometric operator recieved: " <<  yytext << endl;
                    return Synthetic::Parser::make_GEOMETRIC_OP(yytext, Synthetic::location());
            }
\<|\>|\>\=|\<\=|and|or|not {
                        cout << "Relation operator received: " << yytext << endl;
                        return Synthetic::Parser::make_RELATIONAL_OP(yytext, Synthetic::location());
                   }

\=        {
                cout << "assignment" << endl;
                return Synthetic::Parser::make_ASSIGN(Synthetic::location());
            }
            
[\n\t ]     {
                //cout << "Scanner: whitechar (ignored)" << endl;
            }


[-+]?[0-9]+ {
                cout << "Scanner: decimal number [" << yytext << "]" << endl;
                long long int number = strtoll(yytext, 0, 10);
                return Synthetic::Parser::make_NUMBER(number, Synthetic::location());
            }

[-+]?[0-9]+[\.]?[0-9]+ {
                cout << "Scanner: double [" << yytext << "]" << endl;
                std::string::size_type sz;
                float number = std::stof(yytext, &sz); 
                
                return Synthetic::Parser::make_FLOAT(number, Synthetic::location());
            }

.           { 
                cout << "Scanner: unknown character [" << yytext << "]" << endl; 
            }
            
<<EOF>>     { return yyterminate(); }


%%
