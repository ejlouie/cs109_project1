#ifndef SLEEP_H
#define SLEEP_H

#include "common.h"
#include "Instructions.h"
#include "Insns_Parser.h"

class sleep: public Instructions, public Insns_Parser {
 public:
  sleep();
  void execute(map<string, Var*>*);
  void paramatize(stringstream & ss);
  Instructions * clone(stringstream & ss);
  ~sleep();
};

#endif

