#include "Label.h"
#include "common.h"

using namespace std;

Label::Label()
: Parser(1,1)
{
    this->isjmp = false;
    this->islab = true;
}
Label::~Label() {}

void Label::execute(map<string, Var*>* tmp) 
{ this->label = args[0]; }

void Label::initialize(stringstream & ss) {
    Parse(ss);
}

Instructions * Label::clone (stringstream & ss)
{
    Label * label = new Label();
    try { label->initialize(ss); }
    catch(VariableException ve)
    {
        ve.printException();
        delete(label);  return nullptr;
    }
    return label;
}


