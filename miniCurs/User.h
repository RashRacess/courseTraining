#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class User
{
private:
	string _nick;
	string _password;
	string _role;
public:
	
	User() : _nick{ "unknown" }, _password{ "unknown" }, _role{"unknown"} {}

	User(string nick, string password, string role) {
		this->_nick = nick;
		this->_password = password;
		this->_role = role;
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

	void SetNick(string nick) {
		this->_nick = nick;
	}

	string GetNick() {
		return this->_nick;
	}

	void SetPassword(string password) {
		this->_password = password;
	}

	string GetPassword() {
		return this->_password;
	}

	void SetRole(string role) {
		this->_role = role;
	}

	string GetRole() {
		return this->_role;
	}

	void ShowUser() {
		cout << "User name: " << _nick << endl;
		cout << "Password: " << _password << endl;
		cout << "Role: " << _role << endl;
	}
};

