#include "Morse.h"
#include "Translate.h"

#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

/** USER ENTERS STRING, STRING IS PARSED AND SENT TO BE EVALUATED **/

int main(int argc, char *argv[]){

    string input;

    cout << "Enter valid Morse code: ";
    getline(cin, input);

    Translate o;
    o.parse(input);

    return 0;
}
