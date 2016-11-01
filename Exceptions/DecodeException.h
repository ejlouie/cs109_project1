#ifndef __DECODE_EXCEPTION_H
#define __DECODE_EXCEPTION_H

class DecodeException
{
protected:
    std::string exception_str;
    std::string line;
public:
    DecodeException(const std::string & p_line);
    virtual void printException() final;
    virtual ~DecodeException();
};

class InstructionException : public DecodeException
{
public:
    InstructionException(const std::string & p_line)
        : DecodeException(p_line)
    {
        exception_str = "Invalid command";
    }
};

#endif
