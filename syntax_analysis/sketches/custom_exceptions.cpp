#include <iostream>
#include <exception>

class DiabloBaseException : public std::exception {
  const char* message;
  const char* file;
  int line;
  const char* func;
  const char* info;

  public:
    DiabloBaseException(const char* message_, const char* file_, int line_, const char* func_, const char* info_ ="") : message(message_),
      file(file_),
      line(line_),
      func(func_),
      info(info_) {}
   const char* get_file() const { return file; }
   int get_line() const { return line; }
   const char* get_func() const { return func; }
   const char* get_info() const { return info; }

   const char* what() const throw() { return message; }
};

int main(){
  try{
    throw DiabloBaseException("Example error", __FILE__, __LINE__, __FUNCTION__, "Nothing");
  } catch(DiabloBaseException& e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
