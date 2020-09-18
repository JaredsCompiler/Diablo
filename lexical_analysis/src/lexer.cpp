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

void lexer::processLine(int lineno, std::vector<std::string>::iterator* begin, std::string line){
  for(auto& identifier : this->rules.get_rules()){
      for (auto it = std::sregex_iterator(line.begin(), line.end(), identifier.second); 
               it != std::sregex_iterator(); it++) { 
              std::smatch sm; 
              sm = *it; 
              unsigned long int start = sm.position(0);
              unsigned long int end = start + sm.length(1);
              std::string match_string = sm.str(1);

              if (std::all_of(match_string.begin(), match_string.end(), isspace) || match_string.empty()){
                std::cout << "Not adding" << std::endl;
              } else{
                this->tokens.emplace_back(lexeme(lineno, start, end, match_string, identifier.first));
                if(identifier.first == "COMMENT"){ return; }
              } 
          } 

    //if (std::regex_search(*line, sm, identifier.second)) {
        //for (unsigned long int i=1; i<sm.size(); i++) {
            //unsigned long int start = sm.position(i);
            //unsigned long int end = start + sm.length(i);
            //std::string match_string = sm.str(i);
            //if (std::all_of(match_string.begin(), match_string.end(), isspace) || match_string.empty()){
              //std::cout << "Not adding" << std::endl;
            //} else{
              //this->tokens.emplace_back(lexeme(lineno, start, end, sm.str(i), identifier.first));
            //}
        //}
    //}
  }
}

void lexer::processFile(){
  auto begin = this->ingestedFile.get_begin();
  auto end = this->ingestedFile.get_end();

  for(auto i = begin; i != end; ++i){
    std::string line = *i;
    //std::string* line = &*i;
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
