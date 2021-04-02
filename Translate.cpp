#include "Translate.h"
#include "Morse.h"

#include<iostream>

void Translate::parse(const std::string& input){

    std::string token = "";

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

void Translate::toEnglish(const std::string& word){
    if(word.length() > 4){
        std::cout << "Invalid entry\n";
        return;
    }

    Morse code;
    code.searchTree(word);
}
