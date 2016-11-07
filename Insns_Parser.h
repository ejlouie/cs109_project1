#ifndef INSNS_PARSER_H
#define INSNS_PARSER_H

#include "common.h"

class Insns_Parser {
 public:
  vector <string> vec;
  void parse(stringstream & ss);
};


#endif
