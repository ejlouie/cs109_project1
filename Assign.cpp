#include "Assign.h"
#include "Var.h"
#include "VariableException.h"
#include "InstructionException.h"

using namespace std;

Assign::Assign()
:StandardParser(2,2) {}
Assign::~Assign(){}

void Assign::execute (map<string, Var*>* vars)
{
    Var * var = vars->operator[](args[0]);

    if ( var == nullptr )
    { throw InstructionException(args); return; }

    string varType = var->getType();
    string new_value;

    if ( valid_var(args[1]) ) {
        Var * from_var = vars->operator[](args[1]);

        if ( from_var == nullptr )
        { throw InstructionException(args); return;}

        if ( from_var->getType() != varType )
        { throw InstructionException(args); return;}

        new_value = from_var->getValue();

    } else if ( (varType == "NUMERIC" || varType == "REAL") 
            && ( valid_numeric(args[1]) || valid_real(args[1]) ) ) { 
        new_value = args[1]; 
    } else if ( varType == "STRING" && valid_string(args[1]) ){
        new_value = args[1];
    } else if ( varType == "CHAR" && valid_char(args[1])) {
        new_value = args[1];
    }


    var->setValue(new_value);
}

void Assign::initialize (stringstream & ss)
{
    try { Parse(ss); }
    catch( VariableException ve )
    { throw ve; }

}
Instructions * Assign::clone (stringstream & ss)
{
    Assign * assign = new Assign();
    try { assign->initialize(ss); }
    catch( VariableException ve )
    {
        ve.printException();
        delete(assign);     return nullptr;
    }
    return assign;
}
