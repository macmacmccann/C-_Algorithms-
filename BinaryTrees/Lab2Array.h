


#pragma once

#include <vector>


using namespace std;

// Class 
class Node
{
public:
    char data;
    Node* left;
    Node* right;

    //Constructor only the data 
    //Node(int value);
    // explciit prevents conversions 
    // eg., char to node 
    explicit Node(char value);
};





class BinaryTree {
private:  // private always in header 
    Node* root;
    void inOrderTraversal(Node* node); // helper method in order
    static void destroy(Node* node);
    bool search(Node* node, char value);
    static void display(Node* node, int depth);

    static Node* buildFromArrayRec(const vector<char>& arr, int start, int end);


public: // public functions to actually use 
    BinaryTree();
    ~BinaryTree();
    bool search(char value);

    void inorder();
    void buildFromArray(const vector<char>& arr);
    void display();




};