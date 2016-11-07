#include "Label.h"

Label::Label() {
  this->isjmp = false;
  this->islab = true;
  //this->label = "";
}

void Label::execute(map<string, Var*>* tmp) {
  this->label = vec[0];
}

void Label::paramatize(stringstream & ss) {
  parse(ss);
}

Instructions * Label::clone (stringstream & ss) {
  Label * l = new Label();
  l->paramatize(ss);
  return l;
}

Label::~Label() {}

