// A Bison parser, made by GNU Bison 3.6.4.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file src/parser.hpp
 ** Define the  Synthetic ::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_SRC_PARSER_HPP_INCLUDED
# define YY_YY_SRC_PARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 39 "src/parser.y"


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
    #include "templateCommand.cpp"

    using namespace std;

    namespace Synthetic {
        class Scanner;
        class Interpreter;
    }



#line 76 "src/parser.hpp"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 37 "src/parser.y"
namespace  Synthetic  {
#line 211 "src/parser.hpp"




  /// A Bison parser.
  class  Parser 
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    semantic_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    semantic_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // command
      // assignment
      // statement
      // if_statement
      // for_statement
      // while_statement
      char dummy1[sizeof ( Synthetic::Command )];

      // condition
      char dummy2[sizeof ( bool )];

      // id
      // factor
      char dummy3[sizeof ( double )];

      // statements
      char dummy4[sizeof ( std::vector<Synthetic::Command> )];

      // term
      char dummy5[sizeof ( std::vector<double> )];

      // expression
      char dummy6[sizeof ( std::vector<long long int> )];

      // "floatingPoint"
      char dummy7[sizeof (float)];

      // "boolean"
      // "number"
      char dummy8[sizeof (long long int)];

      // "identifier"
      // "geometric_op"
      // "arithmetic_op"
      // "relational_op"
      // "operator"
      // "incrementing"
      // "decrementing"
      // "keyword"
      // "primitive_type"
      // "if"
      // "else"
      // "then"
      // "endif"
      // "for"
      // "forend"
      // "while"
      // "whileend"
      // "do"
      // "doend"
      // "comment"
      char dummy9[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        TOKEN_YYEMPTY = -2,
    TOKEN_END = 0,                 // "end of file"
    TOKEN_YYerror = 256,           // error
    TOKEN_YYUNDEF = 257,           // "invalid token"
    TOKEN_ASSIGN = 258,            // "assignment"
    TOKEN_ID = 259,                // "identifier"
    TOKEN_FLOAT = 260,             // "floatingPoint"
    TOKEN_BOOLEAN = 261,           // "boolean"
    TOKEN_NUMBER = 262,            // "number"
    TOKEN_LEFTPAR = 263,           // "leftpar"
    TOKEN_RIGHTPAR = 264,          // "rightpar"
    TOKEN_LEFT_CURLY = 265,        // "leftcurly"
    TOKEN_RIGHT_CURLY = 266,       // "rightcurly"
    TOKEN_SEMICOLON = 267,         // "semicolon"
    TOKEN_COMMA = 268,             // "comma"
    TOKEN_GEOMETRIC_OP = 269,      // "geometric_op"
    TOKEN_ARITHMETIC_OP = 270,     // "arithmetic_op"
    TOKEN_RELATIONAL_OP = 271,     // "relational_op"
    TOKEN_OPERATOR = 272,          // "operator"
    TOKEN_ID_INC = 273,            // "incrementing"
    TOKEN_ID_DEC = 274,            // "decrementing"
    TOKEN_KEYWORD = 275,           // "keyword"
    TOKEN_PRIMITIVE_TYPE = 276,    // "primitive_type"
    TOKEN_IF = 277,                // "if"
    TOKEN_ELSE = 278,              // "else"
    TOKEN_THEN = 279,              // "then"
    TOKEN_ENDIF = 280,             // "endif"
    TOKEN_FOR = 281,               // "for"
    TOKEN_FOREND = 282,            // "forend"
    TOKEN_WHILE = 283,             // "while"
    TOKEN_WHILEEND = 284,          // "whileend"
    TOKEN_DO = 285,                // "do"
    TOKEN_DOEND = 286,             // "doend"
    TOKEN_COMMENT = 287            // "comment"
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::yytokentype token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 33, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_ASSIGN = 3,                            // "assignment"
        S_ID = 4,                                // "identifier"
        S_FLOAT = 5,                             // "floatingPoint"
        S_BOOLEAN = 6,                           // "boolean"
        S_NUMBER = 7,                            // "number"
        S_LEFTPAR = 8,                           // "leftpar"
        S_RIGHTPAR = 9,                          // "rightpar"
        S_LEFT_CURLY = 10,                       // "leftcurly"
        S_RIGHT_CURLY = 11,                      // "rightcurly"
        S_SEMICOLON = 12,                        // "semicolon"
        S_COMMA = 13,                            // "comma"
        S_GEOMETRIC_OP = 14,                     // "geometric_op"
        S_ARITHMETIC_OP = 15,                    // "arithmetic_op"
        S_RELATIONAL_OP = 16,                    // "relational_op"
        S_OPERATOR = 17,                         // "operator"
        S_ID_INC = 18,                           // "incrementing"
        S_ID_DEC = 19,                           // "decrementing"
        S_KEYWORD = 20,                          // "keyword"
        S_PRIMITIVE_TYPE = 21,                   // "primitive_type"
        S_IF = 22,                               // "if"
        S_ELSE = 23,                             // "else"
        S_THEN = 24,                             // "then"
        S_ENDIF = 25,                            // "endif"
        S_FOR = 26,                              // "for"
        S_FOREND = 27,                           // "forend"
        S_WHILE = 28,                            // "while"
        S_WHILEEND = 29,                         // "whileend"
        S_DO = 30,                               // "do"
        S_DOEND = 31,                            // "doend"
        S_COMMENT = 32,                          // "comment"
        S_YYACCEPT = 33,                         // $accept
        S_program = 34,                          // program
        S_command = 35,                          // command
        S_condition = 36,                        // condition
        S_expression = 37,                       // expression
        S_id = 38,                               // id
        S_assignment = 39,                       // assignment
        S_term = 40,                             // term
        S_factor = 41,                           // factor
        S_statements = 42,                       // statements
        S_statement = 43,                        // statement
        S_if_statement = 44,                     // if_statement
        S_for_statement = 45,                    // for_statement
        S_while_statement = 46                   // while_statement
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case 35: // command
      case 39: // assignment
      case 43: // statement
      case 44: // if_statement
      case 45: // for_statement
      case 46: // while_statement
        value.move<  Synthetic::Command  > (std::move (that.value));
        break;

      case 36: // condition
        value.move<  bool  > (std::move (that.value));
        break;

      case 38: // id
      case 41: // factor
        value.move<  double  > (std::move (that.value));
        break;

      case 42: // statements
        value.move<  std::vector<Synthetic::Command>  > (std::move (that.value));
        break;

      case 40: // term
        value.move<  std::vector<double>  > (std::move (that.value));
        break;

      case 37: // expression
        value.move<  std::vector<long long int>  > (std::move (that.value));
        break;

      case 5: // "floatingPoint"
        value.move< float > (std::move (that.value));
        break;

      case 6: // "boolean"
      case 7: // "number"
        value.move< long long int > (std::move (that.value));
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
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t,  Synthetic::Command && v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const  Synthetic::Command & v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t,  bool && v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const  bool & v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t,  double && v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const  double & v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t,  std::vector<Synthetic::Command> && v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const  std::vector<Synthetic::Command> & v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t,  std::vector<double> && v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const  std::vector<double> & v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t,  std::vector<long long int> && v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const  std::vector<long long int> & v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, float&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const float& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, long long int&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const long long int& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case 35: // command
      case 39: // assignment
      case 43: // statement
      case 44: // if_statement
      case 45: // for_statement
      case 46: // while_statement
        value.template destroy<  Synthetic::Command  > ();
        break;

      case 36: // condition
        value.template destroy<  bool  > ();
        break;

      case 38: // id
      case 41: // factor
        value.template destroy<  double  > ();
        break;

      case 42: // statements
        value.template destroy<  std::vector<Synthetic::Command>  > ();
        break;

      case 40: // term
        value.template destroy<  std::vector<double>  > ();
        break;

      case 37: // expression
        value.template destroy<  std::vector<long long int>  > ();
        break;

      case 5: // "floatingPoint"
        value.template destroy< float > ();
        break;

      case 6: // "boolean"
      case 7: // "number"
        value.template destroy< long long int > ();
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
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return  Parser ::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// Default constructor.
      by_kind ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that);
#endif

      /// Copy constructor.
      by_kind (const by_kind& that);

      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
      {
        YY_ASSERT (tok == token::TOKEN_END || tok == token::TOKEN_YYerror || tok == token::TOKEN_YYUNDEF || tok == token::TOKEN_ASSIGN || tok == token::TOKEN_LEFTPAR || tok == token::TOKEN_RIGHTPAR || tok == token::TOKEN_LEFT_CURLY || tok == token::TOKEN_RIGHT_CURLY || tok == token::TOKEN_SEMICOLON || tok == token::TOKEN_COMMA);
      }
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
      {
        YY_ASSERT (tok == token::TOKEN_END || tok == token::TOKEN_YYerror || tok == token::TOKEN_YYUNDEF || tok == token::TOKEN_ASSIGN || tok == token::TOKEN_LEFTPAR || tok == token::TOKEN_RIGHTPAR || tok == token::TOKEN_LEFT_CURLY || tok == token::TOKEN_RIGHT_CURLY || tok == token::TOKEN_SEMICOLON || tok == token::TOKEN_COMMA);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, float v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::TOKEN_FLOAT);
      }
#else
      symbol_type (int tok, const float& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::TOKEN_FLOAT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, long long int v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::TOKEN_BOOLEAN || tok == token::TOKEN_NUMBER);
      }
#else
      symbol_type (int tok, const long long int& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::TOKEN_BOOLEAN || tok == token::TOKEN_NUMBER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::TOKEN_ID || tok == token::TOKEN_GEOMETRIC_OP || tok == token::TOKEN_ARITHMETIC_OP || tok == token::TOKEN_RELATIONAL_OP || tok == token::TOKEN_OPERATOR || tok == token::TOKEN_ID_INC || tok == token::TOKEN_ID_DEC || tok == token::TOKEN_KEYWORD || tok == token::TOKEN_PRIMITIVE_TYPE || tok == token::TOKEN_IF || tok == token::TOKEN_ELSE || tok == token::TOKEN_THEN || tok == token::TOKEN_ENDIF || tok == token::TOKEN_FOR || tok == token::TOKEN_FOREND || tok == token::TOKEN_WHILE || tok == token::TOKEN_WHILEEND || tok == token::TOKEN_DO || tok == token::TOKEN_DOEND || tok == token::TOKEN_COMMENT);
      }
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::TOKEN_ID || tok == token::TOKEN_GEOMETRIC_OP || tok == token::TOKEN_ARITHMETIC_OP || tok == token::TOKEN_RELATIONAL_OP || tok == token::TOKEN_OPERATOR || tok == token::TOKEN_ID_INC || tok == token::TOKEN_ID_DEC || tok == token::TOKEN_KEYWORD || tok == token::TOKEN_PRIMITIVE_TYPE || tok == token::TOKEN_IF || tok == token::TOKEN_ELSE || tok == token::TOKEN_THEN || tok == token::TOKEN_ENDIF || tok == token::TOKEN_FOR || tok == token::TOKEN_FOREND || tok == token::TOKEN_WHILE || tok == token::TOKEN_WHILEEND || tok == token::TOKEN_DO || tok == token::TOKEN_DOEND || tok == token::TOKEN_COMMENT);
      }
#endif
    };

    /// Build a parser object.
     Parser  (Synthetic::Scanner &scanner_yyarg, Synthetic::Interpreter &driver_yyarg);
    virtual ~ Parser  ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
     Parser  (const  Parser &) = delete;
    /// Non copyable.
     Parser & operator= (const  Parser &) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::TOKEN_END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::TOKEN_END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::TOKEN_YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::TOKEN_YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::TOKEN_YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::TOKEN_YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN (location_type l)
      {
        return symbol_type (token::TOKEN_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN (const location_type& l)
      {
        return symbol_type (token::TOKEN_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ID (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_ID, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ID (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_ID, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOAT (float v, location_type l)
      {
        return symbol_type (token::TOKEN_FLOAT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FLOAT (const float& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_FLOAT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOLEAN (long long int v, location_type l)
      {
        return symbol_type (token::TOKEN_BOOLEAN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BOOLEAN (const long long int& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_BOOLEAN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMBER (long long int v, location_type l)
      {
        return symbol_type (token::TOKEN_NUMBER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NUMBER (const long long int& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_NUMBER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFTPAR (location_type l)
      {
        return symbol_type (token::TOKEN_LEFTPAR, std::move (l));
      }
#else
      static
      symbol_type
      make_LEFTPAR (const location_type& l)
      {
        return symbol_type (token::TOKEN_LEFTPAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHTPAR (location_type l)
      {
        return symbol_type (token::TOKEN_RIGHTPAR, std::move (l));
      }
#else
      static
      symbol_type
      make_RIGHTPAR (const location_type& l)
      {
        return symbol_type (token::TOKEN_RIGHTPAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_CURLY (location_type l)
      {
        return symbol_type (token::TOKEN_LEFT_CURLY, std::move (l));
      }
#else
      static
      symbol_type
      make_LEFT_CURLY (const location_type& l)
      {
        return symbol_type (token::TOKEN_LEFT_CURLY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_CURLY (location_type l)
      {
        return symbol_type (token::TOKEN_RIGHT_CURLY, std::move (l));
      }
#else
      static
      symbol_type
      make_RIGHT_CURLY (const location_type& l)
      {
        return symbol_type (token::TOKEN_RIGHT_CURLY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON (location_type l)
      {
        return symbol_type (token::TOKEN_SEMICOLON, std::move (l));
      }
#else
      static
      symbol_type
      make_SEMICOLON (const location_type& l)
      {
        return symbol_type (token::TOKEN_SEMICOLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::TOKEN_COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::TOKEN_COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GEOMETRIC_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_GEOMETRIC_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_GEOMETRIC_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_GEOMETRIC_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARITHMETIC_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_ARITHMETIC_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ARITHMETIC_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_ARITHMETIC_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RELATIONAL_OP (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_RELATIONAL_OP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RELATIONAL_OP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_RELATIONAL_OP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPERATOR (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_OPERATOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OPERATOR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_OPERATOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ID_INC (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_ID_INC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ID_INC (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_ID_INC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ID_DEC (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_ID_DEC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ID_DEC (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_ID_DEC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KEYWORD (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_KEYWORD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_KEYWORD (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_KEYWORD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRIMITIVE_TYPE (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_PRIMITIVE_TYPE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PRIMITIVE_TYPE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_PRIMITIVE_TYPE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_IF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_IF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_ELSE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_ELSE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_THEN (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_THEN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_THEN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_THEN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENDIF (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_ENDIF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ENDIF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_ENDIF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOR (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_FOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FOR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_FOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOREND (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_FOREND, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FOREND (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_FOREND, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_WHILE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_WHILE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_WHILE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILEEND (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_WHILEEND, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_WHILEEND (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_WHILEEND, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DO (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_DO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DO (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_DO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOEND (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_DOEND, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DOEND (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_DOEND, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMENT (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_COMMENT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COMMENT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_COMMENT, v, l);
      }
#endif


    class context
    {
    public:
      context (const  Parser & yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const { return yyla_; }
      symbol_kind_type token () const { return yyla_.kind (); }
      const location_type& location () const { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const  Parser & yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
     Parser  (const  Parser &);
    /// Non copyable.
     Parser & operator= (const  Parser &);
#endif


    /// Stored state numbers (used for stacks).
    typedef signed char state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static symbol_kind_type yytranslate_ (int t);

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const signed char yytable_[];

    static const signed char yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const signed char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yylast_ = 148,     ///< Last index in yytable_.
      yynnts_ = 14,  ///< Number of nonterminal symbols.
      yyfinal_ = 2 ///< Termination state number.
    };


    // User arguments.
    Synthetic::Scanner &scanner;
    Synthetic::Interpreter &driver;

  };

  inline
   Parser ::symbol_kind_type
   Parser ::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32
    };
    const int user_token_number_max_ = 287;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= user_token_number_max_)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case 35: // command
      case 39: // assignment
      case 43: // statement
      case 44: // if_statement
      case 45: // for_statement
      case 46: // while_statement
        value.copy<  Synthetic::Command  > (YY_MOVE (that.value));
        break;

      case 36: // condition
        value.copy<  bool  > (YY_MOVE (that.value));
        break;

      case 38: // id
      case 41: // factor
        value.copy<  double  > (YY_MOVE (that.value));
        break;

      case 42: // statements
        value.copy<  std::vector<Synthetic::Command>  > (YY_MOVE (that.value));
        break;

      case 40: // term
        value.copy<  std::vector<double>  > (YY_MOVE (that.value));
        break;

      case 37: // expression
        value.copy<  std::vector<long long int>  > (YY_MOVE (that.value));
        break;

      case 5: // "floatingPoint"
        value.copy< float > (YY_MOVE (that.value));
        break;

      case 6: // "boolean"
      case 7: // "number"
        value.copy< long long int > (YY_MOVE (that.value));
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
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
   Parser ::symbol_kind_type
   Parser ::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
   Parser ::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
   Parser ::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case 35: // command
      case 39: // assignment
      case 43: // statement
      case 44: // if_statement
      case 45: // for_statement
      case 46: // while_statement
        value.move<  Synthetic::Command  > (YY_MOVE (s.value));
        break;

      case 36: // condition
        value.move<  bool  > (YY_MOVE (s.value));
        break;

      case 38: // id
      case 41: // factor
        value.move<  double  > (YY_MOVE (s.value));
        break;

      case 42: // statements
        value.move<  std::vector<Synthetic::Command>  > (YY_MOVE (s.value));
        break;

      case 40: // term
        value.move<  std::vector<double>  > (YY_MOVE (s.value));
        break;

      case 37: // expression
        value.move<  std::vector<long long int>  > (YY_MOVE (s.value));
        break;

      case 5: // "floatingPoint"
        value.move< float > (YY_MOVE (s.value));
        break;

      case 6: // "boolean"
      case 7: // "number"
        value.move< long long int > (YY_MOVE (s.value));
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
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
   Parser ::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
   Parser ::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
   Parser ::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  inline
   Parser ::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  inline
  void
   Parser ::by_kind::clear ()
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
   Parser ::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
   Parser ::symbol_kind_type
   Parser ::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  inline
   Parser ::symbol_kind_type
   Parser ::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

#line 37 "src/parser.y"
} //  Synthetic 
#line 2243 "src/parser.hpp"





#endif // !YY_YY_SRC_PARSER_HPP_INCLUDED
