#include "add_mul.h"
#include "common.h"
#include "Instructions.h"
#include "Insns_Parser.h"

//Parser *p_add = new Parser();

add_mul::add_mul(int specifier) {
  this->specifier = specifier;
  this->isjmp = false;
  this->islab = false;
}

void add_mul::execute(map<string, Var*>*) {
  double solution = 1;
  int size = vec.size();
  if (size < 3 || size > 13) {
    cout << "Error: invalid parameters.\n";
    return;
  }
  //cout << size << "\n";
  for (int i = 0; i < size - 1; i++) {
    double tmp;
    stringstream convert (vec[i]);
    convert>>tmp;
    //cout << tmp << "\n";
    if (specifier == 0) {
      solution += tmp;
    }else if (specifier == 1) {
      solution *= tmp;
    }else {
      cout << "Error: invalid instruction specifier.\n";
    }
  }
  if (specifier == 0) {
    solution -= 1;
  }
  cout << linenr << ":" << solution << "\n";
}

void add_mul::paramatize (stringstream & ss) {
  //Parse *p_add = new Parser();
  parse(ss);
}

Instructions * add_mul::clone (stringstream & ss) {
  add_mul * a = new add_mul(specifier);
  a->paramatize(ss);
  return a;
}

add_mul::~add_mul (){}
