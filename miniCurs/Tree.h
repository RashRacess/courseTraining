#pragma once
#include "User.h"

struct UserNode {
	User* user;
	UserNode* left;
	UserNode* right;
};

class Tree {
private:
	UserNode* root;
public:
	Tree() : root{ nullptr } {}

	bool SearchUser(User* user);
	void InsertNode(User* user);
	void ShowTree();

};