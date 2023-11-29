#pragma once
#include <iostream>
#include <fstream>
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

	void InsertNode(Node* root, T& value);

	void ShowTree(Node* root);

	void DeleteTree(Node* root);

	T* SearchInTree(Node* root, T& value);

	void RecordTreeFile(Node* root, fstream &file);

	void SearchStringInTree(Node* root, string str);

	void DeleteTreeNode(Node* root, T& node);

public:
	Tree() : root{ nullptr } {}

	void Insert(T& node) {
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

	T* Search(T& node) {
		return SearchInTree(root, node);
	}

	void RecordTreeToFile(fstream &file, string name) {
		file.open(name, std::ios::out);
		if (!file.is_open()) return;
		RecordTreeFile(root, file);
		file.close();
	}

	void TreeSearchString(string str) {
		SearchStringInTree(root, str);
	}
};

template <typename T>
void Tree<T>::InsertNode(Node* root, T& value) {
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
T* Tree<T>::SearchInTree(Node* root, T& node) {
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
	return nullptr;
}

template<typename T>
void Tree<T>::RecordTreeFile(Node* root, fstream &file) {
 	if (!root) {
		return;
	}
	else {
		RecordTreeFile(root->left, file);
		file << root->data << endl;
		RecordTreeFile(root->right, file);
	}
}

template<typename T>
void Tree<T>::SearchStringInTree(Node* root, string str) {
	if (!root) {
		return;
	}
	else {
		if (root->data == str) {
			cout << &root->data << endl;
		}

		else if (root->data > str) {
			SearchStringInTree(root->left, str);
		}

		else if (root->data < str) {
			SearchStringInTree(root->right, str);
		}
	}
	return;
}

template<typename T>
void Tree<T>::DeleteTreeNode(Node* root, T& node) {
	if (root == nullptr) {
		return;
	}
	else {
		if (root->data > node) {
			DeleteTreeNode(root->left, node);
		}
		else if (root->data < node) {
			DeleteTreeNode(root->right, node);
		}
		else {
			if (root->left == nullptr and root->right == nullptr) {
				root = nullptr;
			}
			
		}
	}
}