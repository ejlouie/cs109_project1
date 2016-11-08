#ifndef __MATH_H
#define __MATH_H

#include "Parser.h"
#include "Instructions.h"

class Var;


class Math: public Instructions, StandardParser 
{
protected:
    int max;
public:
    Math(const int & p_min);
    virtual ~Math();
    void execute(std::map<std::string, Var*>*);
    void initialize(std::stringstream & ss);
    virtual double Operation(std::vector<double> v) = 0;
    Instructions * clone(std::stringstream & ss) = 0;
};

class Add : public Math
{
public:
    Add();
    ~Add();
    Instructions * clone(std::stringstream & ss);
    double Operation(std::vector<double>v);
};

class Multiply : public Math
{
public:
    Multiply();
    ~Multiply();
    Instructions * clone(std::stringstream & ss);
    double Operation(std::vector<double>v);
};

class Subtract : public Math
{
public:
    Subtract();
    ~Subtract();
    Instructions * clone(std::stringstream & ss);
    double Operation(std::vector<double>v);
};

class Divide : public Math
{
public:
    Divide();
    ~Divide();
    Instructions * clone(std::stringstream & ss);
    double Operation(std::vector<double>v);
};

#endif
