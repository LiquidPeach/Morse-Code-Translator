#include "Morse.h"

#include<iostream>

Morse::Morse(){

    for(int i=0; i<SIZE; i++){  //Create each node and store in array
        letters[i] = new Node();
    }
    initTree();                 //Initialize tree when constructor is called
}

Morse::~Morse(){
    deleteNodes();
    std::cout << "Nodes deleted, bye-bye\n";
}

Node* Morse::searchTreePrivate(const std::string& word, Node *leaf, std::string::size_type index){

    if(leaf != nullptr && index < word.length()){
        if(word[index] == '.'){
            return searchTreePrivate(word, leaf->left, ++index);
        }
        else if(word[index] == '-'){
            return searchTreePrivate(word, leaf->right, ++index);
        }
    }

    std::cout << leaf->data << '\n';
    return leaf;
}

void Morse::initTree(void){                 //Creating the Morse Tree

    for(int i='A'; i<='Z'; i++){            //Putting the alphabet from A-Z into array of nodes
        letters[(i-'A')+1]->data = char(i); //Add 1 since the first index (root node) must be empty,
                                            //according to the template Morse tree
    }

    /** Building the tree manually using the Morse Tree template as reference **/
    /** Level 1 of the tree is the empty node at the start of the tree **/

    set_left('E', 0);   //Level 2 of tree
    set_right('T', 0);

    set_left('I', 1);   //Level 3 of tree
    set_right('A', 1);
    set_left('N', 2);
    set_right('M', 2);

    set_left('S', 3);   //Level 4 of tree
    set_right('U', 3);
    set_left('R', 4);
    set_right('W', 4);
    set_left('D', 5);
    set_right('K', 5);
    set_left('G', 6);
    set_right('O', 6);

    set_left('H', 7);   //Level 5 of tree
    set_right('V', 7);
    set_left('F', 8);  //NOTE: U (index 8) only has one child
    set_left('L', 9);  //NOTE: R (index 9) only has one child
    set_left('P', 10);
    set_right('J', 10);
    set_left('B', 11);
    set_right('X', 11);
    set_left('C', 12);
    set_right('Y', 12);
    set_left('Z', 13);
    set_left('Q', 13);

}

int Morse::set_left(char letter, int parent){ //Sets the left pointer of a node

    if(letters[parent] != nullptr){    //If the element is valid

        letters[parent]->left = letters[(parent*2)+1];
        letters[(parent*2)+1]->data = letter;
    }

    return 0;
}

int Morse::set_right(char letter, int parent){ //Sets the right pointer of a node

    if(letters[parent] != nullptr){

        letters[parent]->right = letters[(parent*2)+2];
        letters[(parent*2)+2]->data = letter;
    }

    return 0;
}

void Morse::searchTree(const std::string& word){

    searchTreePrivate(word, letters[0], 0);
}

void Morse::deleteNodesPrivate(Node *leaf){
    if(leaf != nullptr){
        deleteNodesPrivate(leaf->left);
        deleteNodesPrivate(leaf->right);
        delete leaf;
    }
}

void Morse::deleteNodes(){
    deleteNodesPrivate(letters[0]);
}
