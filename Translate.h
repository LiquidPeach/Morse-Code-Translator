#pragma once

#include<string>

class Translate {

public:
    Translate() = default;
    virtual ~Translate() = default;
    void parse(const std::string& input);
    void toEnglish(const std::string& word);

};
