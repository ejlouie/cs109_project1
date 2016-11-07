#ifndef OUT_H
#define OUT_H

#include "Instructions.h"
#include "common.h"
#include "Insns_Parser.h"

class out: public Instructions, public Insns_Parser {
 protected:
 public:
  //out();
  void execute(map<string, Var*>*);
  void paramatize(stringstream & ss);
  Instructions * clone(stringstream & ss);
  //~out();
};

#endif
