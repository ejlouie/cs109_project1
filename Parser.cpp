#include "Parser.h"

Parser::Parser(const int & p_min, const int & p_max) 
: min_size(p_min), max_size(p_max){}
Parser::~Parser(){}

void Parser::remove_whitespace(std::string & str) const
{ str.erase( std::remove( str.begin(), str.end(),' '), str.end()); }


void Parser::Parse(std::stringstream & ss)
{
    ss.seekg(0);
    std::string str = "";

    getline(ss,str,' '); // command name. 

    while( getline(ss,str,',') ){
        remove_whitespace(str);
        args.push_back(str);
    }

    if ( args.size() > max_size || args.size() < min_size )
        throw VariableCountException(ss.str());
}

StandardParser::StandardParser(const int & p_min, const int & p_max) 
: Parser(p_min,p_max) {}
StandardParser::~StandardParser(){}

bool StandardParser::valid_numeric(const std::string & str) const
{
    std::string::size_type sz;

    int test;
    try { test = std::stoi(str,&sz); }
    catch (std::invalid_argument&)
    { return false;}

    if (sz != str.length() ) return false;
    return true;
}

bool StandardParser::valid_real(const std::string & str) const
{
    std::string::size_type sz;

    double test;
    try { test = std::stod(str,&sz); }
    catch (std::invalid_argument&)
    { return false;}

    if (sz != str.length() ) return false;
    return true;
}

bool StandardParser::valid_char(const std::string & str) const
{
    return ( str.length() == 3 && str[0] == '\'' 
            && str[2] == '\'' && std::isalpha(str[1]));
}

bool StandardParser::valid_string(const std::string & str) const
{
    return ( str[0] == '"' && str[str.length() - 1] == '"' );
}

bool StandardParser::valid_var(const std::string & str) const
{
    return str[0] == '$';
}

void StandardParser::Parse(std::stringstream & ss)
{
    try { Parser::Parse(ss); }
    catch (VariableException ve)
    { throw ve; }
    if ( !valid_var(args[0]) )
        throw VariableNameException(ss.str(),args[0]);
}
