#include "RecordTree.h"

void RecordTree::AddRec(Record *rec)
{
	Record* element{ rec };
	if (root == nullptr) {
		root = new RecordNode();
		root->rec = element;
		root->left = nullptr;
		root->right = nullptr;
	}
	else
	{
		RecordNode* node = root;
		while (node)
		{
			if (node->rec == rec) //по имение компании
			{
				cout << "ERROR" << endl;
				return;
			}
			else
			{
				if (rec < node->rec) //по имение компании
				{
					if (node->left)
						node = node->left;
					else
					{
						root->left = new RecordNode();
						root->left->rec = element;
						node = nullptr;
					}
				}

				else if (rec > node->rec) //по имение компании
				{
					if (node->right)
						node = node->right;
					else
					{
						node->right = new RecordNode();
						node->right->rec = element;
						node = nullptr;
					}
				}
			}
		}
	}
}

void RecordTree::DeleteTree() {}

bool RecordTree::SearchRec(Record* rec)
{
	if (root) {
		if (root->rec->GetAgent() == rec->GetAgent())
			return true;
		if (root->left) {
			root = root->left;
			SearchRec(rec);
		}
		if (root->right) {
			root = root->right;
			SearchRec(rec);
		}
	}
}

void RecordTree::ShowTree()
{
	if (root) {
		root->rec->ShowRec();
	}
	if (root->left) {
		root = root->left;
		ShowTree();
	}
	if (root->right) {
		root = root->right;
		ShowTree();
	}
}
