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
#include <set>


lexer::lexer(lexerRules lexRules, sourceFile inputFile){
  this->rules = lexRules;
  this->ingestedFile = inputFile;
  this->begin = inputFile.get_begin();
  this->end = inputFile.get_end();
  this->tokens = std::vector<lexeme>();

}

void lexer::processLine(int lineno, std::vector<std::string>::iterator* begin, std::string line, std::vector<std::tuple<int, int, int>> collection){
  bool change_identifier = false;

  for(auto& identifier : this->rules.get_rules()){
      for (auto it = std::sregex_iterator(line.begin(), line.end(), identifier.second); it != std::sregex_iterator(); it++) { 
          std::smatch sm; 
          sm = *it; 
          unsigned long int start = sm.position(0);
          unsigned long int end = start + sm.length(1);
          std::string match_string = sm.str(1);

          if (std::all_of(match_string.begin(), match_string.end(), isspace) || match_string.empty()){
            std::cout << "Not adding" << std::endl;
          } else{
              if(identifier.first == "IDENTIFIER"){
                std::regex_search(match_string, sm, this->rules.get_rules()["KEYWORD"]);
                if(!sm.empty()){ change_identifier = true; }
              }
            }
            // more clean version is to have lexeme just take this object -> change constructor
            std::tuple<int, int, int> coordinates = std::make_tuple(lineno, start, end);
            if (!(std::find(collection.begin(), collection.end(), coordinates) != collection.end())){
              lexeme item = lexeme(lineno, start, end, match_string, (change_identifier) ? "KEYWORD" : identifier.first);
              this->tokens.push_back(item);
              collection.push_back(coordinates);
          } 
        change_identifier = false;
        if(identifier.first == "COMMENT"){ return; }
    } 
  }
}

void lexer::processFile(){
  auto begin = this->ingestedFile.get_begin();
  auto end = this->ingestedFile.get_end();

  std::vector<std::tuple<int, int, int>> collect_all;

  for(auto i = begin; i != end; ++i){
    std::string line = *i;
    auto lineno = (i - begin);
    this->processLine(lineno, &i, line, collect_all);
  }
  this->tokens = this->sortLexemes();
}

void lexer::removeDuplicates(){
  std::set<lexeme> s(this->tokens.begin(), this->tokens.end());
  this->tokens.assign(s.begin(), s.end());
}

std::vector<lexeme> lexer::sortLexemes(){
  std::vector<lexeme> sortedCopy = this->tokens;
  std::sort(sortedCopy.begin(), sortedCopy.end());
  return sortedCopy;
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

