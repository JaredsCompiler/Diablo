#include "../includes/lexer.hpp"
#include "../includes/reader.hpp"
#include "../includes/lexer_rules.hpp"

#include <map>
#include <regex>
#include <string>
#include <tuple>


lexer::lexer(lexerRules lexRules, sourceFile inputFile,
             std::vector<std::string>::iterator begin,
             std::vector<std::string>::iterator end){
  this->rules = lexRules;
  this->ingestedFile = inputFile;
  this->begin = begin;
  this->end = end;

}

std::vector<std::tuple<size_t, size_t>> lexer::span(std::string str, std::regex regexp){
  /* Given a string, find all matches with their specified spans, from begin to end
   * Example:
   * input: ! Find largest!
   * output: one tuple with the following structure
   *    s, e = element
   *    with s = 0 and e = 15
   * these correspond to slices in the string given
   * line numbers would be the ith position iterating over the collection of strings representing the source document
   */
  std::vector<std::tuple<size_t, size_t>> collection;
  std::smatch match;
  std::regex_search(str, match, regexp);

  for(unsigned i = 0; i < match.size(); ++i){
    size_t start = match.position(i);
    size_t end = match.position(i) + match.length(i);
    collection.emplace_back(std::make_tuple(start, end));
  }
  return collection;
}

std::vector<std::string>::iterator lexer::get_begin(){
  return this->begin;
}

std::vector<std::string>::iterator lexer::get_end(){
  return this->end;
}
