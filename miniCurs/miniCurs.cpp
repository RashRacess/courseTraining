#include "func.h"
#include "Authorization.h"

int main() {
	Tree<User> UserTree; //дерево пользователей
	Tree<Record> RecordTree; //дерево записей
	User pers("RashRecess", "33TG2", "admin"); //администратор

	UserTree.Insert(pers); //добавление администратора
	User *currentUser = new User();

	GetAccess(UserTree, *currentUser);

	cout << "Hello, " << currentUser->GetNick() << ". How are you?";
	return 0;
}
