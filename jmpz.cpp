#include "jmpz.h"

jmpz::jmpz(int specifier) {
  this->specifier = specifier;
  this->isjmp = true;
  this->islab = false;
  this->can_jmp = false;
  //this->label = "";
}

void jmpz::execute(map<string, Var*>* tmp) {
  this->label = vec[0];
  double num1;
  stringstream convert (vec[1]);
  convert>>num1;
  if (specifier == 0) {
    if (num1 == 0)
      this->can_jmp = true;
  }else if (specifier == 1) {
    if (num1 != 0)
      this->can_jmp = true;
  }else
    cout << "ERROR\n";
}

Instructions * jmpz::clone (stringstream & ss) {
  jmpz * j = new jmpz(this->specifier);
  j->paramatize(ss);
  return j;
}

jmpz::~jmpz() {}
 
