#include "Morse.h"
#include "Translate.h"

#include<iostream>

/** USER ENTERS STRING, STRING IS PARSED AND SENT TO BE EVALUATED **/

int main(int argc, char *argv[]){

    std::string input;

    std::cout << "Enter valid Morse code: ";
    getline(std::cin, input);

    Translate o;
    o.parse(input);

    return 0;
}
