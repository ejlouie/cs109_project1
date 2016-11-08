#ifndef __SLEEP_H
#define __SLEEP_H

#include "Instructions.h"
#include "Parser.h"

class Sleep : public Instructions, Parser
{
public:
    Sleep();
    virtual ~Sleep();
    void execute(std::map<std::string, Var*>*);
    void initialize(std::stringstream & ss);
    Instructions * clone(std::stringstream & ss);

};

#endif
