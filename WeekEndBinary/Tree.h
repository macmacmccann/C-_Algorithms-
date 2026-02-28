
#pragma once



#include "Node.h";


class Tree {

private:

	Node* root;

	// Real recursive methods - take presentnode and int value if you pass anything fro the public one 
	

	// method adds in main eg., (5) -> then it returns anode 
	// if the method traverses then you need node + value in params 
	Node* insert(Node* thePresentNode,int value);
	Node* deleteNode(Node* thePresentNode, int value);
	bool searchNode(Node* thePresentNode, int value); // search is bool for both 
	void inOrderTraversal(Node* thePresentNode); // No int value - as you dont insert anything in main / any object of such 
	
	Node* findMin(Node* thePresentNode);


public:
	Tree(); // root = nullptr simple construct private 

	// helper method return value is void 
	void insertHelper(int value);
	void deleteNodeHelper(int value);
	bool searchNodeHelper(int value);
	void inOrderHelper();


};