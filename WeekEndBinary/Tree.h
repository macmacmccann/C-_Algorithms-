
#pragma once



#include "Node.h";


class Tree {

private:

	Node* root;

	// Real recursive methods - take presentnode and int value if you pass anything fro the public one 
	

	// Private methods return value is Node*
	Node* insert(Node* thePresentNode,int value);
	void deleteNode(Node* thePresentNode, int value);
	void searchNode(Node* thePresentNode, int value);
	void inOrderTraversal(Node* thePresentNode); // No int value - as you dont insert anything in main / any object of such 
	
	void findMin(Node* thePresentNode);


public:
	Tree(); // root = nullptr simple construct private 

	// helper method return value is void 
	void insertHelper(int value);
	void deleteNodeHelper(int value);
	void searchNodeHelper(int value);
	void inOrderHelper();













};