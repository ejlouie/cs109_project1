#include "jmpgle.h"

jmpgle::jmpgle(int specifier) {
  this->specifier = specifier;
  this->isjmp = true;
  this->islab = false;
  this->can_jmp = false;
  //this->label = "";
}

void jmpgle::execute(map<string, Var*>* tmp) {
  this->label = vec[0];
  double num1;
  double num2;
  stringstream convert (vec[1]);
  stringstream convert2 (vec[2]);
  convert>>num1;
  convert2>>num2;
  if (specifier == 0) {
    if (num1 > num2)
      this->can_jmp = true;
  }else if (specifier == 1) {
    if (num1 < num2)
      this->can_jmp = true;
  }else if (specifier == 2) {
    if(num1 >= num2)
      this->can_jmp = true;
  }else if (specifier == 3) {
    if(num1 <= num2)
      this->can_jmp = true;
  }else 
    cout << "ERROR\n";
}

Instructions * jmpgle::clone (stringstream & ss) {
  jmpgle * j = new jmpgle(this->specifier);
  j->paramatize(ss);
  return j;
}

jmpgle::~jmpgle() {}
 
