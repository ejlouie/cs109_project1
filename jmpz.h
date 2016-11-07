#ifndef JMPZ_H
#define JMPZ_H

#include "common.h"
#include "Instructions.h"
#include "jmp.h"
#include "Insns_Parser.h"

class jmpz: public jmp {
 private:
  int specifier;
 public:
  jmpz(int specifier);
  virtual void execute(map<string, Var*>*);
  virtual Instructions * clone(stringstream & ss);
  ~jmpz();
};

#endif

