#ifndef __PARSER_H
#define __PARSER_H

#include "common.h"
#include "ParseException.h"

class Parser
{
protected:
    int m_max_size;
    std::vector<std::string> args;

public:
    Parser(const int & max_size) : m_max_size(max_size) {}
    ~Parser(){}

    void Parse(std::stringstream & ss)
    {
        ss.seekg(0);
        std::string str = "";

        getline(ss,str,' ');

        while( getline(ss,str,',') )
        { 
            str.erase( std::remove( str.begin(), str.end(),' '), str.end());
            args.push_back(str); 
        }

        getline(ss,str,'\n');
        args.push_back(str);

        if (args.size() > m_max_size)
            throw ParseException(ss.str());
    }

    void dump() const
    {
        for( auto x = args.begin(); x != args.end(); x++)
            std::cout << x[0];
    }
};

#endif /* __PARSER_H */
