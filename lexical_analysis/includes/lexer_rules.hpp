#pragma once
#include <map>
#include <regex>
#include <string>

// Brackets, braces or parenthesis regex -> ((\(|\))|(\{|\})|(\[|\]))
// Comments regex -> (\!.*\!)
// assignment regex -> (\w+\s+\=\s+\w+\$\;?)
// good god does importing the regex module cause insane compile times
// it appears that C++ uses the ECMA engine which can be accessed on regex 101 using ECMAScript (which might or might not work)


class lexerRules {
  public:
    lexerRules();
    lexerRules(std::map<std::string, std::regex>);
    lexerRules(const lexerRules& other);
    lexerRules &operator=(const lexerRules& other);

    void add_rule(std::string, std::regex);
    std::map<std::string, std::regex> get_rules();
    void testRules(std::string);

  private:
    std::map<std::string, std::regex> rules;
};


