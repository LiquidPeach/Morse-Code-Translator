#include "Translate.h"
#include "Morse.h"

#include<iostream>
#include<string>
#include<sstream>

using std::string;
using std::stringstream;

Translate::Translate(){}

Translate::~Translate(){}

void Translate::parse(string input){

    string token = "";

    for(auto x : input){
        if(x == ' '){
            toEnglish(token);
            token = "";
        }
        else{
            token = token + x;
        }
    }
    toEnglish(token);
}

void Translate::toEnglish(string word){
    if(word.length() > 4){
        std::cout << "Invalid entry\n";
        return;
    }

    Morse *code = new Morse();
    code->searchTree(word);

    delete code;
}
