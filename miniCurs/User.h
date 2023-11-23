#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdlib>
#include "Tree.h"
using namespace std;

class User
{
private:
	string _nick;
	string _password;
	string _role;
public:

	User() : _nick{ "unknown" }, _password{ "unknown" }, _role{ "unknown" } {}

	User(string nick, string password, string role) {
		this->_nick = nick;
		this->_password = password;
		this->_role = role;
	}

	User(string nick, string password) {
		this->_nick = nick;
		this->_password = password;
	}

	~User();

	User(const User& user) {
		_nick = user._nick;
		_password = user._password;
		_role = user._role;
	}

	User& operator=(const User& user) {
		if (&user != this) {
			_nick = user._nick;
			_password = user._password;
			_role = user._role;
		}
		return *this;
	}

	bool operator>(const User& other) const {
		return (_nick > other._nick);// and (_password > other._password);
	}

	bool operator<(const User& other) const {
		return (_nick < other._nick);// and (_password < other._password);
	}

	bool operator==(const User& other) const {
		return (_nick == other._nick);// and (_password == other._password);
	}

	User& operator*() {
		return *this;
	}

	void SetNick(string nick) {
		this->_nick = nick;
	}

	string GetNick() const {
		return this->_nick;
	}

	void SetPassword(string password) {
		this->_password = password;
	}

	string GetPassword() const {
		return this->_password;
	}

	void SetRole(string role) {
		this->_role = role;
	}

	string GetRole() const {
		return this->_role;
	}

	void ShowUser() {
		cout << "User name: " << _nick << endl;
		cout << "Password: " << _password << endl;
		cout << "Role: " << _role << endl;
	}

	User* CreateUser() {
		User* user = new User();
		string name, pass, role;
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Enter name: ";
		cin >> name;
		user->SetNick(name);
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "enter password: ";
		cin >> pass;
		user->SetPassword(pass);
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "enter role";
		cin >> role;
		user->SetRole(role);
		return user;
	}

	template<typename T>
	void ShowTree(Tree<T>& root) {
		root.Show();
	}
};
