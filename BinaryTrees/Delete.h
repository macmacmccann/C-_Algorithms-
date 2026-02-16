#pragma once



struct Node
{
    int data;            // Value stored in the node
    Node* left;          // Pointer to left child
    Node* right;         // Pointer to right child

    Node(int value);     // Constructor
};

class BinaryTree
{
private:
    Node* root;          // Root of the tree

    // Recursive helpers
    // ecapsulated
    // real logic 
    Node* insert(Node* node, int value);
    bool search(Node* node, int value);
    void inOrderTraversal(Node* node);
    void remove(Node* node, int value);
    Node* findMin(Node* node);


public: // Used in main 
    // All params just the value thats passed in into the real or helper function 
    //

    BinaryTree();        // Constructor

    void insert(int value);   // Public insert
    bool search(int value);   // Public search
    void inorder();           // Print inorder traversal
    void remove(int value);   // Public remove

};

