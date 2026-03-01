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

	void destroy(Node* root);

	// & by ref - dont copy the entire vector 
	// const as it reads from the array when constructing this method only creates
	static Node* buildFromArrayRecurring(const vector<string>& array,int start,int end);

public :

	Tree();
	~Tree();
//	doo pree post and inorder 


	// PUBLICS ARE VOID { ROOT = }
	void insertHelper(string value); // VOID 
	void inOrderHelper();
	Node* searchHelper(string value); // THIS NOT 
	void deleteNodeHelper(string value); // VOID - root = 

	void buildFromArrayRecurringHelper(const vector<string>& array);

	
	


};