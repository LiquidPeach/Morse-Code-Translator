#ifndef MORSE_H
#define MORSE_H

#include<iostream>
using std::string;

struct Node {

    char data;
    Node *left, *right;

    Node(Node *l=nullptr, Node *r=nullptr){
        data = '\0';
        left = l;
        right = r;
    }

    Node(char input, Node *l=nullptr, Node *r=nullptr){
        data = input;
        left = l;
        right = r;
    }
};

class Morse {

private:

    static const int SIZE = 28; //28 nodes in the template Morse tree

    Node *letters[SIZE];

    //PRIVATE FUNCTION PROTOTYPES
    Node* searchTreePrivate(std::string word, Node *leaf, std::string::size_type index);
    void deleteNodesPrivate(Node *leaf);

public:
    Morse();
    virtual ~Morse();

    //PUBLIC FUNCTION PROTOTYPES
    void initTree(void);
    int set_left(char letter, int parent);
    int set_right(char letter, int parent);
    void searchTree(std::string word);
    void deleteNodes();
};

#endif // MORSE_H
