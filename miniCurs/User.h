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

	User& operator=(const User& user);

	bool operator>(const User& other) const {
		if (this->GetNick() != other.GetNick())
			return (this->_nick > other._nick);
		else {
			return (this->_password > other._password);
		}
	}

	bool operator<(const User& other) const {
		if (this->GetNick() != other.GetNick())
			return (this->_nick < other._nick);
		else {
			return (this->GetPassword() < other.GetPassword());
		}
	}

	bool operator==(const User& other) const {
		return (this->_nick == other._nick) and (this->_password == other._password);
	}

	bool operator==(const string& other) const {
		return this->GetNick() == other;
	}

	bool operator<(const string& str) const {
		return (this->_nick < str);
	}

	bool operator>(const string& str) const {
		return (this->_nick > str);
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
		cout << "User name: " << this->_nick << endl;
		cout << "Password: " << this->_password << endl;
		cout << "Role: " << this->_role << endl;
	}

	void CreateUser() {
		string name, pass, role;
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Enter name: ";
		cin >> name;
		this->SetNick(name);
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "enter password: ";
		cin >> pass;
		this->SetPassword(pass);
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "enter role: ";
		cin >> role;
		this->SetRole(role);
	}

	template<typename T>
	void ShowTree(Tree<T>& root) {
		root.Show();
	}
};
