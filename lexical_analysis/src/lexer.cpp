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

  for(auto& identifier : this->rules.get_rules()){
      bool can_break_immediate = false;
      for (auto it = std::sregex_iterator(line.begin(), line.end(), identifier.second); it != std::sregex_iterator(); it++) { 
          bool is_keyword = false;
          bool comment_leftovers = false;

          std::smatch sm = *it; 

          unsigned long int start = sm.position(0);
          unsigned long int end = start + sm.length(1);

          std::string match_string = sm.str(1);

          bool is_empty = (std::all_of(match_string.begin(), match_string.end(), isspace) || match_string.empty());
          if(is_empty){ continue; }

          std::tuple<int, int, int> coordinates = std::make_tuple(lineno, start, end);

          bool is_found = (std::find(collection.begin(), collection.end(), coordinates) != collection.end());
          if(is_found){ break; }

          if(identifier.first == "IDENTIFIER"){
            std::regex_search(match_string, sm, this->rules.get_rules()["KEYWORD"]);
            std::string substring = sm.str(1);
            if(substring == match_string){ is_keyword = true; } 
            else { can_break_immediate = true; }
          }

          lexeme item = lexeme(coordinates, match_string, (is_keyword) ? "KEYWORD" : identifier.first);
          this->tokens.push_back(item);
          collection.push_back(coordinates);

          comment_leftovers = ((start >= 0) && (end <= line.size()) && (identifier.first == "COMMENT")) ? true : false;

          if(comment_leftovers){ line.erase(start, end); }
          //if(can_break_immediate){break;}
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

