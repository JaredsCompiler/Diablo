#pragma once
#include <map>
#include <regex>
#include <string>

class lexerRules {
  public:
    lexerRules(std::map<std::string, std::regex>);

    void add_rule(std::string, std::regex);
    std::map<std::string, std::regex> get_rules();
    void testRules(std::string);

  private:
    std::map<std::string, std::regex> rules;
};


