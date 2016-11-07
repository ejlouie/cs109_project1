#ifndef __VARIABLE_EXCEPTION_H
#define __VARIABLEPARSE_EXCEPTION_H

#include "common.h"

class VariableException
{
protected:
    std::string exception_str;
    std::string line;
public:
    VariableException(const std::string & p_line)
    {
        exception_str = "General Variable Parsing Exception";
        line = p_line;
    }
    virtual void printException() final
    {
        std::cout << "\n>>>>Parsing Exception:" << std::endl;
        std::cout << "Problem parsing Variable Declaration:\n" << line << std::endl;
        std::cout << exception_str << std::endl << std::endl;
    }
    virtual ~VariableException(){}
};

class VariableValueException : public VariableException
{
public:
    VariableValueException(const std::string & p_line, const std::string & p_value)
        : VariableException(p_line)
    {
        exception_str = "Variable value is invalid: " + p_value;
    }
};

class VariableTypeException : public VariableException
{
public:
    VariableTypeException(const std::string & p_line, const std::string & p_type)
        : VariableException(p_line)
    {
        exception_str = "Variable type is invalid: " + p_type;
    }
};

class VariableNameException : public VariableException
{
public:
    VariableNameException(const std::string & p_line, const std::string & p_name)
        : VariableException(p_line)
    {
        exception_str = "Variable name is invalid: " + p_name;
    }
};
#endif
