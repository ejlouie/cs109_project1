#ifndef __ASSIGN_H
#define __ASSIGN_H

#include "Instructions.h"
#include "Parser.h"

class Assign : public Instructions, StandardParser
{
public:
    Assign();
    ~Assign();
    virtual void execute (std::map<std::string, Var*>*);
    virtual void initialize (std::stringstream & ss);
    virtual Instructions * clone (std::stringstream & ss);

};
#endif 
