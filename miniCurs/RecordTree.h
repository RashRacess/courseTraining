#pragma once
#include "Record.h"
struct RecordNode {
	Record* rec;
	RecordNode* left;
	RecordNode* right;
};

class RecordTree {
private:
	RecordNode* root;
public:
	RecordTree() :root{ nullptr } {}

	void AddRec(Record* rec);
	void DeleteTree();
	bool SearchRec(Record* rec);
	void ShowTree();


};

