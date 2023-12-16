#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template<typename T>
class Node {
public:
	T data;
	Node<T>* left;
	Node<T>* right;

	Node(const T& value) : data{ value }, left{ nullptr }, right{ nullptr } {}
};

template <typename T>
class Tree {
private:

	void InsertNode(Node<T>*& root, const T value);

	void ShowTree(Node<T>* root);

	void DeleteTree(Node<T>* root);

	T* SearchInTree(Node<T>* root, const T value);

	void RecordTreeFile(Node<T>* root, fstream& file);

	Node<T>* removeNode(Node<T>* node, const T value) {
		if (node == nullptr) {
			return nullptr;
		}

		if (value < node->data) {
			node->left = removeNode(node->left, value);
		}
		else if (value > node->data) {
			node->right = removeNode(node->right, value);
		}
		else {
			if (node->left == nullptr) {
				Node<T>* temp = node->right;
				delete node;
				return temp;
			}
			else if (node->right == nullptr) {
				Node<T>* temp = node->left;
				delete node;
				return temp;
			}

			Node<T>* temp = findMin(node->right);
			node->data = temp->data;
			node->right = removeNode(node->right, temp->data);
		}

		return node;
	}

	Node<T>* findMin(Node<T>* node) {
		while (node->left != nullptr) {
			node = node->left;
		}
		return node;
	}

	Node<T>* root;
	int size;
public:

	Tree() : root{ nullptr }, size{ 0 } {}

	Node<T>* GetRoot() {
		return root;
	}

	void Insert(const T node) {
		if (root == nullptr){
			root = new Node<T>(node);
			size++;
		}
		else {
			InsertNode(root, node);
		}
	}

	void Show() {
		ShowTree(root);
	}

	void Delete() {
		size = 0;
		DeleteTree(root);
	}

	T* Search(const T node) {
		return SearchInTree(root, node);
	}

	void RecordTreeToFile(fstream& file, string name) {
		file.open(name, std::ios::out);
		if (!file.is_open()) return;
		RecordTreeFile(root, file);
		file.close();
	}

	void DeleteNode(const T node) {
		size--;
		removeNode(root, node);
	}

	int GetSize() {
		return size;
	}
};

template <typename T>
void Tree<T>::InsertNode(Node<T>*& root, const T value) {
	if (value < root->data) {
		if (root->left == nullptr) {
			root->left = new Node<T>(value);
			size++;
		}
		else {
			InsertNode(root->left, value);
		}
	}
	else if (value > root->data) {
		if (root->right == nullptr){
			root->right = new Node<T>(value);
			size++;
		}
		else {
			InsertNode(root->right, value);
		}
	}
}

template<typename T>
void Tree<T>::ShowTree(Node<T>* root) {
	if (root != nullptr) {
		ShowTree(root->left);
		cout << root->data << endl;
		ShowTree(root->right);
	}
}

template<typename T>
void Tree<T>::DeleteTree(Node<T>* root) {
	if (root) {
		DeleteTree(root->left);
		DeleteTree(root->right);
		delete root;
	}
}

template<typename T>
T* Tree<T>::SearchInTree(Node<T>* root, const T node) {
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
void Tree<T>::RecordTreeFile(Node<T>* root, fstream& file) {
	if (!root) {
		return;
	}
	else {
		RecordTreeFile(root->left, file);
		file << root->data << endl;
		RecordTreeFile(root->right, file);
	}
}