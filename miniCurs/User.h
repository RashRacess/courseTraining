#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class User
{
private:
	string _nick;
	string _password;
	string _role;
public:

	User() : _nick{ "unknown" }, _password{ "unknown" }, _role{ "unknown" } {}

	User(string nick, string password, string role);

	User(string nick, string password);

	~User();

	User(const User& user);

	User& operator=(const User& user);

	bool operator>(const User& other) const;

	bool operator<(const User& other) const;

	bool operator==(const User& other) const;

	bool operator==(const string& other) const;

	bool operator<(const string& str) const;

	bool operator>(const string& str) const;

	User& operator*();

	void SetNick(string nick);

	string GetNick() const;

	void SetPassword(string password);

	string GetPassword() const;

	void SetRole(string role);

	string GetRole() const;

	void ShowUser();

	void CreateUser();

	//template<typename T>
	//void ShowTree(Tree<T>& root) {
	//	root.Show();
	//}
};
