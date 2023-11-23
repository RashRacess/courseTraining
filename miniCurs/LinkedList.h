#pragma once
#include <iostream>
using namespace std;

template<typename T>
class LinkedList {
private:
	struct Node {
		T data;
		Node* next;

		Node(const T& value) : data{ value }, next{ nullptr } {}
	};

	Node* root;

	void AddNode(Node* root, const T& node);

	void ShowList(Node* root);

	bool SearchNode(Node* root, const T& node);

	void DeleteList(Node* root);

public:
	LinkedList() : root{ nullptr } {}

	void Add(const T& value) {
		if (root == nullptr) {
			root = new Node(value);
		}
		else {
			AddNode(root, value);
		}
	}

	void Show() {
		ShowList(root);
	}

	bool Search(const T& value) {
		return SearchNode(root, value);
	}

	void Delete() {
		DeleteList(root);
	}
};

template<typename T>
void LinkedList<T>::AddNode(Node* root, const T& node) {
	while (root) {
		if (root->next == nullptr) {
			root->next = new Node(node);
			return;
		}
		else {
			root = root->next;
		}
	}
}

template<typename T>
void LinkedList<T>::ShowList(Node* root) {
	while (root) {
		cout << root->data << "->";
		root = root->next;
	}
}

template<typename T>
bool LinkedList<T>::SearchNode(Node* root, const T& node) {
	while (root) {
		if (root->data == node) {
			return true;
		}
		root = root->next;
	}
	return false;
}

template<typename T>
void LinkedList<T>::DeleteList(Node* root)
{
	Node* head = root;
	while (root) {
		root = root->next;
		delete head;
		head = root; 
	}
}


