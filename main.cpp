#include "common.h"
#include "Instructions.h"
#include "Var.h"
#include "Parser.h"
#include "Math.h"
#include "Label.h"
#include "Jump.h"
#include "Sleep.h"
#include "Assign.h"

using namespace std;

map<string, Var*> vars;
vector <Instructions *> insn_vec;


void run_program() {
    int size = insn_vec.size();
    for (int i = 0; i < size; i++) {

        try {insn_vec[i]->execute(&vars);}
        catch(VariableException ve)
        { ve.printException(); break; }

        if (insn_vec[i]->isjmp) {
            if (!insn_vec[i]->can_jmp)
                continue;
            //cout << "JUMP\n";
            string jlab = insn_vec[i]->label;
            //cout << "JUMP LABEL: " << jlab << endl;
            for (int k = 0; k < size; k++) {
                if (insn_vec[k]->islab) {
                    insn_vec[k]->execute(&vars);//get label name
                    //cout << "LABEL\n";
                    string llab = insn_vec[k]->label;
                    //cout << "LABEL LABEL: " << llab << endl;
                    if(jlab.compare(llab) == 0) {
                        //cout << "EQUAL\n";
                        int tmp = insn_vec[k]->linenr + 1;
                        if (tmp < size) {
                            i = tmp;
                        } else {
                            i = tmp - 1;
                        }
                        break;
                    }
                }
            }
        }
    }
}

int main(int argc, char** argv){
    // vector<Instructions *> insn_vec;
    map <string,Var *> var_factory;
    //map<string,Var*> vars;
    map <string, Instructions *> insn;
    int count = 0;
    var_factory["NUMERIC"] = new NumericVar();
    var_factory["REAL"] = new RealVar();
    var_factory["CHAR"] = new CharVar();
    var_factory["STRING"] = new StringVar();

    insn["SUB"] = new Subtract();
    insn["DIV"] = new Divide();
    insn["ADD"] = new Add();
    insn["MUL"] = new Multiply();
    insn["OUT"] = new Out();
    insn["LABEL"] = new Label();
    insn["JMP"] = new jmp();
    insn["JMPZ"] = new jmpz(0);
    insn["JMPNZ"] = new jmpz(1);
    insn["JMPGT"] = new jmpgle(0);
    insn["JMPLT"] = new jmpgle(1);
    insn["JMPGTE"] = new jmpgle(2);
    insn["JMPLTE"] = new jmpgle(3);
    insn["SLEEP"] = new Sleep();
    insn["ASSIGN"] = new Assign();

    string line="";
    string file_name = string(argv[1]);
    if ( file_name.substr(file_name.length() - 4) != ".mis" )
    { cout << "Invalid file name." << endl; return 0;}
    ifstream readFile(file_name);
    ofstream outFile("a.out");
    ofstream errFile("a.err");

    cout.rdbuf(outFile.rdbuf());
    cerr.rdbuf(errFile.rdbuf());

    while( getline(readFile,line)) {
        string command ="";
        stringstream sline(line);
        getline(sline,command,' ');
        if( command == "VAR" ) {
            string name = "";
            getline(sline,name,',');
            name.erase( remove( name.begin(), name.end(),' '), name.end());
            string itemType ="";
            getline(sline,itemType,',');
            itemType.erase( remove( itemType.begin(), itemType.end(),' '), itemType.end());
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
            Instructions * obj = insn[command];
            if ( obj != NULL ) {                                              
                obj = obj->clone(sline);
                if ( obj != NULL ) {
                    obj->linenr = count++;
                    insn_vec.push_back(obj);
                }
            }
            else {
                cout << "Undefined Object Identifier: " << sline.str() << endl;
            }                
        } 
    } 
    readFile.close();
    run_program(); 
    outFile.close();
    errFile.close();

    for_each(vars.begin(),vars.end(),[](auto item)->void {
            delete item.second;
    });

    for_each(insn_vec.begin(),insn_vec.end(),[](auto item) -> void {
            delete item;
    });

    delete(var_factory["NUMERIC"]);
    delete(var_factory["REAL"]);
    delete(var_factory["CHAR"]);
    delete(var_factory["STRING"]);

    delete(insn["SUB"]);
    delete(insn["DIV"]);
    delete(insn["ADD"]);
    delete(insn["MUL"]);
    delete(insn["OUT"]);
    delete(insn["LABEL"]);
    delete(insn["JMP"]);
    delete(insn["JMPZ"]);
    delete(insn["JMPNZ"]);
    delete(insn["JMPGT"]);
    delete(insn["JMPLT"]);
    delete(insn["JMPGTE"]);
    delete(insn["JMPLTE"]);
    delete(insn["SLEEP"]);
    delete(insn["ASSIGN"]);
    return 0;
}
