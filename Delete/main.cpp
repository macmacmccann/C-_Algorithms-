#include <iostream>
#include "Tree.h"

int main() {
    Tree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    std::cout << "Original tree: ";
    tree.inorder();

    std::cout << "Delete 20 (no children): ";
    tree.remove(20);
    tree.inorder();

    std::cout << "Delete 30 (one child): ";
    tree.remove(30);
    tree.inorder();

    std::cout << "Delete 50 (two children): ";
    tree.remove(50);
    tree.inorder();

    return 0;
}
