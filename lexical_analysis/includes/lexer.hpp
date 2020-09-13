#pragma once

#include "reader.hpp"
#include "lexer_rules.hpp"
#include "lexeme.hpp"

#include <map>
#include <regex>
#include <string>
#include <tuple>
#include <vector>

class lexer {
  public:
    lexer(lexerRules, sourceFile);
   
    std::tuple<int, int> span(std::string, std::regex);
    void processFile();
    void processLine(std::vector<std::string>::iterator);

    std::vector<std::string>::iterator get_begin();
    std::vector<std::string>::iterator get_end();
    std::vector<lexeme> get_tokens();

  private:
    lexerRules rules;
    sourceFile ingestedFile;
    std::vector<std::string>::iterator begin;
    std::vector<std::string>::iterator end;
    std::vector<lexeme> tokens;
};
