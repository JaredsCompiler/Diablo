#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

namespace Synthetic {
  template <typename T>
  class templateCommand {
    public:
      templateCommand(const std::string &name, const std::vector<T> c) :
        c_name(name),
        container(c)
      {

      }
      templateCommand(const std::string &name) :
        c_name(name),
        container()
      {

      }
      templateCommand() :
        c_name(),
        container()
      {

      }
      ~templateCommand()
      {

      }


      std::string str() const {
        std::stringstream ts;
        ts << "name = [" << c_name << "], ";
        ts << "arguments = [";
        
        for(size_t i = 0; i < container.size(); i++) {
            ts << container[i];
            if(i < container.size() - 1) {
                ts << ", ";
            }
        }
        
        ts << "]";
        return ts.str();
      }
      std::string name() const{ return c_name; }
      std::vector<T> container_() const { return container; }

    private:
      std::string c_name;
      std::vector<T> container;
  };
};
