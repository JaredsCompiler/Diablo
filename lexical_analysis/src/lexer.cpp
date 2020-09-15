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
#include <ctype.h>


lexer::lexer(lexerRules lexRules, sourceFile inputFile){
  this->rules = lexRules;
  this->ingestedFile = inputFile;
  this->begin = inputFile.get_begin();
  this->end = inputFile.get_end();
  this->tokens = std::vector<lexeme>();

}

std::tuple<int, int> lexer::span(std::string str, std::regex regexp, int* offset){
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
  int i = 0;
  int current_pos = int(match.position(i)) + *offset;
  int length = int(match.length(i));
  int j = 0;
  if(current_pos > EOF && length > 0){
    std::cout << "Match of: " << match[i] << std::endl;
    while(isspace(str[j])){ ++j; }
    current_pos+=j;
    *offset+=j;
    return std::make_tuple(current_pos, current_pos + length);
  }
  return std::make_tuple(EOF, EOF);
}

void lexer::remove_substring(std::string* line, std::string substring){
  size_t index = 0;
  while(true){
    index = line->find(substring, index);
    if(index == std::string::npos){ break; }
    line->replace(index, substring.size(), std::string(substring.size(), ' '));
    index+=substring.size();
  }
}

void lexer::processLine(int lineno, std::vector<std::string>::iterator* begin, std::string* line){
  std::smatch match;
  int counter = 0;
  int max_passes = 10;
  int offset = 0;


  while((std::all_of(line->begin(), line->end(), isspace) || !line->empty()) && counter <= max_passes){
    for(auto& identifier : this->rules.get_rules()){
      auto match = this->span(*line, identifier.second, &offset);
      std::string id = identifier.first;
      auto[start, end] = match;

      if(start >= 0 && end >= 0){
        if(identifier.first == "IDENTIFIER"){
          auto submatch = this->span(*line, this->rules.get_rules()["KEYWORD"], &offset);
          const auto[x, y] = submatch;
          if(x >= 0 && y >= 0){
            start = x;
            end = y;
            id = "KEYWORD";
            counter = 0;
          }
        }
        this->tokens.emplace_back(lexeme(lineno, start, end, (*begin)->substr(start, end), id));
        std::cout << "before: " << *line << std::endl;
        std::cout << start << " " << end << std::endl;
        auto substring = (*begin)->substr(start, end);
        //this->remove_substring(line, substring);
        offset+=substring.length();
        //line->erase(start, end);
        //auto zed = (*line).begin();
        //while(*zed == ' '){ zed++; string_offset++; }
        std::cout << "aftere: " << *line << std::endl;
        //counter--;
      } else {
        counter++;
      }
    }
  }
  if(std::all_of(line->begin(), line->end(), isspace) || line->empty()){
    std::cout << "line is exhausted" << std::endl;
  }
}

void lexer::processFile(){
  auto begin = this->ingestedFile.get_begin();
  auto end = this->ingestedFile.get_end();

  for(auto i = begin; i != end; ++i){
    std::string* line = &*i;
    auto lineno = (i - begin);
    this->processLine(lineno, &i, line);
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
