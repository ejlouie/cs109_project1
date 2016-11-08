#ifndef __INSTRUCTIONS_H
#define __INSTRUCTIONS_H

#include "Parser.h"

class Var;

class Instructions 
{
protected:
    virtual double get_numeric(std::string str,std::map<std::string,Var*>*) final;
public:
    int linenr;
    bool isjmp;
    bool islab;
    bool can_jmp;
    std::string label;

    virtual ~Instructions(){}
    Instructions(){}
    virtual void execute (std::map<std::string,Var*>*) = 0;
    virtual void initialize (std::stringstream & ss) = 0;
    virtual Instructions * clone (std::stringstream & ss) = 0;
};

class Out: public Instructions, Parser {
public:
    Out();
    virtual ~Out();
    void execute(std::map<std::string,Var*>*);
    void initialize(std::stringstream & ss);
    Instructions * clone(std::stringstream & ss);
};

#endif
