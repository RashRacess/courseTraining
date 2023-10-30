#include "Authorization.h"

User* GetAccess(Tree<User>& root, User& user) {
	cout << "Do you have an account?" << endl;
	string answer;
	cin >> answer;
	if (answer == "yes") {
		system("cls");
		cin.ignore(cin.rdbuf()->in_avail());
		return SignIn(root, user);
	}
	else {
		system("cls");
		cin.ignore(cin.rdbuf()->in_avail());
		return SignUp(root, user);
	}
}

User* SignIn(Tree<User>& root, User user)
{
	cout << "enter your name: ";
	string name;
	getline(cin, name);
	cout << "enter your password: ";
	string pass;
	getline(cin, pass);
	user.SetNick(name);
	user.SetPassword(pass);
	if (root.Search(user)) {
		system("cls");
		cout << "congratulations" << endl;
	}
	else {
		cout << "You are not the father" << endl;
		exit(0);
	}
}

User* SignUp(Tree<User>& root, User& user)
{
	cout << "enter your name: ";
	string name;
	getline(cin, name);
	cout << "enter your password: ";
	string pass;
	getline(cin, pass);
	user.SetNick(name);
	user.SetPassword(pass);
	user.SetRole("user");
	root.Insert(user);
	return &user;
	system("cls");
}