#include "sleep.h"

sleep::sleep() {
  this->isjmp = false;
  this->islab = false;
}

void sleep::execute(map<string, Var*>* tmp) {
  int num1;
  stringstream convert(vec[0]);
  convert>>num1;
  this_thread::sleep_for (chrono::seconds(num1));
}

void sleep::paramatize(stringstream & ss) {
  parse(ss);
}

Instructions * sleep::clone (stringstream & ss) {
  sleep * s = new sleep();
  s->paramatize(ss);
  return s;
}

sleep::~sleep() {}
