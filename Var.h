#ifndef __VAR_H
#define __VAR_H

#include "common.h"
#include "Parser.h"

class Var
{
protected:
    virtual void initialize(std::stringstream & ss) = 0;
    std::string value;

public:
    Var();
    ~Var();
    virtual std::string getValue() final;
    virtual std::string getType() = 0;
    virtual void setValue(const std::string & str) final;
    virtual Var * clone(std::stringstream & ss) = 0;

};

class NumericVar : public Var, StandardParser
{
private:
    void initialize(std::stringstream & ss);

public:
    NumericVar();
    virtual ~NumericVar();
    std::string getType();
    Var * clone(std::stringstream & ss);

};

class RealVar : public Var, StandardParser
{
private:
    void initialize(std::stringstream & ss);

public:
    RealVar();
    virtual ~RealVar();
    std::string getType();
    Var * clone(std::stringstream & ss);

};

class CharVar : public Var, StandardParser
{
private:
    void initialize(std::stringstream & ss);

public:
    CharVar();
    virtual ~CharVar();
    std::string getType();
    Var * clone(std::stringstream & ss);

};

class StringVar : public Var, StandardParser
{
private:
    int m_size;
    void initialize(std::stringstream & ss);

public:
    StringVar();
    virtual ~StringVar();
    std::string getType();
    Var * clone(std::stringstream & ss);

};

#endif /* __VAR_H */
