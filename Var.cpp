#include "Var.h"
#include "VariableException.h"

Var::Var(){}
Var::~Var(){}
std::string Var::getValue() 
{ return value; }

void Var::setValue(const std::string & str)
{ value = str; }

NumericVar::NumericVar() : StandardParser(3,3) {}
NumericVar::~NumericVar(){}

std::string NumericVar::getType()
{ return args[1]; }

void NumericVar::initialize(std::stringstream & ss)
{
    try { Parse(ss); }
    catch (VariableException ve )
    { throw ve; }

    value = args[2];
    if ( !valid_numeric(value) )
        throw VariableValueException(ss.str(),value);
}

Var * NumericVar::clone(std::stringstream & ss)
{
    NumericVar * numeric_var = new NumericVar();

    try { numeric_var->initialize(ss); } 
    catch (VariableException ve) {
        ve.printException();
        delete(numeric_var); return nullptr;
    }
    return numeric_var;
}

RealVar::RealVar() : StandardParser(3,3) {}
RealVar::~RealVar(){}

std::string RealVar::getType()
{ return args[0]; }

void RealVar::initialize(std::stringstream & ss)
{
    try { Parse(ss); }
    catch (VariableException ve)
    { throw ve; }
    value = args[2];
    if ( !valid_real(value) )
        throw VariableValueException(ss.str(),value);
}

Var * RealVar::clone(std::stringstream & ss)
{
    RealVar * real_var = new RealVar();

    try { real_var->initialize(ss); } 
    catch (VariableException ve) {
        ve.printException();
        delete(real_var); return nullptr;
    }
    return real_var;
}

CharVar::CharVar() : StandardParser(3,3) {}
CharVar::~CharVar(){}

std::string CharVar::getType()
{ return args[0]; }

void CharVar::initialize(std::stringstream & ss) 
{ 
    try { Parse(ss); }
    catch (VariableException ve)
    { throw ve; }
    value = args[2];
    if ( !valid_char(value) )
        throw VariableValueException(ss.str(),value);
}

Var * CharVar::clone(std::stringstream & ss)
{
    CharVar * char_var = new CharVar();

    try{ char_var->initialize(ss); } 
    catch (VariableException ve) {
        ve.printException();
        delete(char_var); return nullptr;
    }

    return char_var;
}

StringVar::StringVar() : StandardParser(3,4) {}
StringVar::~StringVar(){}

std::string StringVar::getType()
{ return args[0]; }

void StringVar::initialize(std::stringstream & ss) 
{
    try { Parse(ss); }
    catch (VariableException ve)
    { throw ve; }
    if ( args.size() == 3 ){
        value = args[2];
        m_size = 256;
        if ( !valid_string(value) )
            throw VariableValueException(ss.str(),value);
    } else if ( args.size() == 4 ){
        value = args[3];
        if ( !valid_numeric(args[2]) )
        { throw VariableValueException(ss.str(),args[2]); return;}
        m_size = std::stoi(args[2]);
    }

    if ( !valid_string(value) )
        throw VariableValueException(ss.str(),value);
}

Var * StringVar::clone(std::stringstream & ss)
{
    StringVar * string_var = new StringVar();

    try { string_var->initialize(ss); } 
    catch (VariableException ve) {
        ve.printException();
        delete(string_var); return nullptr;
    }

    return string_var;
}
