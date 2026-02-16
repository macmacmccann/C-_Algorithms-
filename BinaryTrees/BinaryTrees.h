#pragma once

int add(int a, int b);
double avg(double a, double b);




// Class 
struct Node
{
    int data;
    Node* left;
    Node* right;

    //Constructor only the data 
    Node(int value);

};

//
class BinaryTree {
private:  // private always in header 
    Node* root;
    void inOrderTraversal(Node* node); // helper method in order
 

public: // public functions to actually use 
    BinaryTree(); // Constructor 
    void createSimpleTree(); // Function to manually ceate a simple tree


    void inorder(); //Public function to start the order 



};