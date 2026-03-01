#pragma once


#include "Node.h";

class Tree {


private:

	Node* root;


	Node* insert(Node* currentNode, string value);
	void inOrderTraversal(Node* currentNode);
	Node* search(Node* currentNode, string value);
	Node* deleteNode(Node* currentNode, string value); 

	Node* findMin(Node* currentNode);


public :

	Tree();
	~Tree();
//	doo pree post and inorder 


	// PUBLICS ARE VOID { ROOT = }
	void insertHelper(string value); // VOID 
	void inOrderHelper();
	Node* searchHelper(string value); // THIS NOT 
	void deleteNodeHelper(string value); // VOID - root = 



	
	


};