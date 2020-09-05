#include "../includes/reader.hpp"
#include <iostream>
#include <fstream>
#include <vector>

sourceFile::sourceFile(std::string path){
  this->path = path;
  this->content = this->read_contents();
}

sourceFile::sourceFile(){
  this->path = "";
  this->content = std::vector<std::string>();
}

std::string sourceFile::get_path(){
  return this->path;
}

std::vector<std::string> sourceFile::get_content(){
  return this->content;
}

size_t sourceFile::get_length(){
  return this->content.size();
}

std::vector<std::string> sourceFile::read_contents(){
  std::ifstream file;
  file.open(this->path);
  std::vector<std::string> contents;
  if(!file.is_open()){
    throw std::invalid_argument("cannot open file!");
  }
  for(std::string line; getline(file, line);){
    contents.push_back(line);
  }
  file.close();
  return contents;
}

void sourceFile::print_contents(){
  for(auto line : this->content){
    std::cout << line << std::endl;
  }
}
