

#include "Tree.h";

using namespace std;
#include <iostream>

Tree::Tree() {
	root = nullptr; // Start at the top root 
}


void Tree::insertHelper(int value) {

	root = insert(root, value);


}

Node* Tree::insert(Node* node, int value) 
	{

		// Base case em

		if (node == nullptr) {
			return new Node(value);
		}

		// If value is smaller than node ur at go left - coz left always contains lower value 
		if (value < node->data) {

			node->left = insert(node->left, value);

		}
		// If value is larger then go right 
		if (value > node->data) {

			node->right = insert(node->right, value);

		}

		return node; //  all paths must return a value 


	} 


	bool Tree::searchNodeHelper(int value) {

		return searchNode(root, value); // Just return the real function - start at root


	}

	// 2 base cases - if node null false , if value == node : true 
	bool Tree::searchNode(Node* node, int value) {


		// if node is null value not found 
		 if(node == nullptr){
			 return false;
		}

		 // If value is found return true 
		 if (value == node->data) {
			 return true;
		 }

		 // Then typical reursion 
		 // Search left or right recursively depending on the value 
		 if (value < node->data) {
			 return searchNode(node->left, value);
		 }
		 if (value > node->data) {
			 return searchNode(node->right, value);
		 }

	}


	void Tree::inOrderHelper() {
		inOrderTraversal(root); // Start at the root 
	}

	// whats the param ? is it in main inorder(5) then Node* node 
	void Tree::inOrderTraversal(Node* node) {
		// base case 
		if (node == nullptr) {
			return;
		}
		inOrderTraversal(node->left);
		cout << node->data << "\n";
		inOrderTraversal(node->right);
	}

	Node* Tree::findMin(Node* node) {

		while (node->left != nullptr) {
			node = node->left;
		}
		return node;

	}


	void Tree::deleteNodeHelper(int value) {
		root = deleteNode(root,value);
}

	Node* Tree::deleteNode(Node* node, int value) {

		if (node == nullptr) {
			return nullptr;
		}
		
		if (value < node->data) {
			node->left = deleteNode(node->left, value);
		}
		else if (value > node->data) {
			node->right = deleteNode(node->right, value);
		} 
		else {
			// Case 1 no children
			if (node->left == nullptr && node->right == nullptr) {
				delete node;
				return nullptr;
			}

			// Case 2 : 1 child (right) 
			else if (node->left == nullptr) {

				Node* temp = node->right;
				delete node;
				return temp;

			}

			// Case 2 b 1 child (left)
			else if (node->right == nullptr) {

				Node* temp = node->left;
				delete node;
				return temp;

			}
			// case 3 two children 
			else {

				Node* successor = findMin(node->right); // Smallest value in right tree -> thatll be deleted 
				node->data = successor->data; // Success copied the found node 

				// Now iv copied the succsor -> go find it again and delete it 
										// (go right again , find this guy)
				// to note: it WILL call case 1 or 2 as its a min value (so wont go back to this code) 
				node->right = deleteNode(node->right, successor->data);


			}
		}
			return node;

	}