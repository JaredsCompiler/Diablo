#include <iostream>
#include <string>
#include <regex>
#include <tuple>

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

int main (){
  auto element = span("! Find largest!", "\\!.*\\!");
  for(auto e : element){
    const auto[s, t] = e;
    std::cout << s << " " << t << std::endl;
  }
  return 0;
}
