#ifndef LABEL_H
#define LABEL_H

#include "Instructions.h"
#include "Parser.h"

class Label: public Instructions, Parser
{
public:
    Label();
    virtual ~Label();
    void execute(std::map<std::string, Var*>*);
    void initialize(std::stringstream & ss);
    Instructions * clone(std::stringstream & ss);
};

#endif
