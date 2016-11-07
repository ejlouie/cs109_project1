#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "common.h"
#include "Var.h"

class Instructions {
protected:
  //int linenr;
public:
  int linenr;
  //Instructions(); 
  virtual void execute(map<string, Var*>*) = 0;
  virtual void paramatize (stringstream & ss) = 0;
  virtual Instructions * clone (stringstream & ss)=0;
  //virtual ~Instructions();
};

#endif
