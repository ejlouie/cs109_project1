#ifndef __DECODER_H
#define __DECODER_H

#include <stack>
#include <vector>
#include <fstream>
#include <iostream>


//class Instruction;

class Decoder
{
public:
    Decoder(const std::string & file_path_in
            //,
            //const std::string & file_path_out, 
            //const std::string & file_path_err, 
            //std::stack<int> * ints, 
            //std::stack> * floats, 
            //std::stack<char> * chars, 
            //std::stack<std::string> * strings, 
            //std::stack<Instruction> * instructions
           )

        //:file_in(file_path_in), file_out(file_path_out), file_err(file_path_err)
    {
        file_in.open(file_path_in);

        //this->instructions = instructions;
        //this->vars_int = ints;
        //this->vars_float = floats;
        //this->vars_string = strings;
    }

    ~Decoder()
    {
        file_in.close();
        //file_out.close();
        //file_err.close();
    }

    void decode();

private:

    std::vector<std::string> readline (const std::string & file);
    bool add_variable (const std::vector<std::string> & params);

    std::ifstream file_in;
    //std::ifstream file_out;
    //std::ifstream file_err;

    //std::stack<Instruction> * instructions;
    
    //std::stack<std::map<std::string,int>> * vars_int;
    //std::stack<float> * vars_float;
    //std::stack<char> * vars_char;
    //std::stack<std::string> * vars_string;
};


#endif
