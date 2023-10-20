#include <iostream>
using namespace std;

template <typename T>
class Tree {
private:
	struct Node {
		T data;
		Node* left;
		Node* right;

		Node(const T& value) : data{ value }, left{ nullptr }, right{ nullptr } {}
	};

	Node* root;

	void InsertNode(Node*& root, const T& value);

	void ShowTree(Node* root);


public:
	Tree() : root{ nullptr } {}

	void Insert(const T& node) {
		InsertNode(root, node);
	}

	void Show() {
		ShowTree(root);
	}

};

template <typename T>
void Tree<T>::InsertNode(Node*& root, const T& value) {
	if (!root) {
		root = new Node(value);
	}

	else {
		if (value < root->data) {
			InsertNode(root->left, value);
		}
		if (value > root->data) {
			InsertNode(root->right, value);
		}
	}
}

template<typename T>
void Tree<T>::ShowTree(Node* root) {
	if (root != nullptr) {
		ShowTree(root->left);
		cout << root->data << endl;
		ShowTree(root->right);
	}
}