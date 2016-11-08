#ifndef __JUMP_H
#define __JUMP_H

#include "Instructions.h"
#include "Parser.h"

class jmp : public Instructions, public Parser
{
public:
    jmp(const int & p_min = 1, const int & p_max = 1);
    virtual ~jmp();
    virtual void execute(std::map<std::string, Var*>*);
    void initialize(std::stringstream & ss);
    Instructions * clone(std::stringstream & ss);
};

class jmpz : public jmp
{
private:
    int specifier;
public:
    jmpz(const int & specifier);
    virtual ~jmpz();
    virtual void execute(std::map<std::string, Var*>*);
    virtual Instructions * clone(std::stringstream & ss);
};

class jmpgle: public jmp 
{
private:
    int specifier;
public:
    jmpgle(const int & specifier);
    ~jmpgle();
    virtual void execute(std::map<std::string, Var*>*);
    virtual Instructions * clone(std::stringstream & ss);
};

#endif

