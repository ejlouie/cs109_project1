#include "common.h"

#include "Var.h"
#include "Instructions.h"
#include "Math.h"

int main(){

    std::map <std::string,Var *> var_factory;
    std::map<std::string,Var*> vars;
    std::map <std::string, Instructions *> insn;
    int count = 0;

    var_factory["NUMERIC"] = new NumericVar();
    var_factory["REAL"] = new RealVar();
    var_factory["CHAR"] = new CharVar();
    var_factory["STRING"] = new StringVar();

    insn["ADD"] = new Add();
    insn["SUB"] = new Subtract();
    //insn["DIV"] = new SubDiv(1);
    insn["OUT"] = new Out();

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
                    vars[name] = new_var;
                }
            } else {
                VariableTypeException iv(sline.str(),itemType);
                iv.printException();
            }
        }
        else { 
            Instructions * obj = insn[command]; //Fetch the corresponding object from map

            if ( obj != NULL ) { // If can find an object with name inde  
                obj = obj->clone(sline); // Clone an object of the same type  
                if ( obj != NULL) {
                    obj->linenr = count++;
                    obj->execute(&vars); 
                    delete(obj);
                } else break;
            }
        }
    }

    readFile.close();

    for_each (vars.begin(), vars.end(),[](auto item) -> void {
        delete(item.second);
    });

    delete(var_factory["NUMERIC"]);
    delete(var_factory["REAL"]);
    delete(var_factory["CHAR"]);
    delete(var_factory["STRING"]);

    return 0;
}
