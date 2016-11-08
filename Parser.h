#ifndef __PARSER_H
#define __PARSER_H

#include "VariableException.h"

class Parser
{
private:
    void remove_whitespace(std::string & str) const;
        // removes white space from str

    int max_size;
        // max number of arguments
        
    int min_size;
        // max number of arguments

protected:
    std::vector<std::string> args;

public:
    Parser(const int & p_min, const int & p_max);
    ~Parser();
    void Parse(std::stringstream & ss);
};

class StandardParser : public Parser
{
protected:
    bool valid_numeric(const std::string & str) const;
        // checks if the input string is a valid NUMERIC

    bool valid_real(const std::string & str) const;
        // checks if the input string is a valid REAL

    bool valid_char(const std::string & str) const;
        // checks if the input string is a valid CHAR

    bool valid_string(const std::string & str) const;
        // checks if the input string is a valid STRING

    bool valid_var(const std::string & str) const;
        // checks if the input string is a valid variable

public:
    StandardParser(const int & p_min, const int & p_max);
    ~StandardParser();
    void Parse(std::stringstream & ss);

};

#endif /* __PARSER_H */
