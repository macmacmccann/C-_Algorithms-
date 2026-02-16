
#include "Delete.h"
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




Node* BinaryTree::findMin(Node* node)
{
    while (node->left != nullptr)  // Keep going left
        node = node->left;

    return node; // Smallest value found
}



void BinaryTree::remove(int value)
{
    root = remove(root, value); // Start deletion from root
}


Node* BinaryTree::remove(Node* node, int value)
{
    // Base case: value not found
    if (node == nullptr)
        return nullptr;

    // If value is smaller, search left subtree
    if (value < node->data)
        node->left = remove(node->left, value);

    // If value is larger, search right subtree
    else if (value > node->data)
        node->right = remove(node->right, value);

    // Node found
    else
    {
        // Case 1: No children
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;        // Free memory
            return nullptr;     // Parent now points to null
        }

        // Case 2: One child (right only)
        else if (node->left == nullptr)
        {
            Node* temp = node->right; // Store child
            delete node;              // Delete current
            return temp;              // Replace node with child
        }

        // Case 2: One child (left only)
        else if (node->right == nullptr)
        {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        // Case 3: Two children
        else
        {
            // Find inorder successor (smallest in right subtree)
            Node* successor = findMin(node->right);

            // Copy successor value to current node
            node->data = successor->data;

            // Delete successor node from right subtree
            node->right = remove(node->right, successor->data);
        }
    }

    return node; // Return updated node pointer
}