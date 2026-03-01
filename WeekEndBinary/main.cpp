// WeekEndBinary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#include "Tree.h"

#include <vector>
int main()
{
	Tree tree;
	tree.insertHelper(30);
	tree.insertHelper(70);
	tree.insertHelper(50);
	tree.insertHelper(40);
	tree.insertHelper(20);
	tree.insertHelper(10);


	cout << "Orginial tree\n";

	tree.inOrderHelper();


	tree.deleteNodeHelper(70);

	cout << "Delete 70 \n";

	tree.inOrderHelper();

	tree.searchNodeHelper(10);



}

