#include "common.h"

#include "Parser.h"
#include "Var.h"

using namespace std;

int main(){

    map <string,Var *> var_factory;

    var_factory["NUMERIC"] = new NumericVar();
    var_factory["REAL"] = new RealVar();
    var_factory["CHAR"] = new CharVar();
    var_factory["STRING"] = new StringVar();

    string line="";
    ifstream readFile("hello.txt");
    string command = "";

    while( getline(readFile,line))
    {
        stringstream iss(line);
        getline(iss,command,' '); 
        if( command == "VAR" )
        {
            string name = "";
            getline(iss,name,',');
            string itemType = "";
            getline(iss,itemType,',');

            Var * new_var = var_factory[itemType];

            if ( new_var != NULL ){
                new_var = new_var->clone(iss);

                if ( new_var != NULL ){
                    cout << "Variable Discovered!" << endl;
                    new_var->dump();
                    delete(new_var);
                }
                else cout << "Undefined Variable." << endl;
            }
            else cout << "Undefined Variable." << endl;
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
