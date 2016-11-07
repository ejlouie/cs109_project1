#include "Insns_Parser.h"

void Insns_Parser::parse(stringstream & ss) {
  string str = "";
  while (getline(ss, str,',')) {
    vec.push_back(str);
  }                    
  getline(ss,str,'\n');        
  vec.push_back(str);                                                                               
}
