#include "common.h"
#include "Instructions.h"
#include "InstructionException.h"
#include "Parser.h"
#include "Var.h"

using namespace std;

double Instructions::get_numeric(string str,map<string,Var*>* vars)
{
    string value;
    string::size_type sz;
    double converted_value;
    if ( str[0] == '$' )
    {
        Var * var = vars->operator[](str);
        if ( var != nullptr )
        {
            value = var->getValue();
            try{ converted_value = stod(value,&sz); }
            catch(invalid_argument&)
            { throw VariableValueException(value);}
            if ( sz != value.length())
                throw VariableValueException(value);
        } else throw VariableValueException(str);

    } else {
        try{ converted_value = stod(str,&sz); }
        catch(invalid_argument&)
        { throw VariableValueException(str);}
        if ( sz != str.length())
            throw VariableValueException(str);
    }
    return converted_value;
}

// *************************************** //
// OUT

Out::Out() : Parser(1,12){}
Out::~Out(){}

void Out::execute(map<string, Var*>* vars)
{
    for_each(args.begin(), args.end(), [vars](auto itr) -> void {
        Var * var = vars->operator[](itr);
        if ( var != nullptr )
            cout << var->getValue();
        else cout << itr << " ";
    });
    cout << endl;
}

void Out::initialize(stringstream & ss)
{
    Parse(ss);
}

Instructions * Out::clone(stringstream & ss)
{
    Out * out = new Out();
    try { out->initialize(ss); }
    catch( VariableException ve ) { 
      ve.printException();
      delete(out);  return nullptr;
    }
    return out; 
}
