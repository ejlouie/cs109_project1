#ifndef __PARSE_EXCEPTION_H
#define __PARSE_EXCEPTION_H

#include "common.h"

class ParseException
{
protected:
    std::string exception_str;
    std::string line;
public:
    ParseException(const std::string & p_line);
    virtual void printException() final;
    virtual ~ParseException();
};

class InvalidLineException : public ParseException
{
public:
    InvalidLineException(const std::string & p_line)
        : ParseException(p_line)
    {
        exception_str = "Invalid Line";
    }
};

class InvalidVariable : public ParseException
{
public:
    InvalidVariable(const std::string & p_line)
        : ParseException(p_line)
    {
        exception_str = "Numeric value is invalid.";
    }
};

#endif
