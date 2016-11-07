#ifndef __PARSER_H
#define __PARSER_H

#include "common.h"
#include "ParseException.h"

class Parser
{
 private:
  void remove_whitespace(std::string & str)
  { str.erase( std::remove( str.begin(), str.end(),' '), str.end()); }

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

    while( getline(ss,str,',') ){
      remove_whitespace(str);
      args.push_back(str);
    }

    if (args.size() > m_max_size)
      throw ParseException(ss.str());
  }
};

#endif /* __PARSER_H */
