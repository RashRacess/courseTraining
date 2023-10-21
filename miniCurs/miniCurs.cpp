#include "func.h"

int main() {
	ifstream file;
	//User user{ "dima", "12345", "pole" };
	//User user2{ "dina", "3246", "admin" };
	//User user3{ "dasha", "4y3374", "pole" };
	//bst2.Insert(user);
	//bst2.Insert(user2);
	//bst2.Insert(user3);

	Record rec("microsoft", "bill", "112", "newYork", 3);
	//Record rec2("apple", "timmy", "911", "california", 7);

	cout << "Records: " <<  endl;
	Tree<Record>bst;
	CreateRecordTree(bst, file, "Records.txt");
	HumanRecordInference();
	bst.Show();
	bst.Delete();

	cout << endl << endl;

	cout << "Users: " << endl;
	Tree<User>bst2;
	CreateUserTree(bst2, file, "Users.txt");
	HumanUserInference();
	bst2.Show();

}
