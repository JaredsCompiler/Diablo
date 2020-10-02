#include "../includes/lexeme.hpp"
#include <iostream>
#include <regex>
#include <tuple>
#include <vector>
#include <algorithm>
#include <iomanip>

lexeme::lexeme(std::tuple<size_t, size_t, size_t> coordinates, std::string sub, std::string id){
  const auto[z, x, y] = coordinates;
  this->slice = std::make_tuple(z, x, y);
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
  const auto[line, start, end] = lex.slice;
  out << std::left << std::setw(0) << lex.identifier << std::right << "\t\t" << lex.substring << "\t";
  out << "(" << line << ", " <<  start << ", " << end << ")";
  return out;
}

bool operator==(const lexeme& l1, const lexeme& l2){
  return (
    l1.slice == l2.slice &&
    l1.substring == l2.substring &&
    l1.identifier == l2.identifier
  );
}

bool operator!=(const lexeme& l1, const lexeme& l2){
  return !(l1 == l2);
}

bool operator <(const lexeme& l1, const lexeme& l2){
  return l1.slice < l2.slice;
}
