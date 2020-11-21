#include "../../lexical_analysis/includes/reader.hpp"
#include <tuple>
#include <string>

#pragma once

class balancer {
  public:
    bool is_matching(char, char);
    bool is_valid(char);
    bool is_balanced(std::string);

    //bool is_file_balanced(sourceFile); // needs to be changed to sourceFile to prevent extraneous code
    std::tuple<bool, std::string, int> is_file_balanced(sourceFile);
};
