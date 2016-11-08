#ifndef __INSTRUCTION_EXCEPTION_H
#define __INSTRUCTION_EXCEPTION_H

#include "common.h"

class InstructionException
{
protected:
    std::string exception_str;
    std::vector<std::string> line;
public:
    InstructionException(const std::vector<std::string> & p_line)
    {
        exception_str = "General Instruction Parsing Exception";
        line = p_line;
    }
    virtual void printException() final
    {
        std::cerr << "\n>>>>Parsing Exception:" << std::endl;
        std::cerr << "Problem parsing instruction:\n";
        for_each( line.begin(), line.end(), [](auto item) -> void {
            std::cerr << item << ",";
        });
        std::cerr << exception_str << std::endl << std::endl;
    }
    virtual ~InstructionException(){}
};

class InstructionArgException : public InstructionException
{
public:
    InstructionArgException (const std::vector<std::string> & p_line)
        : InstructionException(p_line)
    {
        exception_str = "Instruction arguments are invalid";
    }
};

#endif
