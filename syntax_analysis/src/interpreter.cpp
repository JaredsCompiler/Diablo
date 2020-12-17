/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014 Krzysztof Narkiewicz <krzysztof.narkiewicz@ezaquarii.com>
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 * 
 */

#include "interpreter.h"
#include "../includes/command.h"

#include <sstream>
#include <iterator>
#include <string>

using namespace Synthetic;

Interpreter::Interpreter() :
    m_scanner(*this),
    m_parser(m_scanner, *this),
    m_location(0),
    m_commands(),
    symbol_table(),
    assembler_()
{

}

int Interpreter::parse() {
    m_location = 0;
    return m_parser.parse();
}

void Interpreter::clear() {
    m_location = 0;
    m_commands.clear();
}

std::string Interpreter::str() const {
    std::stringstream s;
    s  << symbol_table << std::endl;
    return s.str();
}

void Interpreter::switchInputStream(std::istream *is) {
    m_scanner.switch_streams(is, NULL);
    m_commands.clear();    
}

void Interpreter::addCommand(const Command &cmd)
{
    m_commands.push_back(cmd);
}

void Interpreter::increaseLocation(unsigned int loc) {
    m_location += loc;
}

unsigned int Interpreter::location() const {
    return m_location;
}

void Interpreter::addSymbol(Symbol S, bool update_mem) {
    this->symbol_table.insert(S, update_mem);
}

Symbol Interpreter::getSymbol(std::string variable){
  return this->symbol_table.obtain(variable);
}

void Interpreter::addInstruction(Instruction I){
  this->assembler_.push(I);
}

Instruction Interpreter::generateInstruction(std::string i){
  std::string _inst_code = this->assembler_.getInstruction(i);
  size_t location = this->assembler_.location_() + 1;
  this->assembler_.updateLocation(location);
  return Instruction(_inst_code, location);
}

Instruction Interpreter::generateBlankInstruction(std::string i){
  size_t location = this->assembler_.location_() + 1;
  this->assembler_.updateLocation(location);
  return Instruction(i, location);
}

Assembler Interpreter::getAssembler(){
  return this->assembler_;
}

void Interpreter::setDispenseFlag(bool f){
  this->assembler_.setDispense(f);
}

bool Interpreter::shouldDispenseFlag(){
  return this->assembler_.shouldDispenseInstruction();
}
