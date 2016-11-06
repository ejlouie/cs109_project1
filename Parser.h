#ifndef __PARSER_H
#define __PARSER_H

#include <vector>
#include <string>
#include <sstream>


class Parser
{
protected:
    std::vector<std::string> args;

public:
    Parser(){}
    ~Parser(){}
    void Parse(std::stringstream & ss)
    {
        std::string str = "";

        while( std::getline(ss,str,',') )
        { args.push_back(str); }

        std::getline(ss,str,'\n');
        args.push_back(str);

        for( auto x = args.begin(); x != args.end(); x++ )
            std::cout << x[0] << std::endl;
    }
};

#endif /* __PARSER_H */
