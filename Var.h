#ifndef __VAR_H
#define __VAR_H

#include "common.h"
#include "Parser.h"
#include "VariableException.h"

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
        Parse(ss);
        std::string::size_type sz;

        try {
            value = std::stoi(args[3],&sz);
        } catch(std::invalid_argument&){
            throw VariableValueException(ss.str(),args[3]);
        }

        if ( sz != args[3].length() )
            throw VariableValueException(ss.str(),args[3]);
    }

public:
    NumericVar() : Parser(4) {}
    virtual ~NumericVar(){}
    virtual Var * clone(std::stringstream & ss)
    {
        NumericVar * numeric_var = new NumericVar();

        try{
            numeric_var->initialize(ss);
        } catch (VariableException pe) {
            pe.printException();
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
        Parse(ss);
        std::string::size_type sz;

        try {
            value = std::stof(args[3],&sz);
        } catch (std::invalid_argument&) {
            throw VariableValueException(ss.str(),args[3]);
        }

        if ( sz != args[3].length() )
            throw VariableValueException(ss.str(),args[3]);
    }

public:
    RealVar() : Parser(4) {}
    virtual ~RealVar(){}
    virtual Var * clone(std::stringstream & ss)
    {
        RealVar * real_var = new RealVar();
        try {
            real_var->initialize(ss);
        } catch (VariableException iv) {
            iv.printException();
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
        Parse(ss);

        value = args[3][1];

        if ( args[3].length() != 3 || !isalpha(value) )
            throw VariableValueException(ss.str(),args[3]);
    }

public:
    CharVar() : Parser(4) {}
    virtual ~CharVar(){}
    virtual Var * clone(std::stringstream & ss)
    {
        CharVar * char_var = new CharVar();
        try{
            char_var->initialize(ss);
        } catch (VariableException iv) {
            iv.printException();
            delete(char_var);
            return nullptr;
        }

        return char_var;
    }

    void dump() const 
    { std::cout << "Value: " << value << std::endl; }

};

class StringVar : public Var, Parser
{
private:
    std::string value;
    int m_size;
    void initialize(std::stringstream & ss) 
    {
        Parse(ss);
        if ( args.size() == 4 ){
            value = args[3];
            m_size = 256;
        } else if ( args.size() == 5 ){
            value = args[4];
            std::string::size_type sz;
            try { 
                m_size = std::stoi(args[3],&sz);
            } catch (std::invalid_argument&){
                throw VariableValueException(ss.str(),args[3]);
            }
            if ( sz != args[3].length() )
                throw VariableValueException(ss.str(),args[3]);

        } else throw VariableException(ss.str());
    }

public:
    StringVar() : Parser(5){}
    virtual ~StringVar(){}
    virtual Var * clone(std::stringstream & ss)
    {
        StringVar * string_var = new StringVar();
        try {
            string_var->initialize(ss);
        } catch (VariableException ve) {
            ve.printException();
            delete(string_var);
            return nullptr;
        }

        return string_var;
    }

    void dump() const 
    { std::cout << "Value: " << value << std::endl; }

};

#endif /* __VAR_H */
