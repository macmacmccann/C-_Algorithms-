#pragma once


#include "Tree.h";
#include <iostream>;

using namespace std;

Tree::Tree() {

	root = nullptr;

}

void Tree::insertHelper(int value) {

	// start the real method from the root with the value put in 
	root = insert(root, value);

}

Node* Tree::insert(Node* currentNode, int value) {

	// Base case 
	if (currentNode == nullptr) {
		return currentNode; // NO return new Node(value) in insertion 
		// if your at the bottom of the insert good just insert with value 

	}

	// rescursive in order 

	if (value < currentNode->data) {
		currentNode->left = insert(currentNode->left, value);
	}
	if (value > currentNode->data) {
		currentNode->right = insert(currentNode->right, value);
	}
	
	return currentNode; // all paths must return a value
}

void Tree::inOrderHelper() {

	inOrderTraversal(root); // start from root dont let the person do it just let them call 
}


void Tree::inOrderTraversal(Node* currentNode) {

	if (currentNode == nullptr) {
		return;
	}

	inOrderTraversal(currentNode->left);
	cout << currentNode->data;
	inOrderTraversal(currentNode->right);
}


bool Tree::SearchHelper(int value) {
	
	return searchNode(root, value);
}


bool Tree::searchNode(Node* currentNode, int value) {

	// Base case if we got to null ptr then not found

	if (currentNode == nullptr) {
		return false;
	}

	if (value < currentNode->data) {
		return searchNode(currentNode->left, value); // JUST RETURN  NO EQULA FOR SEARCH
	}
	if (value > currentNode->data) {
	    return searchNode(currentNode->right, value);
	}

	return currentNode;

}

Node* Tree::findMin(Node* node) { //XXXX


	while (node->left != nullptr) {
		node = node->left;
	}
	return node; // NO its inside the forloop 

}

void Tree::removeNodeHelper(int value) { // XXX does the helper need the same return type or just call the method 


	root = removeNode(root,value);  // MISSING ROOT = 

}

Node* Tree::removeNode(Node* currentNode, int value) {


	if (currentNode == nullptr) {
		return nullptr; // BE CAFEFUL REUTRN NULLPTR 
	}
	else if (value < currentNode->data) {
		currentNode->left = removeNode(currentNode->left, value);
	}
	else if (value > currentNode->data) {
		currentNode->right = removeNode(currentNode->right, value);
	}

	else { // Second main else block 

		// if no children case 1 
		if (currentNode->left == nullptr && currentNode->right == nullptr) {
			delete currentNode;
			return nullptr;

		}
		// if right is empty 
		else if (currentNode->right == nullptr) {
			Node* temp = currentNode->left;
			delete currentNode;
			return temp;

		}
		else if (currentNode->left == nullptr) {
			Node* temp = currentNode->right;
			delete currentNode;
			return temp;
		}

		// if two children do not = null 
	
		if (currentNode->left != nullptr && currentNode->right != nullptr) {

			Node* successor = findMin(currentNode->right); // Just find min of right branch 
			currentNode->data = successor->data; // Copy data 
											// ( start at current node right not root , find this number ) 
			currentNode->right = removeNode(currentNode->right, successor->data); 
		}

		return currentNode;

	}
}


