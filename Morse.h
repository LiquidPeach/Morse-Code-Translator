#pragma once

#include<array>

struct Node {

    char data;
    Node *left, *right;

    Node()
        : data('\0'), left(nullptr), right(nullptr)
    {
    }

    Node(char input)
        : data(input), left(nullptr), right(nullptr)
    {
    }
};

class Morse {

private:

    static const int SIZE = 28; //28 nodes in the template Morse tree
    std::array<Node*, SIZE> letters;

    //PRIVATE FUNCTION PROTOTYPES
    Node* searchTreePrivate(const std::string& word, Node *leaf, std::string::size_type index);
    void deleteNodesPrivate(Node *leaf);

public:
    Morse();
    virtual ~Morse();

    //PUBLIC FUNCTION PROTOTYPES
    void initTree(void);
    int set_left(char letter, int parent);
    int set_right(char letter, int parent);
    void searchTree(const std::string& word);
    void deleteNodes();
};
