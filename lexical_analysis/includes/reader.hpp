#pragma once

#include <string>
#include <vector>

class sourceFile {
  public:
    sourceFile(std::string);
    sourceFile();

    std::string get_path();
    size_t get_length();
    std::vector<std::string> get_content();
    std::vector<std::string>::iterator get_begin();
    std::vector<std::string>::iterator get_end();

    std::vector<std::string> read_contents();
    void print_contents();

  private:
    std::string path;
    std::vector<std::string> content;
    std::vector<std::string>::iterator begin;
    std::vector<std::string>::iterator end;
};
