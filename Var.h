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

class NumericVar : public Var, Parser
{
private:
    int value;
    void initialize(std::stringstream & ss)
    {
        std::string str="";
        getline(ss,str,'\n');

        if (std::all_of (str.begin(), str.end(), [](unsigned char c) {
                return std::isdigit(c); }))
        { value = std::stoi(str); }

        else throw InvalidNumeric(ss.str());
    }

public:
    NumericVar(){}
    virtual ~NumericVar(){}
    virtual Var * clone(std::stringstream & ss)
    {
        NumericVar * numeric_var = new NumericVar();
        try{
            numeric_var->initialize(ss);
        } catch (InvalidNumeric in) {
            in.printException();
            delete(numeric_var);
            return nullptr;
        }

        return numeric_var;
    }

    void dump() const 
    { std::cout << "Value: " << value << std::endl; }

};

class RealVar : public Var, Parser
{
private:
    float value;
    void initialize(std::stringstream & ss) 
    { 
        std::string str="";
        getline(ss,str,'\n');

        bool contains_commas; 
        bool is_alpha;
        contains_commas = std::any_of (str.begin(), str.end(), [] (unsigned char c) {
                    return c == ',';
                    });
        is_alpha = std::any_of (str.begin(), str.end(), [] (unsigned char c) {
                    return std::isalpha(c);
                    });

        if ( !contains_commas && !is_alpha )
        { value = stof(str); }
        else throw InvalidReal(ss.str());
    }

public:
    RealVar(){}
    virtual ~RealVar(){}
    virtual Var * clone(std::stringstream & ss)
    {
        RealVar * real_var = new RealVar();
        try {
            real_var->initialize(ss);
        } catch (InvalidReal ir) {
            ir.printException();
            delete(real_var);
            return nullptr;
        }

        return real_var;
    }

    void dump() const 
    { std::cout << "Value: " << value << std::endl; }

};

class CharVar : public Var, Parser
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

class StringVar : public Var, Parser
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
