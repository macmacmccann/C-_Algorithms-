#pragma once


#include "Node.h"

class Tree {


	Node* root;



private:


	// privates return value to the helper mostly except for inorder 
	Node* insert(Node* currentNode, int value);


	void inOrderTraversal(Node* node);  

	bool searchNode(Node* currentNode, int valueToLookFor);

	Node* removeNode(Node* currentNode, int valueToLookFor);

	Node* findMin(Node* currentNode);


public:

	Tree(); // construcotr public used in main 


	void insertHelper(int value);

	void inOrderHelper();

	bool SearchHelper(int value);

	void removeNodeHelper(int value);





};