 #include "jmp.h"

jmp::jmp() {
  this->isjmp = true;
  this->islab = false;
  this->can_jmp = false;
}

void jmp::execute(map<string, Var*>* tmp) {
  this->can_jmp = true;
  this->label = vec[0];
}

void jmp::paramatize(stringstream & ss) {
  parse(ss);
}

Instructions * jmp::clone (stringstream & ss) {
  jmp * j = new jmp();
  j->paramatize(ss);
  return j;
}

jmp::~jmp() {}
