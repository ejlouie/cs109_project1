#include "Sleep.h"
#include "common.h"

using namespace std;

Sleep::Sleep() : Parser(1,1)
{
  this->isjmp = false;
  this->islab = false;
}
Sleep::~Sleep() {}

void Sleep::execute(map<string, Var*>* tmp) {
  int num1;
  stringstream convert(args[0]);
  convert>>num1;
  this_thread::sleep_for (chrono::seconds(num1));
}

void Sleep::initialize(stringstream & ss) 
{
    Parse(ss);
}

Instructions * Sleep::clone (stringstream & ss) 
{
    Sleep * sleep = new Sleep();
    try { sleep->initialize(ss); }
    catch( VariableException ve)
    {
        ve.printException();
        delete(sleep);  return nullptr;
    }
    return sleep;
}

