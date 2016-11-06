#ifndef __VAR_H
#define __VAR_H

#include <algorithm>
#include <iostream>

#include "Parser.h"
#include "ParseException.h"

class Var
{
protected:
    virtual void initialize(std::stringstream & ss) = 0;

public:
    Var(){}
    ~Var(){}
    virtual Var * clone(std::stringstream & ss) = 0;
    virtual void dump() const = 0;

};

class NumericVar : public Var
{
private:
    int value;
    void initialize(std::stringstream & ss)
    {
        std::string str="";
        std::string::size_type sz;

        getline(ss,str,'\n');

        try{
            value = stoi(str,&sz);
        } catch(std::invalid_argument&) {
            throw InvalidVariable(ss.str());
        }

        if ( sz != str.length() )
            throw InvalidVariable(ss.str());
    }

public:
    NumericVar(){}
    virtual ~NumericVar(){}
    virtual Var * clone(std::stringstream & ss)
    {
        NumericVar * numeric_var = new NumericVar();
        try{
            numeric_var->initialize(ss);
        } catch (InvalidVariable iv) {
            iv.printException();
            delete(numeric_var);
            return nullptr;
        }

        return numeric_var;
    }

    void dump() const 
    { std::cout << "Value: " << value << std::endl; }

};

class RealVar : public Var
{
private:
    float value;
    void initialize(std::stringstream & ss)
    {
        std::string str="";
        std::string::size_type sz;

        getline(ss,str,'\n');

        try{
            value = stof(str,&sz);
        } catch(std::invalid_argument&) {
            throw InvalidVariable(ss.str());
        }

        if ( sz != str.length() )
            throw InvalidVariable(ss.str());
    }

public:
    RealVar(){}
    virtual ~RealVar(){}
    virtual Var * clone(std::stringstream & ss)
    {
        RealVar * real_var = new RealVar();
        try {
            real_var->initialize(ss);
        } catch (InvalidVariable iv) {
            iv.printException();
            delete(real_var);
            return nullptr;
        }

        return real_var;
    }

    void dump() const 
    { std::cout << "Value: " << value << std::endl; }

};

class CharVar : public Var
{
private:
    char value;
    void initialize(std::stringstream & ss) 
    { 
        std::string str="";
        getline(ss,str,'\n');
    }

public:
    CharVar(){}
    virtual ~CharVar(){}
    virtual Var * clone(std::stringstream & ss)
    {
        CharVar * char_var = new CharVar();
        char_var->initialize(ss);

        return char_var;
    }

    void dump() const 
    { std::cout << "Value: " << value << std::endl; }

};

class StringVar : public Var
{
private:
    std::string value;
    void initialize(std::stringstream & ss) 
    { ss >> value; }

public:
    StringVar(){}
    virtual ~StringVar(){}
    virtual Var * clone(std::stringstream & ss)
    {
        StringVar * string_var = new StringVar();
        string_var->initialize(ss);

        return string_var;
    }
    void dump() const 
    { std::cout << "Value: " << value << std::endl; }

};

#endif /* __VAR_H */
