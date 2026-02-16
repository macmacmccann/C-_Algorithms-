#include "BinaryTreeSearchInsert.h"
#include <iostream>

// Node constructor
Node::Node(int value)
{
    data = value;        // Store value
    left = nullptr;     // No children initially
    right = nullptr;
}


BinaryTree::BinaryTree()
{
    root = nullptr;     // Tree starts empty
}

// Public insert function
void BinaryTree::insert(int value)
{
    root = insert(root, value); // Start insertion from root
}

// Recursive insert helper
Node* BinaryTree::insert(Node* node, int value)
{
    // If we reach an empty spot, create a new node
    if (node == nullptr)
        return new Node(value);

    // If value is smaller, go left
    if (value < node->data)
        node->left = insert(node->left, value);

    // If value is larger, go right
    else if (value > node->data)
        node->right = insert(node->right, value);

    // Return unchanged node pointer
    return node;
}

// Public search function
bool BinaryTree::search(int value)
{
    return search(root, value); // Start search from root
}

// Recursive search helper
bool BinaryTree::search(Node* node, int value)
{
    // If node is null, value not found
    if (node == nullptr)
        return false;

    // If value matches, return true
    if (node->data == value)
        return true;

    // Search left or right depending on value
    if (value < node->data)
        return search(node->left, value);
    else
        return search(node->right, value);
}

// Public inorder traversal
void BinaryTree::inorder()
{
    inOrderTraversal(root); // Start traversal
    std::cout << std::endl;
}

// Recursive inorder helper
void BinaryTree::inOrderTraversal(Node* node)
{
    if (node == nullptr)
        return;

    inOrderTraversal(node->left);   // Visit left
    std::cout << node->data << " "; // Visit node
    inOrderTraversal(node->right);  // Visit right
}