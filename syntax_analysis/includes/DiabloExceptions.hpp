#include <iostream>
#include <exception>

class DiabloBaseException : public std::exception {
  /*
   * Custom exceptions in C++
   * http://peterforgacs.github.io/2017/06/25/Custom-C-Exceptions-For-Beginners/
  */
  const char* file;
  const char* func;
  const char* info;
  const char* message;
  int line;

  public:
   DiabloBaseException(const char* message_, const char* file_, int line_, const char* func_, const char* info_ ="");
   const char* get_file() const;
   const char* get_func() const;
   const char* get_info() const;
   const char* what() const throw();
   int get_line() const;

};

class FileErrorException : public DiabloBaseException {
  public:
    /*
     * Use the base class' constructor
     * https://stackoverflow.com/questions/8093882/using-c-base-class-constructors
    */
    using DiabloBaseException::DiabloBaseException;
};

class VariableNotDeclaredException : public DiabloBaseException {
  public:
    /*
     * Use the base class' constructor
     * https://stackoverflow.com/questions/8093882/using-c-base-class-constructors
    */
    using DiabloBaseException::DiabloBaseException;
};

class TypeMismatchException : public DiabloBaseException {
    public:
      using DiabloBaseException::DiabloBaseException;
};
