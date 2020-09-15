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

  private:
    std::tuple<size_t, size_t> slice;
    size_t line_no;
    //std::vector<std::string>::iterator it;
    std::string identifier;
    std::string substring;
};

