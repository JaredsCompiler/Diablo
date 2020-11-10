#pragma once
#include <iostream>
#include <regex>
#include <tuple>
#include <vector>

class lexeme {
  public:
    lexeme(size_t, size_t, size_t, std::string, std::string);
    friend std::ostream& operator<<(std::ostream& out, const lexeme& lex);
    const std::string get_substring();
    std::string get_tag();
    std::tuple<size_t, size_t> get_slice();
    size_t get_lineno();

    friend bool operator== (const lexeme &l1, const lexeme &l2);
     
    friend bool operator!= (const lexeme &l1, const lexeme &l2);
    friend bool operator <(const lexeme& l1, const lexeme& l2);

  private:
    std::tuple<size_t, size_t> slice;
    size_t line_no;
    std::string identifier;
    std::string substring;
};

