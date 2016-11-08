#include "Math.h"
#include "Var.h"
#include "InstructionException.h"

Math::Math (const int & p_max) : StandardParser(3,p_max) {}
Math::~Math(){}

void Math::execute(std::map<std::string, Var*>* vars) {

    std::vector<double> number_args;

    for_each(args.begin() + 1, args.end(), [this,&number_args,vars] (auto item) -> void {
        Var * var = vars->operator[](item);

        if ( var != nullptr )
        {
            std::string val = var->getValue();
            if( this->valid_numeric(val) || this->valid_real(val) )
                number_args.push_back(std::stod(var->getValue()));
            
        } else number_args.push_back(std::stod(item)); 
            // data types of args have already been checked in initialize
    });

    double solution = Operation(number_args);

    Var * var = vars->operator[](args[0]);

    if ( var != nullptr ) var->setValue(std::to_string(solution));
    else throw InstructionArgException(args);
}

void Math::initialize(std::stringstream & ss)
{
    try { Parse(ss); }
    catch ( VariableException ve )
    { throw ve; return; }

    // checking if all arguments are either REAL, NUMERIC, or Variables
    bool parsed = all_of ( args.begin() + 1, args.end(),[this] (auto item) -> bool {
            return (this->valid_real(item) || this->valid_numeric(item) || this->valid_var(item));
        });
    if ( !parsed )
        throw VariableException(ss.str());
}

Add::Add() : Math(13) {}
Add::~Add() {}

double Add::Operation(std::vector<double>v)
{
    double sum = v[0];
    for( int i = 1; i < v.size(); i++ )
        sum += v[i];
    return sum;
}


Instructions * Add::clone (std::stringstream & ss) {
    Add * add = new Add();
    try { add->initialize(ss); }
    catch( VariableException ve )
    {
        ve.printException();
        delete(add);    return nullptr;
    }
    return add;
}


Subtract::Subtract() : Math(3) {}
Subtract::~Subtract() {}

double Subtract::Operation(std::vector<double> v)
{ return v[0] - v[1]; }

Instructions * Subtract::clone (std::stringstream & ss) {
    Subtract * subtract = new Subtract();
    try { subtract->initialize(ss); }
    catch( VariableException ve )
    {
        ve.printException();
        delete(subtract);    return nullptr;
    }
    return subtract;
}

Multiply::Multiply() : Math(13) {}
Multiply::~Multiply() {}
double Multiply::Operation(std::vector<double>v)
{
    double sum = v[0];
    for( int i = 1; i < v.size(); i++ )
        sum *= v[i];
    return sum;
}

Instructions * Multiply::clone (std::stringstream & ss) {
    Multiply * multiply = new Multiply();
    try { multiply->initialize(ss); }
    catch( VariableException ve )
    {
        ve.printException();
        delete(multiply);    return nullptr;
    }
    return multiply;
}

Divide::Divide() : Math(3) {}
Divide::~Divide() {}
double Divide::Operation(std::vector<double>v)
{
    return v[0] / v[1];
}

Instructions * Divide::clone (std::stringstream & ss) {
    Divide * divide = new Divide();
    try { divide->initialize(ss); }
    catch( VariableException ve )
    {
        ve.printException();
        delete(divide);    return nullptr;
    }
    return divide;
}

