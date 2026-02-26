#pragma once
#include "Node.h"

class Tree {
private:
    Node* root;
    Node* insert(Node* node, int value);
    Node* remove(Node* node, int value);
    Node* findMin(Node* node);
    void inorder(Node* node);

public:
    Tree();
    void insert(int value);
    void remove(int value);
    void inorder();
};
