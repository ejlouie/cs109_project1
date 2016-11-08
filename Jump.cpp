#include "Jump.h"

using namespace std;

jmp::jmp(const int & p_min, const int & p_max ) : Parser(p_min,p_max) {
    this->isjmp = true;
    this->islab = false;
    this->can_jmp = false;
}
jmp::~jmp() {}

void jmp::execute(map<string, Var*>* tmp)
{
    this->can_jmp = true;
    this->label = args[0];
}

void jmp::initialize (stringstream & ss)
{
    Parse(ss);
}

Instructions * jmp::clone (stringstream & ss) 
{
    jmp * jump = new jmp();
    try { jump->initialize(ss); }
    catch (VariableException ve)
    {
        ve.printException();
        delete(jump);   return nullptr;
    }
    return jump;
}

// ***************************
// jmp
jmpz::jmpz(const int & specifier) : jmp(2,2) 
{
    this->specifier = specifier;
    this->isjmp = true;
    this->islab = false;
    this->can_jmp = false;
}

jmpz::~jmpz() {}

void jmpz::execute(map<string, Var*>* vars)
{
    this->label = args[0];
    
    double num;
    try { num = get_numeric(args[1],vars); }
    catch( VariableException ve )
    { throw ve; return;}

    if (specifier == 0) {
        this->can_jmp = (num == 0);
    } else if (specifier == 1) {
        this->can_jmp = (num!=0);
    } 
}

Instructions * jmpz::clone (stringstream & ss) 
{
    jmpz * jump_z = new jmpz(this->specifier);
    try { jump_z->initialize(ss); }
    catch (VariableException ve)
    {
        ve.printException();
        delete(jump_z);    return nullptr;
    }
    return jump_z;
}

// ************************************
// jmpgle
jmpgle::jmpgle(const int & specifier) : jmp(3,3) 
{
  this->specifier = specifier;
  this->isjmp = true;
  this->islab = false;
  this->can_jmp = false;
  //this->label = "";
}
jmpgle::~jmpgle() {}

void jmpgle::execute(map<string, Var*>* vars)
{
    this->label = args[0];
    double num1,num2;
    try {
        num1 = get_numeric(args[1],vars);
        num2 = get_numeric(args[2],vars);
    } catch(VariableException ve)
    { throw ve; }

    switch(specifier)
    {
    case 0: this->can_jmp = (num1>num2); break;
    case 1: this->can_jmp = (num1<num2); break;
    case 2: this->can_jmp = (num1>=num2); break;
    case 3: this->can_jmp = (num1<=num2); break;
    }
    /*
    if (specifier == 0) {
        this->can_jmp = (num1>num2);
    }else if (specifier == 1) {
        this->can_jmp = (num1<num2);
    }else if (specifier == 2) {
        this->can_jmp = (num1>=num2);
    }else if (specifier == 3) {
        this->can_jmp = (num1<=num2);
    }
    */
}

Instructions * jmpgle::clone (stringstream & ss)
{
    jmpgle * jump_gle = new jmpgle(this->specifier);
    try { jump_gle->initialize(ss); }
    catch( VariableException ve)
    {
        ve.printException();
        delete(jump_gle);   return nullptr;
    }
    return jump_gle;
}
