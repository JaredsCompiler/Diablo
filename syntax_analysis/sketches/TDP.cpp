#include <iostream>
#include <string>
#include <vector>

// Rename: TDP.cpp

/*
 * E -> TE^1 (T, E prime)
 * E^1 (E prime) -> +TE^1 | -TE^1 | epsilon
 * T -> id
*/

//bool isEOF = false;
//

namespace Synthetic {
  class Token {
     public:
       Token(std::string, std::string);
       Token();
       std::string content_();
       std::string classification_();
       bool EOF_();
       void EOFSetter();

     private:
      std::string content;
      std::string classification;
      bool isEOF;
  };  

  Token::Token(std::string content, std::string classification){
    this->content = content;
    this->classification = classification;
    this->isEOF = false;
  }

  Token::Token(){
    this->content = std::string();
    this->classification = std::string();
    this->isEOF = false;
  }
  
  std::string Token::content_(){ return this->content; }
  std::string Token::classification_(){ return this->classification; }
  bool Token::EOF_(){ return isEOF; }

  void Token::EOFSetter(){ this->isEOF = (!this->isEOF) ? true : false; }

};


std::vector<Synthetic::Token> container = {
  Synthetic::Token("a", "ID"),
  Synthetic::Token("+", "ARITHMETIC_OP"),
  Synthetic::Token("b", "ID")
};

std::vector<Synthetic::Token>::iterator position = container.begin();



Synthetic::Token globalToken = *position;

namespace ArithmeticOperations {

  void lexer(){
    std::cout << __func__ << std::endl;
    if(position == container.end()){
      std::cerr << "[-] Container iterator is expired" << std::endl;
      globalToken.EOFSetter();
    } else {
      std::cout << "before fuck up" << std::endl;
      std::cout  << "in betweeen "<< std::endl;
      globalToken = *position;
      position++;
      std::cout << "after fuck up" << std::endl;
    }
  }

  void T(){
    if(globalToken.EOF_()){ return; } // base case
    if(globalToken.classification_() != "ID"){
      globalToken.EOFSetter();
      std::cerr << "[-] Error, expected id but got " << globalToken.content_() <<  " with classification of " << globalToken.classification_() << std::endl;
    } else{
      std::cout << "[+] Got id of " << globalToken.content_() << std::endl;
      lexer();
    }

  }

  void E_Prime(){
    if(globalToken.EOF_()){ return; }

    if(globalToken.classification_() == "ARITHMETIC_OP"){
      lexer();
      T();
      E_Prime();
    } else {
      std::cerr << "[-] Unexpected " << globalToken.content_() << " with value of " << globalToken.classification_() << std::endl;
    }
  }

  void E(){
    T();
    E_Prime();

    if(!globalToken.EOF_()){
      std::cerr << "[-] EOF not encountered" << std::endl;
    } else {
      std::cout << "[+] Container has been accepted!" << std::endl;
    }
  }
};

int main(){

  ArithmeticOperations::E();
  //ArithmeticOperations::lexer();
  //ArithmeticOperations::T();
 
  return 0;
}

