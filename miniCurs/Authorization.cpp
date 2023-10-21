#include "Authorization.h"

void GetAccess(Tree<User>& root, User &user) {
	cout << "Do you have an account?" << endl;
	string answer;
	cin >> answer;
	if (answer == "yes") {
		system("cls");
		cin.ignore(cin.rdbuf()->in_avail());
		SignIn(root, user);
	}
	else {
		system("cls");
		cin.ignore(cin.rdbuf()->in_avail());
		SignUp(root, user);
	}
}

void SignIn(Tree<User>& root, User user)
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
		system("cls");
		exit(0);
	}
}

void SignUp(Tree<User>& root, User& user)
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
	system("cls");
}
