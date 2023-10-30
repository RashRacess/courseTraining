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

	void InsertNode(Node* root, const T& value);

	void ShowTree(Node* root);

	void DeleteTree(Node* root);

	T* SearchInTree(Node* root, const T& value);


public:
	Tree() : root{ nullptr } {}

	void Insert(const T& node) {
		if (root == nullptr)
			root = new Node(node);
		else {
			InsertNode(root, node);
		}
	}

	void Show() {
		ShowTree(root);
	}

	void Delete() {
		DeleteTree(root);
	}

	bool Search(const T& node) {
		return SearchInTree(root, node);
	}
};

template <typename T>
void Tree<T>::InsertNode(Node* root, const T& value) {
	if (value < root->data) {
		if (root->left == nullptr) {
			root->left = new Node(value);
		}
		else {
			InsertNode(root->left, value);
		}
	}
	else if (value > root->data) {
		if (root->right == nullptr)
			root->right = new Node(value);
		else {
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

template<typename T>
void Tree<T>::DeleteTree(Node* root) {
	if (root) {
		DeleteTree(root->left);
		DeleteTree(root->right);
		delete root;
	}
}

template<typename T>
T* Tree<T>::SearchInTree(Node* root, const T& node) {
	if (!root) {
		return nullptr;
	}
	else {
		if (root->data == node) {
			return &root->data;
		}

		if (node < root->data) {
			return SearchInTree(root->left, node);
		}

		else if (node > root->data) {
			return SearchInTree(root->right, node);
		}
	}
}