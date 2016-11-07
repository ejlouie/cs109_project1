#ifndef __PARSER_H
#define __PARSER_H

#include "common.h"
#include "ParseException.h"
#include "VariableException.h"

class Parser
{
private:
    void remove_whitespace(std::string & str)
    { str.erase( std::remove( str.begin(), str.end(),' '), str.end()); }

protected:
    std::vector<std::string> args;

public:
    Parser(){}
    ~Parser(){}

    void Parse(std::stringstream & ss)
    {
        ss.seekg(0);
        std::string str = "";

        getline(ss,str,' ');

        while( getline(ss,str,',') ){
            if(str[0] != '"' && str[str.length() - 1] != '"') 
                remove_whitespace(str);
            args.push_back(str);
        }

    }
};

class VarParser : public Parser
{
public:
    VarParser(){}
    ~VarParser(){}
    void Parse(std::stringstream & ss)
    {
        Parser::Parse(ss);

        if ( args[0][0] != '$' )
            throw VariableNameException(ss.str(), args[0]);
        if ( args.size() > 4 )
            throw VariableException(ss.str());
    }
};

#endif /* __PARSER_H */
