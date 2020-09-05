#include "../includes/lexer_rules.hpp"
#include <map>
#include <regex>
#include <string>

lexerRules::lexerRules(){
  this->rules = std::map<std::string, std::regex>();
}

lexerRules::lexerRules(std::map<std::string, std::regex> token){
  this->rules = token;
}

lexerRules::lexerRules(const lexerRules& other){
  this->rules = other.rules;
}

lexerRules & lexerRules::operator=(const lexerRules& ru){
  if(this == &ru){ return *this; }
  rules = ru.rules;
  return *this;
}

void lexerRules::add_rule(std::string identifier, std::regex matcher){
  if(this->rules.find(identifier) == this->rules.end()){
    this->rules[identifier] = matcher;
  }
}

std::map<std::string, std::regex> lexerRules::get_rules(){
  return this->rules;
}

void lexerRules::testRules(std::string line){
  return;
}

