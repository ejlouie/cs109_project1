#include "ParseException.h"

ParseException::ParseException(const std::string & p_line )
{
    exception_str = "General Decode Exception";
    line = p_line;
}

void ParseException::printException()
{
    std::cout << "\n>>>>Parsing Excepion:" << std::endl;
    std::cout << "Problem parsing line: " << line << std::endl;
    std::cout << exception_str << std::endl;
}

ParseException::~ParseException() {}
