#include "DecodeException.h"

DecodeExcepion::DecodeExcepion(const std::string & p_line )
{
    exception_str = "General Decode Exception";
    line = p_line;
}

void DecodeExcepion::printException()
{
    std::cout << "Decode Excepion:" << std::endl;
    std::cout << "Problem parsing line: " << line << std::endl;
    std::cout << exception_str << std::endl;
}

DecodeExcepion::~DecodeExcepion() {}
