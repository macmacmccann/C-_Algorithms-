

#include <iostream>
using namespace std;
#include "BinaryTrees.h"



int main()
{

    cout << "added " << add(2, 3) << "\n";
    cout << "averaged " << avg(2, 4) << "\n";

    BinaryTree tree;

    tree.createSimpleTree();

    cout << "In Order Transerval starts :  ";
    tree.inorder(); 

    return 0;

}

