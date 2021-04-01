#ifndef TRANSLATE_H
#define TRANSLATE_H

#include<iostream>

class Translate {

private:


public:
    Translate();
    virtual ~Translate();
    void parse(std::string input);
    void toEnglish(std::string word);

};

#endif // TRANSLATE_H
