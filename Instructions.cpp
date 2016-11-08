#include "common.h"
#include "Instructions.h"
#include "InstructionException.h"
#include "Parser.h"
#include "Var.h"

// *************************************** //
// OUT

Out::Out() : Parser(1,12){}
Out::~Out(){}

void Out::execute(std::map<std::string, Var*>* vars)
{
    for_each(args.begin(), args.end(), [vars](auto itr) -> void {
        Var * var = vars->operator[](itr);
        if ( var != nullptr )
            std::cout << var->getValue();
        else std::cout << itr[0] << " ";
    });
    
    std::cout << std::endl;
}

void Out::initialize(std::stringstream & ss)
{
    Parse(ss);
}

Instructions * Out::clone(std::stringstream & ss)
{
    Out * out = new Out();
    try { out->initialize(ss); }
    catch( VariableException ve ) { 
      ve.printException();
      delete(out);  return nullptr;
    }
    return out; 
}
