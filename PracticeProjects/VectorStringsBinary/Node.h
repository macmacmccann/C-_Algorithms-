

#include <string>

using std::string;

class Node {

public:

	string data;
	Node* left;
	Node* right;

	// without explciit it turns cstring to Node type in node.cpp
//	Node(char value) : data(value) {}  // Converting constructor
	explicit Node(string value);


};