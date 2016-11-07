#include "out.h"

out::out() {
  this->isjmp = false;
  this->islab = false;
}

void out::execute(map<string, Var*>*) {
  int size = vec.size();
  if (size < 1 || size > 12) {
    cout << "Error: invalid parameters.\n";
    return;
  }
  for (int i = 0; i < size; i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
}

void out::paramatize(stringstream & ss) {
  parse(ss);
}

Instructions * out::clone(stringstream & ss) {
  out *j = new out();
  j->paramatize(ss);
  return j; 
}

out::~out() {}
