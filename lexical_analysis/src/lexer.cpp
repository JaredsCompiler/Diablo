#include "../includes/lexer.hpp"
#include "../includes/reader.hpp"
#include "../includes/lexer_rules.hpp"
#include "../includes/lexeme.hpp"

#include <map>
#include <regex>
#include <string>
#include <tuple>


lexer::lexer(lexerRules lexRules, sourceFile inputFile){
  this->rules = lexRules;
  this->ingestedFile = inputFile;
  this->begin = inputFile.get_begin();
  this->end = inputFile.get_end();
  this->tokens = std::vector<lexeme>();

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
  std::cout << collection.size() << std::endl;
  return collection;
}

void lexer::processFile(){
  auto begin = this->ingestedFile.get_begin();
  auto end = this->ingestedFile.get_end();
  for(auto i = begin; i != end; ++i){
    for(auto& identifier : this->rules.get_rules()){
      std::cout << identifier.first << std::endl;
      for(auto tup : this->span(*i, identifier.second)){
        const auto[start, end] = tup;
        auto position = (i - begin);
        this->tokens.emplace_back(lexeme(position, start, end, begin, identifier.first));
      }
    }
  }
}

std::vector<std::string>::iterator lexer::get_begin(){
  return this->begin;
}

std::vector<std::string>::iterator lexer::get_end(){
  return this->end;
}

std::vector<lexeme> lexer::get_tokens(){
  return this->tokens;
}
