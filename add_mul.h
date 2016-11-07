#ifndef ADD_MUL_H
#define ADD_MUL_H

#include "common.h"
#include "Instructions.h"
#include "Insns_Parser.h"

class add_mul: public Instructions, public Insns_Parser {
 protected:
  int specifier;
 public:
  add_mul(int specifier);
  void execute(map<string, Var*>*);
  void paramatize(stringstream & ss);
  Instructions * clone(stringstream & ss);
  ~add_mul();
};

#endif
