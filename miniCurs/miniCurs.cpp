#include "func.h"

int main() {
	//User user{"dima", "12345", "pole"};
	//User user2{"dina", "3246", "admin"};
	//User user3{"dasha", "4y3374", "pole"};

	//Record rec("microsoft", "bill", "112", "newYork", 3);
	//Record rec2("apple", "timmy", "911", "california", 7);

	cout << "Records: " <<  endl;
	Tree<Record>bst;
	Record newRec("google", "dima", "12345", "rechitskaya", 4);
	Record rec2("apple", "timmy", "911", "california", 7);
	bst.Insert(newRec);
	bst.Insert(rec2);
	bst.Show();

	cout << "Users: " << endl;
	Tree<User>bst2;
	User user{"dima", "12345", "pole"};
	User user2{"dina", "3246", "admin"};
	User user3{"dasha", "4y3374", "pole"};
	bst2.Insert(user);
	bst2.Insert(user2);
	bst2.Insert(user3);
	bst2.Show();
}
