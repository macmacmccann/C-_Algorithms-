
#include "Tree.h"

using namespace std;
#include <iostream>
#include <vector>


Tree::Tree() {

	root = nullptr;
}


Tree::~Tree() {
	destroy(root);
}

void Tree::destroy(Node* node) {

	if (!node) return;

	destroy(node->left);
	destroy(node->right);
	delete node;
}

void Tree::buildFromArrayRecurringHelper(const vector<string>& array) {

									// array , start, end 
	root = buildFromArrayRecurring(array, 0, array.size() - 1);

}
	

Node* Tree::buildFromArrayRecurring(const vector<string>& array , int start, int end) {

	if (start > end)
		return nullptr;

	int mid = (start + end) / 2;

	Node* node = new Node(array[mid]);

	// Build left subtree - array start to mid
	node->left = buildFromArrayRecurring(array, start, mid - 1);

	// Build right subtree - array mid to end 
	node->right = buildFromArrayRecurring(array, mid + 1, end);

	return node; // Return node to helper function as root 

}

/*

	Array: ["A", "B", "C", "D", "E"]
			 0    1    2    3    4

	Tree :
		C		? array[2]
	   / \
	  B   D		? array[1], array[3]
     /     \
	A       E	? array[0], array[4]

*/

void Tree::inOrderHelper() {

	inOrderTraversal(root);

}

void Tree::inOrderTraversal(Node* currentNode) {

	if (currentNode == nullptr) {
		return;
	}

	inOrderTraversal(currentNode->left);
	cout << currentNode->data;
	inOrderTraversal(currentNode->right);
}

void Tree::insertHelper(string value) {

	root = insert(root, value);
}

Node* Tree::insert(Node* currentNode, string value) {

	if (currentNode == nullptr) {
		return new Node(value);
	}

	if (value < currentNode->data) {
		currentNode->left = insert(currentNode->left, value);
	}
	if (value > currentNode->data) {
		currentNode->right = insert(currentNode->right, value);
	}
	return currentNode;
}


Node* Tree::searchHelper(string value) {

	Node* foundNode = new Node(nullptr);
	foundNode = search(root, value);

	if (foundNode == nullptr) {
		cout << "Node not found";
	}
	cout << "Node found" << foundNode->data;
	return foundNode; // just return it but didnt do anything did logic here 

		//old version
	//return search(root, value);

}

Node* Tree::search(Node* currentNode, string value) {

	if (currentNode == nullptr) {
		return nullptr;
	}

	if (currentNode->data == value) {
		return currentNode; // ??
	}

	if (value < currentNode->data) {
		return insert(currentNode->left, value);

	}
	if (value > currentNode->data) {
		return insert(currentNode->right, value);
	}
	// No return !!

}

Node* Tree::findMin(Node* currentNode) {

	while (currentNode->left != nullptr) {
		currentNode = currentNode->left;
		return currentNode;
	}
}

void Tree::deleteNodeHelper(string value) { // VOID 

	root = deleteNode(root, value); // ROOT = 
}

Node* Tree::deleteNode(Node* currentNode, string value) {

	if (currentNode == nullptr) {
		return nullptr;

	}

	// Recursion type A (like insert)

	if (value < currentNode->data) {
		currentNode->left = deleteNode(currentNode->left, value);
	}
	else if (value > currentNode->data) {
		currentNode->right = deleteNode(currentNode->right, value);
	}
	else {

		// Case 1 no children
		if (currentNode->left == nullptr && currentNode->right == nullptr) {
			delete currentNode;
			return nullptr;
		}
		
		// Case 2 a
		if (currentNode->left == nullptr) {
			Node* temp = currentNode->right;
			delete currentNode; // just delete the node nothing fancy 
			return temp; // and then reutrn temp 
		}

		if (currentNode->right == nullptr) {
			Node* temp = currentNode->left;
			delete currentNode;
			return temp;
		}
		if (currentNode->left != nullptr && currentNode->right != nullptr) {

			Node* successor = findMin(currentNode->right); // Go right and find the min
			currentNode->data = successor->data; // Put the succsors value in this node 
			currentNode->right = deleteNode(currentNode->right, successor->data); // find the successor and delete will be case 2 a or 2 b 

		}
		return currentNode;
	}




}