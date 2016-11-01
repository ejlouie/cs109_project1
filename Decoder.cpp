#include "Decoder.h"
#include "Exceptions/DecodeException.h"


std::vector<std::string> Decoder::readline(const std::string & file)
{

    std::vector<std::string> tokens;

    std::size_t begin = 0;
    std::size_t end = file.find(" ");

    if ( end != std::string::npos)
        tokens.push_back(file.substr(begin,end - begin));

    while( end != std::string::npos ){
        begin = end + 1;
        end = file.find(",",begin);
        tokens.push_back(file.substr(begin,end - begin));
    }

    return tokens;
}

bool Decoder::add_variable(const std::vector<std::string> & params)
{
    if ( params[2] == "NUMERIC" ) {
        if ( params.size() != 3 )
            return false;
        // add int
        return true;
    } else if ( params[2] == "REAL" ) {
        if ( params.size() != 3 )
            return false;
        // float
        return true;
    } else if (params[2] == "CHAR" ) {
        if ( params.size() != 3 )
            return false;
        // add char
        return true;
    } else if ( params[2] == "STRING" ) {
        if ( params.size() != 3 && params.size() != 4 )
            return false;
        // add string
        return true;
    } else return false;
}

void Decoder::decode()
{
    std::string line;
    std::vector<std::string> tokens;

    while (getline (file_in, line) ){
        tokens = readline(line);

        if ( tokens[0] == "VAR" )
            add_variable(tokens);
        else if ( tokens[0] == "ADD" )
            std::cout << "ADD command found" << std::endl;
        else if ( tokens[0] == "SUB" )
            std::cout << "SUB command found" << std::endl;
        else if ( tokens[0] == "MUL" )
            std::cout << "MUL command found" << std::endl;
        else if ( tokens[0] == "DIV" )
            std::cout << "DIV command found" << std::endl;
        else if ( tokens[0] == "ASSIGN" )
            std::cout << "ASSIGN command found" << std::endl;
        else if (tokens[0] == "OUT" )
            std::cout << "OUT command found" << std::endl;
        else
            throw InstructionException(tokens[0]);

        for( int i = 0; i < tokens.size() ; i++)
            std::cout << tokens[i] << std::endl;

        std::cout << std::endl;

        tokens.clear();
    }

}
