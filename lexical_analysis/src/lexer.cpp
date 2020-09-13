#include "../includes/lexer.hpp"
#include "../includes/reader.hpp"
#include "../includes/lexer_rules.hpp"
#include "../includes/lexeme.hpp"

#include <map>
#include <regex>
#include <string>
#include <tuple>
#include <cmath>
#include <stdio.h>


lexer::lexer(lexerRules lexRules, sourceFile inputFile){
  this->rules = lexRules;
  this->ingestedFile = inputFile;
  this->begin = inputFile.get_begin();
  this->end = inputFile.get_end();
  this->tokens = std::vector<lexeme>();

}

std::tuple<int, int> lexer::span(std::string str, std::regex regexp){
  std::cout << "calling span" << std::endl;
  /* Given a string, find all matches with their specified spans, from begin to end
   * Example:
   * input: ! Find largest!
   * output: one tuple with the following structure
   *    s, e = element
   *    with s = 0 and e = 15
   * these correspond to slices in the string given
   * line numbers would be the ith position iterating over the collection of strings representing the source document
   */

  std::smatch match;
  std::regex_search(str, match, regexp);

  int last_pos = -1;
  int start, end = -1;

  for(unsigned int i = 0; i < match.size(); ++i) {
    unsigned int curr = match.position(i);
    if(match.position(i) >= 0 && last_pos > match.position(i)){
        std::cout << curr << " " << (match.position(i) + match.length(i)) << std::endl;
        std::cout << "Before " << str << std::endl;
        str = std::regex_replace(str, std::regex(str.substr(match.position(i), (match.position(i) + match.length(i)))), "");
        printf("After: %s\n", str.c_str());
        last_pos = match.position(i);
        //start =  match.position(i);
        //end = match.position(i) + match.length(i);
    }
  }

  return std::make_tuple(start, end);
}

bool valid_string(std::string line){
  if(line.empty()){ return false; }
  std::string copy = line;
  std::regex_replace(copy, std::regex("\\s+"), "");
  return (copy.empty()) ? false : true;
}

void lexer::processLine(std::vector<std::string>::iterator it){
  std::string line =  *it;
  int counter = 0;
  int max_passes = 5;
  while(valid_string(line) && counter < max_passes){

    for(auto& identifier : this->rules.get_rules()){
      auto match = this->span(line, identifier.second);
      const auto[start, end] = match;
      int delta = (start - end);
      if(start >= 0 && delta >= 0){
        auto lineno = (it - begin);
        this->tokens.emplace_back(lexeme(lineno, start, end, begin, identifier.first));
        std::cout << "Before: " << line << std::endl;
        line.erase(start, end);
        std::cout << "After: " << line << std::endl;
      }
      else{ counter++; }
    }
  }
  //if(!line.empty()){
    //std::cerr << "Malformed!: " << line << std::endl;
  //}
}

void lexer::processFile(){
  auto begin = this->ingestedFile.get_begin();
  auto end = this->ingestedFile.get_end();

  for(auto i = begin; i != end; ++i){
    this->processLine(i);
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
