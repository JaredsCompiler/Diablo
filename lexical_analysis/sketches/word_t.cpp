#include <iostream>
#include <string>
#include <regex>
#include <tuple>

class lexeme {
  public:
    lexeme(size_t, size_t, size_t);
    std::tuple<size_t, size_t> get_slice();
    size_t get_line_number();
  private:
    std::tuple<size_t, size_t> slice;
    size_t line_no;
};

lexeme::lexeme(size_t line, size_t begin, size_t end){
  this->line_no = line;
  this->slice = std::make_tuple(begin, end);
}

std::tuple<size_t, size_t> lexeme::get_slice(){
  return this->slice;
}

size_t lexeme::get_line_number(){
  return this->line_no;
}

std::vector<std::tuple<size_t, size_t>> span(std::string str, std::string regexp){
  /* Given a string, find all matches with their specified spans, from begin to end
   * Example:
   * input: ! Find largest!
   * output: one tuple with the following structure
   *    s, e = element
   *    with s = 0 and e = 15
   * these correspond to slices in the string given
   * line numbers would be the ith position iterating over the collection of strings representing the source document
   */
  std::vector<std::tuple<size_t, size_t>> collection;
  std::smatch match;
  std::regex expression(regexp);
  std::regex_search(str, match, expression);

  for(unsigned i = 0; i < match.size(); ++i){
    size_t start = match.position(i);
    size_t end = match.position(i) + match.length(i);
    collection.emplace_back(std::make_tuple(start, end));
  }
  return collection;
}

std::string slice(std::string line, size_t start, size_t end){
  return line.substr(start, end);
}

int main (){
  std::vector<std::string> content = {
    "! Find the largest dick!",
    "if(condition)"
  };

  std::map<std::string, std::string> tokeMap = {
    {"COMMENT", "\\!.*\\!"}
  };

  std::vector<lexeme> collection;

  for(size_t i = 0; i < content.size(); ++i){
    for(auto& identifier : tokeMap){
      auto match = span(content[i], identifier.second);
      for(auto tup : match){
        const auto[s, e] = tup;
        collection.emplace_back(lexeme(i, s, e));
      }
    }
  }

  for(auto element : collection){
    auto l = element.get_line_number();
    auto span = element.get_slice();
    const auto[s, e] = span;
    std::cout << l << " " << s << " " << e << std::endl;
  }
  return 0;
}
