#include "func.h"
#include "User.h"
#include "Tree.h"
#include "Record.h"
#include "RecordTree.h"

int main() {
	system("chcp 65001");
	cout << "Users:" << endl;
	User dima("dima", "12345", "admin");
	Tree derevo;
	derevo.InsertNode(&dima);
	derevo.ShowTree();

	cout << endl << endl << endl;
	
	cout << "Records:" << endl;
	RecordTree recTree;
	Record rec("microsoft", "bill", "112", "newYork", 3);
	recTree.AddRec(&rec);
	Record rec2("apple", "timmy", "911", "california", 7);
	recTree.AddRec(&rec2);
	recTree.ShowTree();

	return 0;
}