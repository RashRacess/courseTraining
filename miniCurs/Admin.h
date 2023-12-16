#pragma once
#include "User.h"
using namespace std;

class Admin : public User
{
	bool isAdmin;
public:
	Admin();
	Admin(string name, string password, string role, bool isAdmin);

	Admin(const Admin& admin);

	Admin& operator=(const User& user);

	Admin& operator=(const Admin& admin);

	Admin& operator*();

	bool operator>(const Admin& other) const;

	bool operator<(const Admin& other) const;

	bool operator==(const Admin& other) const;

	bool operator> (const string& str) const;

	bool operator<(const string& str) const;

	bool operator==(const string& str) const;
};

