#pragma once
#include "func.h"
#include "Authorization.h"
#include "UserInterface.h"
#include "AdminInterface.h"
// класс дерево проверить и дописать чего не хватает
// класс интерфейс админа написать
// перенести все функции из .h в .сср
// залить на гитхаб

class Autoriz
{
public:
	void LesGo() {
		UserInterface personInterface;
		AdminInterface adminInterface;

		fstream users;
		Tree<User> UserTree; //дерево пользователей
		User* currentUser = new User();

		Admin* admin = new Admin();

		CreateUserTree(UserTree, users, "Users.txt");

		UserTree.Show();

		currentUser = access(&UserTree, *currentUser);


		if (!UserTree.Search(*currentUser)) {
			users.open("Users.txt", ios::app);
			if (!users.is_open()) return;
			users << endl << currentUser->GetNick() << " " << currentUser->GetPassword() << " " << currentUser->GetRole();
			users.close();
		}

		cout << endl << "Current user" << endl;
		currentUser->ShowUser();
		cout << "**************" << endl;

		UserTree.Delete();
		if (currentUser->GetRole() == "user")
		{
			personInterface.UserAccount(*currentUser);
		}
		if (currentUser->GetRole() == "admin") {
			*admin = copirovanie(*currentUser);
			adminInterface.AdminAccount(*admin);
		}
		return;
	}
};