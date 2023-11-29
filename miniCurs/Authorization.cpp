#include "Authorization.h"

User* access(Tree<User>* root, User& user)
{
	string nick, pass, role;
	cout << "Enter nick: ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, nick);
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "Enter password: ";
	getline(cin, pass);
	user.SetNick(nick);
	user.SetPassword(pass);

	if (root->Search(user)) {
		user.SetRole(root->Search(user)->GetRole());
		cout << "ok" << endl;
		return &user;
	}

	else {
		//root->Insert(user);
		user.SetRole("user");
		cout << "ok" << endl;
		return &user;
	}
}
