#ifndef JMP_H
#define JMP_H

#include "common.h"
#include "Instructions.h"
#include "Insns_Parser.h"

class jmp: public Instructions, public Insns_Parser {
 public:
  jmp();
  virtual void execute(map<string, Var*>*);
  void paramatize(stringstream & ss);
  Instructions * clone(stringstream & ss);
  ~jmp();
};

#endif

