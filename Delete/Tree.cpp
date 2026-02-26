#include "Tree.h"
#include <iostream>

Tree::Tree() {
    root = nullptr;
}

void Tree::insert(int value) {
    root = insert(root, value);
}

Node* Tree::insert(Node* node, int value) {
    if (node == nullptr)
        return new Node(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);

    return node;
}

void Tree::remove(int value) {
    root = remove(root, value);
}

Node* Tree::remove(Node* node, int value) {
    if (node == nullptr)
        return nullptr;

    if (value < node->data)
        node->left = remove(node->left, value);
    else if (value > node->data)
        node->right = remove(node->right, value);
    else {
        // Case 1: No children
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        // Case 2: One child (right)
        else if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        // Case 2: One child (left)
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        // Case 3: Two children
        else {
            Node* successor = findMin(node->right);
            node->data = successor->data;
            node->right = remove(node->right, successor->data);
        }
    }
    return node;
}

Node* Tree::findMin(Node* node) {
    while (node->left != nullptr)
        node = node->left;
    return node;
}

void Tree::inorder() {
    inorder(root);
    std::cout << std::endl;
}

void Tree::inorder(Node* node) {
    if (node == nullptr)
        return;

    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}
