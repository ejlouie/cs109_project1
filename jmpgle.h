#ifndef JMPGLE_H
#define JMPGLE_H

#include "common.h"
#include "Instructions.h"
#include "jmp.h"
#include "Insns_Parser.h"

class jmpgle: public jmp {
 private:
  int specifier;
 public:
  jmpgle(int specifier);
  virtual void execute(map<string, Var*>*);
  virtual Instructions * clone(stringstream & ss);
  ~jmpgle();
};

#endif

