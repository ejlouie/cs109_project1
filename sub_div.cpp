#include "sub_div.h"
//#include <map>
#include "common.h"
#include "Instructions.h"
#include "Insns_Parser.h"

//Parser *p = new Parser();

sub_div::sub_div (int specifier) {
  this->specifier = specifier;
}


void sub_div::execute(map<string, Var*>* vars) {
  double num1;
  double num2;  
  int size = vec.size();
  if (size != 3) {
    cout << "Error: invalid parameters.\n" << endl;
    return;
  }
  /*Var* s = vars->operator[](vec[0]);
  if (s != NULL) {
    num1 = s->getValue(); 
  }else {
    stringstream convert1(vec[0]);
    convert1>>num1;
  }
  Var* b = vars->operator[](vec[1]);
  if (b != NULL) {
    num2 = s->getValue();
  }else {
    stringstream convert2(vec[1]);
    convert2>>num2;
    }*/
  double solution;
  if (specifier == 0) {
    solution = num1 - num2;
  }else if (specifier == 1) {
    solution = num1/num2;
  }else 
    cout << "Error: invalid instructions specifier.\n";
  std::cout << linenr << ":" << solution << "\n";
}

void sub_div::paramatize (stringstream & ss) {
  parse(ss);
}

Instructions * sub_div::clone (stringstream & ss) {
  sub_div * s = new sub_div(specifier);
  s->paramatize(ss);
  return s;
}


sub_div::~sub_div (){}
