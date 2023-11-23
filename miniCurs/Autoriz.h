#pragma once
#include "func.h"
#include "Authorization.h"
#include "UserInterface.h"
// класс дерево проверить и дописать чего не хватает
// класс интерфейс админа написать
// перенести все функции из .h в .сср
// залить на гитхаб

class Autoriz
{
public:
	void LesGo() {
		UserInterface personInterface;

		fstream users;
		Tree<User> UserTree; //дерево пользователей
		User* currentUser = new User();

		Admin* admin = new Admin();

		CreateUserTree(UserTree, users, "Users.txt");

		currentUser = access(&UserTree, *currentUser);

		//cout << endl << "Current user" << endl;
		//currentUser->ShowUser();
		//cout << "**************" << endl;


		UserTree.Delete();
		//if (currentUser->GetRole() == "user")
		//{
		//	personInterface.UserAccount(*currentUser);
		//}
		
	}
};

