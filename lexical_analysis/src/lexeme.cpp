#include "../includes/lexeme.hpp"
#include <iostream>
#include <regex>
#include <tuple>
#include <vector>
#include <algorithm>

lexeme::lexeme(size_t line, size_t begin, size_t end, std::string sub, std::string id){
  this->line_no = line;
  this->slice = std::make_tuple(begin, end);
  this->substring = sub;
  this->identifier = id;
}

const std::string lexeme::get_substring(){
  return this->substring;
}

std::string lexeme::get_tag(){
  return this->identifier;
}

std::ostream& operator<<(std::ostream& out, const lexeme& lex){
  const auto[start, end] = lex.slice;
  out << lex.identifier << "\t\t" << lex.substring << "\t";
  out << "(" << lex.line_no << ", " <<  start << ", " << end << ")";
  return out;
}

bool operator==(const lexeme& l1, const lexeme& l2){
  return (
    l1.line_no == l2.line_no &&
    l1.slice == l2.slice &&
    l1.substring == l2.substring &&
    l1.identifier == l2.identifier
  );
}

bool operator!=(const lexeme& l1, const lexeme& l2){
  return !(l1 == l2);
}

bool operator <(const lexeme& l1, const lexeme& l2){
  const auto[l1_s, l1_e] = l1.slice;
  const auto[l2_s, l2_e] = l2.slice;

  //return (
    //l1.line_no < l2.line_no &&
    //((l1_s < l2_s) && (l1_e < l2_e))
  //);
  //if this is the case, then we need to refactor lexeme to have a tuple of three elements
  return std::make_tuple(l1.line_no, l1_s, l1_e) < std::make_tuple(l2.line_no, l2_s, l2_e);
}
