#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "common.h"
#include "Parser.h"

class Var;

class Instructions 
{
public:
    int linenr;
    virtual ~Instructions(){}
    Instructions(){}
    virtual void execute (std::map<std::string, Var*>*) = 0;
    virtual void initialize (std::stringstream & ss) = 0;
    virtual Instructions * clone (std::stringstream & ss)=0;
};

class SubDiv: public Instructions, StandardParser 
{
protected:
    int specifier;
public:
    SubDiv(int specifier);
    virtual ~SubDiv();
    void execute(std::map<std::string, Var*>*);
    void initialize(std::stringstream & ss);
    Instructions * clone(std::stringstream & ss);
};

class AddMul : public Instructions, StandardParser 
{
protected:
    int specifier;
public:
    AddMul(int specifier);
    virtual ~AddMul();
    void execute(std::map<std::string, Var*>*);
    void initialize(std::stringstream & ss);
    Instructions * clone(std::stringstream & ss);
};

class Out: public Instructions, Parser {
public:
    Out();
    virtual ~Out();
    void execute(std::map<std::string, Var*>*);
    void initialize(std::stringstream & ss);
    Instructions * clone(std::stringstream & ss);
};

#endif
