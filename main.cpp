#include "Decoder.h"

using namespace std;

int main(){
    
    Decoder dec("hello.txt");

    try 
    {
        dec.decode();
    } 
    catch (InstructionException ie) {
        ie.printException();
    }


    return 0;
}
