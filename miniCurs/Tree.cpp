#include "Tree.h"


void Tree::InsertNode(User* user)
{
	User* element{user};
	if (!root) {
		root = new UserNode();
		root->user = element;
	}
	else {
		UserNode* node = root;
		while (node) {
			if (node->user->GetNick() == user->GetNick()) {
				cout << "ERROR" << endl;
				return;
			}
			else {
				if (user->GetNick() < node->user->GetNick()) {
					if (node->left)
						node = node->left;
					else {
						node->left = new UserNode();
						node->left->user = element;
						node = nullptr;
					}
				}
				else if (user->GetNick() > node->user->GetNick()) {
					if (node->right)
						node = node->right;
					else {
						node->right = new UserNode();
						node->right->user = element;
						node = nullptr;
					}
				}
			}
		}
	}
	
}

void Tree::ShowTree()
{
	if (root) {
		root->user->ShowUser();
	}
	if (root->left) {
		root = root->left;
		root->user->ShowUser();
	}
	if (root->right) {
		root = root->right;
		root->user->ShowUser();
	}
}
