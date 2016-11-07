#include "common.h"
#include "Instructions.h"
#include "Parser.h"
#include "sub_div.h"
#include "add_mul.h"
#include "Label.h"
#include "jmp.h"
#include "jmpz.h"
#include "jmpgle.h"
#include "sleep.h"
#include "Insns_Parser.h"
#include "Var.h"
#include "out.h"

map<string, Var*> vars;
vector <Instructions *> insn_vec;


void run_program() {
  int size = insn_vec.size();
  for (int i = 0; i < size; i++) {
    if (insn_vec[i]->isjmp) {
      insn_vec[i]->execute(&vars);
      if (!insn_vec[i]->can_jmp)
	continue;
      //cout << "JUMP\n";
      string jlab = insn_vec[i]->label;
      //cout << "JUMP LABEL: " << jlab << endl;
      for (int k = 0; k < size; k++) {
        if (insn_vec[k]->islab) {
          insn_vec[k]->execute(&vars);
          //cout << "LABEL\n";
          string llab = insn_vec[k]->label;
          //cout << "LABEL LABEL: " << llab << endl;
          if(jlab.compare(llab) == 0) {
            //cout << "EQUAL\n";
	    int tmp = insn_vec[k]->linenr + 1;
	    if (tmp < size) {
	      i = tmp;
	    }else {
	      i = tmp - 1;
	    }
	    break;
	  }
        }
      }
    }
    insn_vec[i]->execute(&vars);
  }
  
}

int main(){
  // vector<Instructions *> insn_vec;
  std::map <std::string,Var *> var_factory;
  //std::map<std::string,Var*> vars;
  map <string, Instructions *> insn;
  int count = 0;
  var_factory["NUMERIC"] = new NumericVar();
  var_factory["REAL"] = new RealVar();
  var_factory["CHAR"] = new CharVar();
  var_factory["STRING"] = new StringVar();
  insn["SUB"] = new sub_div(0);
  insn["DIV"] = new sub_div(1);
  insn["ADD"] = new add_mul(0);
  insn["MUL"] = new add_mul(1);
  insn["OUT"] = new out();
  insn["LABEL"] = new Label();
  insn["JMP"] = new jmp();
  insn["JMPZ"] = new jmpz(0);
  insn["JMPNZ"] = new jmpz(1);
  insn["JMPGT"] = new jmpgle(0);
  insn["JMPLT"] = new jmpgle(1);
  insn["JMPGTE"] = new jmpgle(2);
  insn["JMPLTE"] = new jmpgle(3);
  insn["SLEEP"] = new sleep();
  std::string line="";
  std::ifstream readFile("hello.txt");
  while( getline(readFile,line)) {
    std::string command ="";
    std::stringstream sline(line);
    getline(sline,command,' ');
    if( command == "VAR" ) {
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
	  vars[name] = new_var;
	  new_var->dump();
	  //delete(new_var);
	}
      } else {
	VariableTypeException iv(sline.str(),itemType);
	iv.printException();
      }
    }
    else {
      string name1 = "";
      stringstream iss(line);                                            
      getline(iss, name1, ',');                                                       
      Instructions * obj = insn[name1];                                                      
      if ( obj != NULL ) {                                              
	obj = obj->clone(iss);                                                           
	obj->linenr = count++;
	//obj->execute(&vars);
	insn_vec.push_back(obj);                                                                                                        
	//delete(obj);
      }
      else {
	cout << "Undefined Object Identifier\n";                                    
      }                
    } 
  } 
  readFile.close();
  run_program(); 
  /*delete(var_factory["NUMERIC"]);
    delete(var_factory["REAL"]);
    delete(var_factory["CHAR"]);
    delete(var_factory["STRING"]);*/
  return 0;
}
