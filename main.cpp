#include "common.h"
#include "Instructions.h"
#include "Parser.h"
#include "sub_div.h"
#include "add_mul.h"
#include "Insns_Parser.h"
#include "Var.h"
#include "out.h"

int main(){
  std::map <std::string,Var *> var_factory;
  std::map<std::string,Var*> vars;
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
      //string line = "";
      //ifstream readFile("dummy.mis");
      string name1 = "";
      //while(getline(readFile,line)) { // Loop through the file lines                                                                                                                                                                                       
      stringstream iss(line); // INstantiate stringstream with the current line just read                                                                                                                                                                 
      getline(iss, name1, ','); // Parse token until the first comma and store it in name                                                                                                                                                                 
      Instructions * obj = insn[name1]; //Fetch the corresponding object from map using name                                                                                                                                                               
      if ( obj != NULL ) { // If can find an object with name index                                                                                                                                                                                        
	obj = obj->clone(iss); // Clone an object of the same type                                                                                                                                                                                         
	obj->linenr = count++;
	obj->execute(&vars);                                                                                                        
	delete(obj);
      }
      else {
	cout << "Undefined Object Identifier\n"; // Cannot find object type in map                                                                                                                                                      
      }                
    } 
  } 
  readFile.close();
  /*delete(var_factory["NUMERIC"]);
    delete(var_factory["REAL"]);
    delete(var_factory["CHAR"]);
    delete(var_factory["STRING"]);*/
  return 0;
}
