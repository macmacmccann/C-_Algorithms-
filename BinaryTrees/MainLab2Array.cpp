
#include <iostream>
#include <vector>

#include "Lab2Array.h"


using namespace std;

int main()

{

	BinaryTree tree;

	vector<char> arr = { 'A','B','C','D','E','F','G','H','I','J','K','L' };
	tree.buildFromArray(arr);


	cout << "In order traversal";
	tree.inorder();

	tree.display();

	cout << "Searching E" << endl;
	cout << (tree.search('E') ? "Found" : "Not Found") << endl;

	cout << "Searching z " << endl;
	cout << (tree.search('z') ? "Found" : "Not Found") << endl;

	return 0;

}