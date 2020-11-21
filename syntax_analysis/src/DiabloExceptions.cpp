#include <iostream>
#include <exception>

#include "../includes/DiabloExceptions.hpp"

DiabloBaseException::DiabloBaseException(const char* message_, const char* file_, int line_, const char* func_, const char* info_){
  this->file = file_;
  this->func = func_;
  this->info = info_;
  this->line = line_;
  this->message = message_;
}


 const char* DiabloBaseException::get_file() const { return this->file; }
 const char* DiabloBaseException::get_func() const { return this->func; }
 const char* DiabloBaseException::get_info() const { return this->info; }
 const char* DiabloBaseException::what() const throw() { return this->message; }
 int DiabloBaseException::get_line() const { return this->line; }
