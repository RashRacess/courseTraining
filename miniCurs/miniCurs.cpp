#include "func.h"
#include "Authorization.h"

int main() {
	Tree<User> UserTree; //дерево пользователей
	Tree<Record> RecordTree; //дерево записей
	User pers("admin", "admin", "admin"); //администратор

	UserTree.Insert(pers); //добавление администратора
	User *currentUser = new User();

	currentUser = access(&UserTree, *currentUser);
	
	cout << "Hello, " << currentUser->GetNick() << ". How are you?" << endl;

	UserTree.Show();
	return 0;
}
