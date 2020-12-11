#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <map>

class Symbol {
  public:
    Symbol();
    Symbol(std::string, std::string, long long int);

    bool typeDeclared();
    bool typeMismatch();
    bool isDefined();

    long long int value_();
    std::string type_();
    std::string name_();
    unsigned long long int location_();

    void setLocation(unsigned long long int);

    private:
      std::string type;
      std::string name;
      long long int value;
      bool typeIsDelcared;
      unsigned long long int location;

};
