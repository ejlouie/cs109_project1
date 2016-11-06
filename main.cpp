#include "common.h"

#include "Parser.h"
#include "Var.h"

int main(){

    std::map <std::string,Var *> var_factory;
    std::map<std::string,Var*> vars;

    var_factory["NUMERIC"] = new NumericVar();
    var_factory["REAL"] = new RealVar();
    var_factory["CHAR"] = new CharVar();
    var_factory["STRING"] = new StringVar();

    std::string line="";
    std::ifstream readFile("hello.txt");

    while( getline(readFile,line))
    {
        std::string command ="";
        std::stringstream sline(line);
        getline(sline,command,' ');

        if( command == "VAR" )
        {
            std::string name = "";
            getline(sline,name,',');
            name.erase( std::remove( name.begin(), name.end(),' '), name.end());
            std::string itemType ="";
            getline(sline,itemType,',');
            itemType.erase( std::remove( itemType.begin(), itemType.end(),' '), itemType.end());

            Var * new_var = var_factory[itemType];

            if ( new_var != NULL ){
                new_var = new_var->clone(sline);

                if ( new_var != NULL ){
                    std::cout << "Variable Discovered: " << itemType << std::endl;
                    new_var->dump();
                    delete(new_var);
                }
            } else {
                VariableTypeException iv(sline.str(),itemType);
                iv.printException();
            }
        }
        else
        { 
            // Instructions
        }
    }

    readFile.close();

    delete(var_factory["NUMERIC"]);
    delete(var_factory["REAL"]);
    delete(var_factory["CHAR"]);
    delete(var_factory["STRING"]);

    return 0;
}
