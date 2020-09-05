#include <iostream>
#include <string>
#include <regex>
#include <tuple>

// this will NOT compile, please do not try to


////////////////////////////////////////////////////////////////////////////////

int main (){
  std::vector<std::string> content = {
    "! Find the largest! This is a sentence about cakes",
    "if(condition)"
  };


  std::vector<lexeme> collection;
  std::vector<std::string>::iterator it = content.begin();

  for(size_t i = 0; i < content.size(); ++i){
    for(auto& identifier : tokeMap){
      auto match = span(content[i], identifier.second);
      for(auto tup : match){
        const auto[s, e] = tup;
        collection.emplace_back(lexeme(i, s, e, it));
      }
    }
  }

  for(auto element : collection){
    std::cout << element.get_substring() << std::endl;
    //auto l = element.get_line_number();
    //auto span = element.get_slice();
    //const auto[s, e] = span;
    //std::cout << l << " " << s << " " << e << std::endl;
  }
  return 0;
}
