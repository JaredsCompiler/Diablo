#include "../includes/lexeme.hpp"
#include <iostream>
#include <regex>
#include <tuple>
#include <vector>
#include <algorithm>

lexeme::lexeme(size_t line, size_t begin, size_t end, std::vector<std::string>::iterator i, std::string id){
  this->line_no = line;
  this->slice = std::make_tuple(begin, end);
  this->it = i;
  this->identifier = id;
}

const std::string lexeme::get_substring(){
  std::vector<std::string>::iterator i = this->it + this->line_no;
  const auto[s, e] = this->slice;
  return (*i).substr(s, e);
}

std::string lexeme::get_tag(){
  return this->identifier;
}

std::ostream& operator<<(std::ostream& out, const lexeme& lex){
  printf("lineno: %zu\n", lex.line_no);
  printf("span: (%zu, %zu)\n", std::get<0>(lex.slice), std::get<1>(lex.slice));
  std::cout << "identifier: " << lex.identifier << std::endl;
  // this is duplicate, const stupid fuck error
  std::vector<std::string>::iterator i = lex.it + lex.line_no;
  const auto[start, end] = lex.slice;
  std::cout << (*i).substr(start, end) << std::endl;
  return out;
}
