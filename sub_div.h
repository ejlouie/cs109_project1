#ifndef SUB_DIV_H
#define SUB_DIV_H

#include "Insns_Parser.h"
#include "Instructions.h"
#include "common.h"

class sub_div: public Instructions, public Insns_Parser {
 protected:
  int specifier;
 public:
  sub_div(int specifier);
  void execute(map<string, Var*>*);
  void paramatize(stringstream & ss);
  Instructions * clone(stringstream & ss);
  ~sub_div();
};

#endif
