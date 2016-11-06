#ifndef __PARSE_EXCEPTION_H
#define __PARSE_EXCEPTION_H

#include "common.h"

class ParseException
{
protected:
    std::string exception_str;
    std::string line;
public:
    ParseException(const std::string & p_line)
    {
        exception_str = "General Line Parsing Exception";
        line = p_line;
    }
    virtual void printException() final
    {
        std::cout << "\n>>>>Parsing Exception:" << std::endl;
        std::cout << "Problem parsing line:\n" << line << std::endl;
        std::cout << exception_str << std::endl << std::endl;
    }
    virtual ~ParseException(){}
};

#endif
