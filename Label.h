#ifndef LABEL_H
#define LABEL_H

#include "common.h"
#include "Instructions.h"
#include "Insns_Parser.h"

class Label: public Instructions, public Insns_Parser {
 public:
  Label();
  void execute(map<string, Var*>*);
  void paramatize(stringstream & ss);
  Instructions * clone(stringstream & ss);
  ~Label();
};

#endif
