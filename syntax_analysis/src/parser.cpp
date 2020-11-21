// A Bison parser, made by GNU Bison 3.6.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

// "%code top" blocks.
#line 72 "src/parser.y"

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

    std::map<std::string, double> symbolTable = {
        {"a", 10}
    };

#line 67 "src/parser.cpp"




#include "parser.hpp"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 37 "src/parser.y"
namespace  Synthetic  {
#line 167 "src/parser.cpp"

  /// Build a parser object.
   Parser :: Parser  (Synthetic::Scanner &scanner_yyarg, Synthetic::Interpreter &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

   Parser ::~ Parser  ()
  {}

   Parser ::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
   Parser ::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

   Parser ::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
   Parser ::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
   Parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

   Parser ::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

   Parser ::symbol_kind_type
   Parser ::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

   Parser ::stack_symbol_type::stack_symbol_type ()
  {}

   Parser ::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case 35: // command
      case 39: // assignment
      case 43: // statement
      case 44: // if_statement
      case 45: // for_statement
      case 46: // while_statement
        value.YY_MOVE_OR_COPY<  Synthetic::Command  > (YY_MOVE (that.value));
        break;

      case 36: // condition
        value.YY_MOVE_OR_COPY<  bool  > (YY_MOVE (that.value));
        break;

      case 38: // id
      case 41: // factor
        value.YY_MOVE_OR_COPY<  double  > (YY_MOVE (that.value));
        break;

      case 42: // statements
        value.YY_MOVE_OR_COPY<  std::vector<Synthetic::Command>  > (YY_MOVE (that.value));
        break;

      case 40: // term
        value.YY_MOVE_OR_COPY<  std::vector<double>  > (YY_MOVE (that.value));
        break;

      case 37: // expression
        value.YY_MOVE_OR_COPY<  std::vector<long long int>  > (YY_MOVE (that.value));
        break;

      case 5: // "floatingPoint"
        value.YY_MOVE_OR_COPY< float > (YY_MOVE (that.value));
        break;

      case 6: // "boolean"
      case 7: // "number"
        value.YY_MOVE_OR_COPY< long long int > (YY_MOVE (that.value));
        break;

      case 4: // "identifier"
      case 14: // "geometric_op"
      case 15: // "arithmetic_op"
      case 16: // "relational_op"
      case 17: // "operator"
      case 18: // "incrementing"
      case 19: // "decrementing"
      case 20: // "keyword"
      case 21: // "primitive_type"
      case 22: // "if"
      case 23: // "else"
      case 24: // "then"
      case 25: // "endif"
      case 26: // "for"
      case 27: // "forend"
      case 28: // "while"
      case 29: // "whileend"
      case 30: // "do"
      case 31: // "doend"
      case 32: // "comment"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

   Parser ::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case 35: // command
      case 39: // assignment
      case 43: // statement
      case 44: // if_statement
      case 45: // for_statement
      case 46: // while_statement
        value.move<  Synthetic::Command  > (YY_MOVE (that.value));
        break;

      case 36: // condition
        value.move<  bool  > (YY_MOVE (that.value));
        break;

      case 38: // id
      case 41: // factor
        value.move<  double  > (YY_MOVE (that.value));
        break;

      case 42: // statements
        value.move<  std::vector<Synthetic::Command>  > (YY_MOVE (that.value));
        break;

      case 40: // term
        value.move<  std::vector<double>  > (YY_MOVE (that.value));
        break;

      case 37: // expression
        value.move<  std::vector<long long int>  > (YY_MOVE (that.value));
        break;

      case 5: // "floatingPoint"
        value.move< float > (YY_MOVE (that.value));
        break;

      case 6: // "boolean"
      case 7: // "number"
        value.move< long long int > (YY_MOVE (that.value));
        break;

      case 4: // "identifier"
      case 14: // "geometric_op"
      case 15: // "arithmetic_op"
      case 16: // "relational_op"
      case 17: // "operator"
      case 18: // "incrementing"
      case 19: // "decrementing"
      case 20: // "keyword"
      case 21: // "primitive_type"
      case 22: // "if"
      case 23: // "else"
      case 24: // "then"
      case 25: // "endif"
      case 26: // "for"
      case 27: // "forend"
      case 28: // "while"
      case 29: // "whileend"
      case 30: // "do"
      case 31: // "doend"
      case 32: // "comment"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case 35: // command
      case 39: // assignment
      case 43: // statement
      case 44: // if_statement
      case 45: // for_statement
      case 46: // while_statement
        value.copy<  Synthetic::Command  > (that.value);
        break;

      case 36: // condition
        value.copy<  bool  > (that.value);
        break;

      case 38: // id
      case 41: // factor
        value.copy<  double  > (that.value);
        break;

      case 42: // statements
        value.copy<  std::vector<Synthetic::Command>  > (that.value);
        break;

      case 40: // term
        value.copy<  std::vector<double>  > (that.value);
        break;

      case 37: // expression
        value.copy<  std::vector<long long int>  > (that.value);
        break;

      case 5: // "floatingPoint"
        value.copy< float > (that.value);
        break;

      case 6: // "boolean"
      case 7: // "number"
        value.copy< long long int > (that.value);
        break;

      case 4: // "identifier"
      case 14: // "geometric_op"
      case 15: // "arithmetic_op"
      case 16: // "relational_op"
      case 17: // "operator"
      case 18: // "incrementing"
      case 19: // "decrementing"
      case 20: // "keyword"
      case 21: // "primitive_type"
      case 22: // "if"
      case 23: // "else"
      case 24: // "then"
      case 25: // "endif"
      case 26: // "for"
      case 27: // "forend"
      case 28: // "while"
      case 29: // "whileend"
      case 30: // "do"
      case 31: // "doend"
      case 32: // "comment"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case 35: // command
      case 39: // assignment
      case 43: // statement
      case 44: // if_statement
      case 45: // for_statement
      case 46: // while_statement
        value.move<  Synthetic::Command  > (that.value);
        break;

      case 36: // condition
        value.move<  bool  > (that.value);
        break;

      case 38: // id
      case 41: // factor
        value.move<  double  > (that.value);
        break;

      case 42: // statements
        value.move<  std::vector<Synthetic::Command>  > (that.value);
        break;

      case 40: // term
        value.move<  std::vector<double>  > (that.value);
        break;

      case 37: // expression
        value.move<  std::vector<long long int>  > (that.value);
        break;

      case 5: // "floatingPoint"
        value.move< float > (that.value);
        break;

      case 6: // "boolean"
      case 7: // "number"
        value.move< long long int > (that.value);
        break;

      case 4: // "identifier"
      case 14: // "geometric_op"
      case 15: // "arithmetic_op"
      case 16: // "relational_op"
      case 17: // "operator"
      case 18: // "incrementing"
      case 19: // "decrementing"
      case 20: // "keyword"
      case 21: // "primitive_type"
      case 22: // "if"
      case 23: // "else"
      case 24: // "then"
      case 25: // "endif"
      case 26: // "for"
      case 27: // "forend"
      case 28: // "while"
      case 29: // "whileend"
      case 30: // "do"
      case 31: // "doend"
      case 32: // "comment"
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
   Parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   Parser ::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YYUSE (yykind);
        yyo << ')';
      }
  }
#endif

  void
   Parser ::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
   Parser ::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
   Parser ::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   Parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   Parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   Parser ::debug_level_type
   Parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   Parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

   Parser ::state_type
   Parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
   Parser ::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
   Parser ::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
   Parser ::operator() ()
  {
    return parse ();
  }

  int
   Parser ::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (scanner, driver));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 35: // command
      case 39: // assignment
      case 43: // statement
      case 44: // if_statement
      case 45: // for_statement
      case 46: // while_statement
        yylhs.value.emplace<  Synthetic::Command  > ();
        break;

      case 36: // condition
        yylhs.value.emplace<  bool  > ();
        break;

      case 38: // id
      case 41: // factor
        yylhs.value.emplace<  double  > ();
        break;

      case 42: // statements
        yylhs.value.emplace<  std::vector<Synthetic::Command>  > ();
        break;

      case 40: // term
        yylhs.value.emplace<  std::vector<double>  > ();
        break;

      case 37: // expression
        yylhs.value.emplace<  std::vector<long long int>  > ();
        break;

      case 5: // "floatingPoint"
        yylhs.value.emplace< float > ();
        break;

      case 6: // "boolean"
      case 7: // "number"
        yylhs.value.emplace< long long int > ();
        break;

      case 4: // "identifier"
      case 14: // "geometric_op"
      case 15: // "arithmetic_op"
      case 16: // "relational_op"
      case 17: // "operator"
      case 18: // "incrementing"
      case 19: // "decrementing"
      case 20: // "keyword"
      case 21: // "primitive_type"
      case 22: // "if"
      case 23: // "else"
      case 24: // "then"
      case 25: // "endif"
      case 26: // "for"
      case 27: // "forend"
      case 28: // "while"
      case 29: // "whileend"
      case 30: // "do"
      case 31: // "doend"
      case 32: // "comment"
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 207 "src/parser.y"
            { driver.clear(); }
#line 872 "src/parser.cpp"
    break;

  case 3:
#line 209 "src/parser.y"
            {
                /*const Command &cmd = $2;*/
                /*cout << "command parsed, updating AST" << endl;*/
                /*driver.addCommand(cmd);*/
                /*cout << endl << "prompt> ";*/
            }
#line 883 "src/parser.cpp"
    break;

  case 4:
#line 216 "src/parser.y"
        {
            /*std::cout << "command parsed: [expression], updating AST..." << std::endl;*/
            const Command c = Command("expression", yystack_[0].value.as <  std::vector<long long int>  > ());
            driver.addCommand(c);

        }
#line 894 "src/parser.cpp"
    break;

  case 5:
#line 223 "src/parser.y"
        {
            std::vector<long long int> container;

            for(auto element : yystack_[0].value.as <  std::vector<double>  > ()){ container.push_back((long long int)element); }
            
            const Command c = Command("term", container);
            driver.addCommand(c);
        }
#line 907 "src/parser.cpp"
    break;

  case 6:
#line 232 "src/parser.y"
                     {}
#line 913 "src/parser.cpp"
    break;

  case 7:
#line 233 "src/parser.y"
                             {}
#line 919 "src/parser.cpp"
    break;

  case 8:
#line 235 "src/parser.y"
        {
            for(auto element : yystack_[0].value.as <  std::vector<Synthetic::Command>  > ()){
                driver.addCommand(element);
            }
        }
#line 929 "src/parser.cpp"
    break;

  case 9:
#line 242 "src/parser.y"
            {
                cout << "*** STOP RUN ***" << endl;
                cout << driver.str() << endl;
            }
#line 938 "src/parser.cpp"
    break;

  case 10:
#line 247 "src/parser.y"
            {
                std::vector<long long int> v = {(long long int)yystack_[0].value.as <  bool  > ()};
                const Command cmd = Command("condition", v);
                /*cout << "command parsed, updating AST" << endl;*/
                driver.addCommand(cmd);
            }
#line 949 "src/parser.cpp"
    break;

  case 11:
#line 254 "src/parser.y"
            {
                std::vector<float> c = {yystack_[0].value.as < float > ()};
                const Command cmd = Command("float", c);
                /*cout << "command parsed, updating AST" << endl;*/
                driver.addCommand(cmd);
            }
#line 960 "src/parser.cpp"
    break;

  case 12:
#line 276 "src/parser.y"
        {
            string &id = yystack_[2].value.as < std::string > ();
            cout << "ID: " << id << endl;
            yylhs.value.as <  Synthetic::Command  > () = Command(id);
        }
#line 970 "src/parser.cpp"
    break;

  case 13:
#line 282 "src/parser.y"
        {
          yylhs.value.as <  Synthetic::Command  > () = Command("keyword");
        }
#line 978 "src/parser.cpp"
    break;

  case 14:
#line 286 "src/parser.y"
        {
            yylhs.value.as <  Synthetic::Command  > () = Command("comment");
        }
#line 986 "src/parser.cpp"
    break;

  case 15:
#line 297 "src/parser.y"
    {
        std::cout << "expression (" << yystack_[2].value.as <  std::vector<long long int>  > ().back() << ") RELATIONAL_OP (" << yystack_[1].value.as < std::string > () << ") expression" <<  yystack_[0].value.as <  std::vector<long long int>  > ().back() << std::endl;
        long long int a = yystack_[2].value.as <  std::vector<long long int>  > ().back();
        long long int b = yystack_[0].value.as <  std::vector<long long int>  > ().back();
        // TODO
        // throw error if operator not found or condition does not evaluate
        yylhs.value.as <  bool  > () = compare(a, b, yystack_[1].value.as < std::string > ());

    }
#line 1000 "src/parser.cpp"
    break;

  case 16:
#line 307 "src/parser.y"
    {
        std::cout << "LEFTPAR expression (" << yystack_[3].value.as <  std::vector<long long int>  > ().back() << ") RELATIONAL_OP (" << yystack_[2].value.as < std::string > () << ") expression (" << yystack_[1].value.as <  std::vector<long long int>  > ().back() << ") RIGHTPAR" << std::endl;

        long long int a = yystack_[3].value.as <  std::vector<long long int>  > ().back();
        long long int b = yystack_[1].value.as <  std::vector<long long int>  > ().back();
        // TODO
        // throw error if operator not found or condition does not evaluate
        yylhs.value.as <  bool  > () = compare(a, b, yystack_[2].value.as < std::string > ());
    }
#line 1014 "src/parser.cpp"
    break;

  case 17:
#line 317 "src/parser.y"
    {
        std::cout << "BOOLEAN (" << yystack_[0].value.as < long long int > () << ")" << std::endl;
        yylhs.value.as <  bool  > () = (yystack_[0].value.as < long long int > ()) ? true : false;
    }
#line 1023 "src/parser.cpp"
    break;

  case 18:
#line 322 "src/parser.y"
    {
        std::cout << "LEFTPAR BOOLEAN (" << yystack_[1].value.as < long long int > () << ") RIGHTPAR" << std::endl;
        yylhs.value.as <  bool  > () = (yystack_[1].value.as < long long int > ()) ? true : false;
    }
#line 1032 "src/parser.cpp"
    break;

  case 19:
#line 344 "src/parser.y"
        {
            std::cout << "NUMBER (" << yystack_[0].value.as < long long int > ()  << ") ";
            long long int number = yystack_[0].value.as < long long int > ();
            yylhs.value.as <  std::vector<long long int>  > () = std::vector<long long int>();
            yylhs.value.as <  std::vector<long long int>  > ().push_back(number);
        }
#line 1043 "src/parser.cpp"
    break;

  case 20:
#line 351 "src/parser.y"
        {
            std::cout << "<expression> ARITHMETIC_OP (" << yystack_[1].value.as < std::string > () << ") NUMBER (" << yystack_[0].value.as < long long int > ()  << ")" << std::endl << std::endl;
            long long int number = yystack_[0].value.as < long long int > ();
            std::vector<long long int> &args = yystack_[2].value.as <  std::vector<long long int>  > ();
            std::string oper = yystack_[1].value.as < std::string > ();

            if(!args.empty()){
                long long int top = args.back();
                args.pop_back();
                args.push_back(compute(top, number, oper));
            }
            else { args.push_back(number); }
            yylhs.value.as <  std::vector<long long int>  > () = args;
        }
#line 1062 "src/parser.cpp"
    break;

  case 21:
#line 366 "src/parser.y"
    {
        std::cout << "LEFTPAR <expression> RIGHTPAR" << std::endl;
        yylhs.value.as <  std::vector<long long int>  > () = yystack_[1].value.as <  std::vector<long long int>  > ();
    }
#line 1071 "src/parser.cpp"
    break;

  case 22:
#line 374 "src/parser.y"
     {
        std::cout << "ID ( " << yystack_[0].value.as < std::string > () << ")" << std::endl;
        std::string variable = yystack_[0].value.as < std::string > ();
        double value = get_variable(symbolTable, variable);
        if(value == std::numeric_limits<double>::infinity()){
            char buff[BUFSIZ];
            snprintf(buff, sizeof(buff), "[ERROR] Variable %s is undefined", variable.c_str());
            throw VariableNotDeclaredException(buff, __FILE__, __LINE__, __FUNCTION__, "Nothing");
        } else {
            std::cout << "variable [" << variable << "] with value of --> " << "[" << value << "]" << std::endl;
        }
        yylhs.value.as <  double  > () = value;
     }
#line 1089 "src/parser.cpp"
    break;

  case 23:
#line 390 "src/parser.y"
    {
        std::cout << "PRIMITIVE_TYPE (" << yystack_[2].value.as < std::string > () << ") " << "ID (" << yystack_[1].value.as < std::string > () << ") " << "SEMICOLON (;)" << std::endl;
        symbolTable[yystack_[1].value.as < std::string > ()] = 0;
    }
#line 1098 "src/parser.cpp"
    break;

  case 24:
#line 396 "src/parser.y"
    {
        std::cout << "PRIMITIVE_TYPE (" << yystack_[4].value.as < std::string > () << ") " << "ID (" << yystack_[3].value.as < std::string > () << ")" << " ASSIGN (=) expression (" << yystack_[1].value.as <  std::vector<long long int>  > ().back() << ") SEMICOLON (;)" << std::endl;
        long long int value = yystack_[1].value.as <  std::vector<long long int>  > ().back();
        symbolTable[yystack_[3].value.as < std::string > ()] = (float)value;
    }
#line 1108 "src/parser.cpp"
    break;

  case 25:
#line 402 "src/parser.y"
    {
        std::cout << "ID (" << yystack_[3].value.as < std::string > () << ") ASSIGN (=) expresion (" << yystack_[1].value.as <  std::vector<long long int>  > ().back() << ") SEMICOLON (;)" << std::endl;
        long long int value = yystack_[1].value.as <  std::vector<long long int>  > ().back();
        symbolTable[yystack_[3].value.as < std::string > ()] = (float)value;
    }
#line 1118 "src/parser.cpp"
    break;

  case 26:
#line 408 "src/parser.y"
    {
        std::cout << "PRIMITIVE_TYPE (" << yystack_[4].value.as < std::string > () << ") ID (" << yystack_[3].value.as < std::string > () << ") ASSIGN (=) term (" << yystack_[1].value.as <  std::vector<double>  > ().back() << ") SEMICOLON (;)" << std::endl;
        double value = yystack_[1].value.as <  std::vector<double>  > ().back();
        symbolTable[yystack_[3].value.as < std::string > ()] = (float)value;
    }
#line 1128 "src/parser.cpp"
    break;

  case 27:
#line 414 "src/parser.y"
    {
        std::cout << "ID (" << yystack_[3].value.as < std::string > () << ") ASSIGN (=) term (" <<  yystack_[1].value.as <  std::vector<double>  > ().back() << ") SEMICOLON (;)" << std::endl;
        double value = yystack_[1].value.as <  std::vector<double>  > ().back();
        symbolTable[yystack_[3].value.as < std::string > ()] = (float)value;
    }
#line 1138 "src/parser.cpp"
    break;

  case 28:
#line 430 "src/parser.y"
              {
        std::cout << "factor (" << yystack_[0].value.as <  double  > () << ")" << std::endl;
        double number = yystack_[0].value.as <  double  > ();
        yylhs.value.as <  std::vector<double>  > () = std::vector<double>();
        yylhs.value.as <  std::vector<double>  > ().push_back(number);
       }
#line 1149 "src/parser.cpp"
    break;

  case 29:
#line 437 "src/parser.y"
        {
            std::cout << "term (" << yystack_[2].value.as <  std::vector<double>  > ().back() << ") GEOMETRIC_OP (" << yystack_[1].value.as < std::string > () << ") factor (" << yystack_[0].value.as <  double  > () << std::endl;
            double number = yystack_[0].value.as <  double  > ();
            std::vector<double> &args = yystack_[2].value.as <  std::vector<double>  > ();
            std::string oper = yystack_[1].value.as < std::string > ();

            if(!args.empty()){
                double top = args.back();
                args.pop_back();
                args.push_back(compute(top, number, oper));
            }
            else { args.push_back(number); }
            yylhs.value.as <  std::vector<double>  > () = args;
        }
#line 1168 "src/parser.cpp"
    break;

  case 30:
#line 452 "src/parser.y"
    {
        std::cout << "LEFTPAR term (" << yystack_[1].value.as <  std::vector<double>  > ().back() << ") RIGHTPAR" << std::endl;
        yylhs.value.as <  std::vector<double>  > () = yystack_[1].value.as <  std::vector<double>  > ();
    }
#line 1177 "src/parser.cpp"
    break;

  case 31:
#line 457 "src/parser.y"
    {
        std::cout << "id (" << yystack_[0].value.as <  double  > () << ")" << std::endl;
        yylhs.value.as <  std::vector<double>  > () = std::vector<double>(yystack_[0].value.as <  double  > ());
    }
#line 1186 "src/parser.cpp"
    break;

  case 32:
#line 464 "src/parser.y"
        {
          std::cout  << "id (" << yystack_[1].value.as <  double  > () << ") ID (" << yystack_[0].value.as < std::string > () << ")" << std::endl;
          yylhs.value.as <  double  > () = yystack_[1].value.as <  double  > ();
        }
#line 1195 "src/parser.cpp"
    break;

  case 33:
#line 469 "src/parser.y"
        {
            std::cout << "NUMBER (" << yystack_[0].value.as < long long int > () << ")" << std::endl;
            yylhs.value.as <  double  > () = yystack_[0].value.as < long long int > ();
        }
#line 1204 "src/parser.cpp"
    break;

  case 34:
#line 474 "src/parser.y"
        {
            std::cout << "LEFTPAR expression (" << yystack_[1].value.as <  std::vector<long long int>  > ().back() << ") RIGHTPAR" << std::endl;
            yylhs.value.as <  double  > () = yystack_[1].value.as <  std::vector<long long int>  > ().back();
        }
#line 1213 "src/parser.cpp"
    break;

  case 36:
#line 482 "src/parser.y"
        {
            std::cout << "<statement> ";
            Synthetic::Command c("statement");
            std::vector<Synthetic::Command> container = {c};
            yylhs.value.as <  std::vector<Synthetic::Command>  > () = container;
        }
#line 1224 "src/parser.cpp"
    break;

  case 37:
#line 491 "src/parser.y"
    {
        std::cout << "<assignment> ";
        yylhs.value.as <  Synthetic::Command  > () = Command("statement");
    }
#line 1233 "src/parser.cpp"
    break;

  case 38:
#line 496 "src/parser.y"
    {
        std::cout  << "<if_statement>";
        yylhs.value.as <  Synthetic::Command  > () = Command("if_statement");
    }
#line 1242 "src/parser.cpp"
    break;

  case 39:
#line 501 "src/parser.y"
    {
        std::cout << "<for_statement>";
        yylhs.value.as <  Synthetic::Command  > () = Command("for_statement");
    }
#line 1251 "src/parser.cpp"
    break;

  case 40:
#line 506 "src/parser.y"
    {
        std::cout  << "<while_statement>";
        yylhs.value.as <  Synthetic::Command  > () = Command("while_statement");
    }
#line 1260 "src/parser.cpp"
    break;

  case 41:
#line 512 "src/parser.y"
                                                  {
    std::cout << "IF <condition> ";
    std::cout << " THEN <statements> ";
    std::cout << " ENDIF";
}
#line 1270 "src/parser.cpp"
    break;

  case 42:
#line 517 "src/parser.y"
                                                                 {
                std::cout << "IF <condition>";
                std::cout << " THEN <statements> ";
                std::cout << " ELSE <statements> ";
                std::cout << " ENDIF";
            }
#line 1281 "src/parser.cpp"
    break;

  case 43:
#line 527 "src/parser.y"
    {
        /*
        * for (int i = 0; i < 10; ++i)
        *    int value = 0;
        * forend
        */
        std::cout << "FOR LEFTPAR PRIMITIVE_TYPE (" << yystack_[12].value.as < std::string > () << ") ID (" << yystack_[11].value.as < std::string > () << ") ASSIGN (=) <expression> ";
        std::cout << " SEMICOLON (;) ID (" << yystack_[7].value.as < std::string > () << ") RELATIONAL_OP (" << yystack_[6].value.as < std::string > () << ")" << "<expression> ";
        std::cout << "SEMICOLON (;) ID_INC (" << yystack_[5].value.as <  std::vector<long long int>  > ().back() << ") RIGHTPAR <statements> ";
        std::cout << " FOREND " << std::endl;

    }
#line 1298 "src/parser.cpp"
    break;

  case 44:
#line 540 "src/parser.y"
    {

        /*
        * for (int i = 0; i < 10; --i)
        *    int value = 0;
        * forend
        */
    }
#line 1311 "src/parser.cpp"
    break;

  case 45:
#line 550 "src/parser.y"
                                                      {}
#line 1317 "src/parser.cpp"
    break;

  case 46:
#line 551 "src/parser.y"
                                                       {}
#line 1323 "src/parser.cpp"
    break;

  case 47:
#line 552 "src/parser.y"
                                                        {}
#line 1329 "src/parser.cpp"
    break;


#line 1333 "src/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
   Parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
   Parser ::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
   Parser ::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  //  Parser ::context.
   Parser ::context::context (const  Parser & yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
   Parser ::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        int yychecklim = yylast_ - yyn + 1;
        int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }



  int
   Parser ::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
   Parser ::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char  Parser ::yypact_ninf_ = -9;

  const signed char  Parser ::yytable_ninf_ = -35;

  const short
   Parser ::yypact_[] =
  {
      -9,    14,    -9,    76,    -9,    -9,    -8,    74,    -9,    -9,
      12,   112,    19,   112,    29,    -9,    -9,    -9,   100,    11,
      -9,    55,    -9,    -9,    29,    -9,    -9,    -9,    91,    77,
      -9,    82,    91,    -4,    85,    -5,    27,    -9,   115,   104,
     100,    83,    29,   126,    -9,   103,    66,   123,   117,    -9,
      93,    -9,    96,    31,    -9,    -9,    22,   118,   117,    -9,
      91,    -9,   117,     8,    29,   129,   105,   112,   112,    -9,
     120,    -9,   117,    85,    -9,    -9,    -9,    38,    97,    42,
      59,    -9,    80,   133,    -9,   106,    45,    68,    -9,    -9,
      -9,    29,    -9,   117,    -9,    -9,    -9,   113,    98,    -9,
     135,   124,   117,   102,   108,   132,   134,    29,    29,   119,
     121,    -9,    -9
  };

  const signed char
   Parser ::yydefact_[] =
  {
       2,     0,     1,    22,    11,    17,    19,     0,     9,    13,
       0,     0,     0,     0,     0,    14,     3,    10,     4,     6,
       7,     5,    28,     8,    36,    38,    39,    40,     0,     0,
      22,     0,     0,     0,    31,     0,     0,    19,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,    32,
       0,    35,     0,     0,    12,    18,     0,    21,     0,    30,
       0,    23,     0,     0,     0,     0,     0,     0,     0,    20,
      15,    33,     0,     0,    29,    25,    27,     0,     0,     0,
       0,    21,     0,     0,    45,     0,     0,     0,    16,    24,
      26,     0,    41,     0,    47,    46,    34,     0,     0,    42,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    43,    44
  };

  const short
   Parser ::yypgoto_[] =
  {
      -9,    -9,    -9,    -3,     0,     2,   141,     1,    94,    -1,
     131,    -9,    -9,    -9
  };

  const signed char
   Parser ::yydefgoto_[] =
  {
      -1,     1,    16,    17,    40,    34,    44,    35,    22,    51,
      24,    25,    26,    27
  };

  const signed char
   Parser ::yytable_[] =
  {
      23,    18,    21,    19,    59,    57,   -33,    33,    39,    50,
      42,    47,    58,    45,     2,    49,    36,    81,     3,     4,
       5,     6,     7,    47,    58,   -31,     8,    41,    52,    53,
      60,    57,    56,    43,     9,    10,    11,    47,    63,    61,
      12,    66,    13,    76,    14,    50,    15,    88,    70,    43,
      10,    11,    73,    47,    90,    12,    50,    13,    77,    14,
      78,    79,    80,    82,    85,    86,    10,    11,    81,    50,
      43,    12,    87,    13,    47,    14,    95,    96,    30,    28,
      31,     6,    32,    47,    29,    66,    54,    10,    11,    49,
      97,    55,    12,    98,    68,    30,    14,    30,     6,    32,
      71,    72,   103,    91,    65,    92,   109,   110,    75,    89,
     100,    47,    47,    47,   104,    47,    48,    47,     5,    37,
      38,    31,    37,    62,    37,    62,   105,   106,    64,    28,
      69,    67,   -34,    83,    84,    47,    93,    94,    99,   101,
     102,   107,    20,   108,    74,    46,   111,     0,   112
  };

  const signed char
   Parser ::yycheck_[] =
  {
       1,     1,     1,     1,     9,     9,    14,     7,    11,    14,
      13,    15,    16,    14,     0,     4,     4,     9,     4,     5,
       6,     7,     8,    15,    16,    14,    12,     8,    28,    28,
       3,     9,    32,     4,    20,    21,    22,    15,    38,    12,
      26,    42,    28,    12,    30,    14,    32,     9,    48,     4,
      21,    22,    50,    15,    12,    26,    14,    28,    58,    30,
      60,    60,    62,    64,    67,    68,    21,    22,     9,    14,
       4,    26,    72,    28,    15,    30,    31,     9,     4,     3,
       6,     7,     8,    15,     8,    86,     9,    21,    22,     4,
      91,     9,    26,    93,    28,     4,    30,     4,     7,     8,
       7,     8,   102,    23,    21,    25,   107,   108,    12,    12,
      12,    15,    15,    15,    12,    15,    16,    15,     6,     7,
       8,     6,     7,     8,     7,     8,    18,    19,    24,     3,
       7,    28,    14,     4,    29,    15,     3,    31,    25,     4,
      16,     9,     1,     9,    50,    14,    27,    -1,    27
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,    34,     0,     4,     5,     6,     7,     8,    12,    20,
      21,    22,    26,    28,    30,    32,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,     3,     8,
       4,     6,     8,    37,    38,    40,     4,     7,     8,    36,
      37,     8,    36,     4,    39,    42,    43,    15,    16,     4,
      14,    42,    37,    40,     9,     9,    37,     9,    16,     9,
       3,    12,     8,    37,    24,    21,    42,    28,    28,     7,
      37,     7,     8,    38,    41,    12,    12,    37,    37,    40,
      37,     9,    42,     4,    29,    36,    36,    37,     9,    12,
      12,    23,    25,     3,    31,    31,     9,    42,    37,    25,
      12,     4,    16,    37,    12,    18,    19,     9,     9,    42,
      42,    27,    27
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    33,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    35,    35,    35,    36,    36,    36,    36,    37,
      37,    37,    38,    39,    39,    39,    39,    39,    40,    40,
      40,    40,    41,    41,    41,    42,    42,    43,    43,    43,
      43,    44,    44,    45,    45,    46,    46,    46
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     3,     1,     1,     3,     5,     1,     3,     1,
       3,     3,     1,     3,     5,     4,     5,     4,     1,     3,
       3,     1,     2,     1,     3,     2,     1,     1,     1,     1,
       1,     5,     7,    15,    15,     4,     5,     5
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\"assignment\"",
  "\"identifier\"", "\"floatingPoint\"", "\"boolean\"", "\"number\"",
  "\"leftpar\"", "\"rightpar\"", "\"leftcurly\"", "\"rightcurly\"",
  "\"semicolon\"", "\"comma\"", "\"geometric_op\"", "\"arithmetic_op\"",
  "\"relational_op\"", "\"operator\"", "\"incrementing\"",
  "\"decrementing\"", "\"keyword\"", "\"primitive_type\"", "\"if\"",
  "\"else\"", "\"then\"", "\"endif\"", "\"for\"", "\"forend\"",
  "\"while\"", "\"whileend\"", "\"do\"", "\"doend\"", "\"comment\"",
  "$accept", "program", "command", "condition", "expression", "id",
  "assignment", "term", "factor", "statements", "statement",
  "if_statement", "for_statement", "while_statement", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   207,   207,   208,   215,   222,   232,   233,   234,   241,
     246,   253,   275,   281,   285,   296,   306,   316,   321,   343,
     350,   365,   373,   389,   395,   401,   407,   413,   430,   436,
     451,   456,   463,   468,   473,   480,   481,   490,   495,   500,
     505,   512,   517,   525,   539,   550,   551,   552
  };

  void
   Parser ::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
   Parser ::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 37 "src/parser.y"
} //  Synthetic 
#line 1874 "src/parser.cpp"

#line 555 "src/parser.y"


// Bison expects us to provide implementation - otherwise linker complains
void Synthetic::Parser::error(const location &loc , const std::string &message) {
        
        // Location should be initialized inside scanner action, but is not in this example.
        // Let's grab location directly from driver class.
	// cout << "Error: " << message << endl << "Location: " << loc << endl;
	
        cout << "Error: " << message << endl << "Error location: " << driver.location() << endl;
}
