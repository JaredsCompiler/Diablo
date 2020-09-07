#pragma once

#include "reader.hpp"
#include "lexer_rules.hpp"
#include "lexeme.hpp"

#include <map>
#include <regex>
#include <string>
#include <tuple>

class lexer {
  public:
    lexer(lexerRules, sourceFile);
   
    std::vector<std::tuple<size_t, size_t>> span(std::string, std::regex);
    void processFile();

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
