#pragma once
#include "User.h"
//#include "Tree.h"
//#include "Record.h"
using namespace std;

class Admin : public User
{
	bool isAdmin;
public:
	Admin() : User() {
		isAdmin = true;
		this->SetRole("admin");
	}
	Admin(string name, string password, string role, bool isAdmin) : User(name, password) {
		role = "admin";
		isAdmin = true;
	}

	Admin(const Admin& admin) {
		this->SetNick(admin.GetNick());
		this->SetPassword(admin.GetPassword());
		this->SetRole(admin.GetRole());
	}

	Admin& operator=(const User& user) {
		this->SetNick(user.GetNick());
		this->SetPassword(user.GetPassword());
		this->SetRole("admin");
		return *this;
	}

	Admin& operator=(const Admin& admin) {
		if (&admin != this) {
			this->SetNick(admin.GetNick());
			this->SetPassword(admin.GetPassword()); 
			this->SetRole("admin");
		}
		return *this;
	}

	Admin& operator*() {
		return *this;
	}

	void ShowRecordTree() {
		cout << "records" << endl;
	}

	bool operator>(const Admin& other) const {
		return this->GetNick() > other.GetNick();
	}

	bool operator<(const Admin& other) const {
		return this->GetNick() < other.GetNick();
	}

	bool operator==(const Admin& other) const {
		return this->GetNick() == other.GetNick();
	}

	bool operator> (const string& str) const {
		return this->GetNick() > str;
	}

	bool operator<(const string& str) const {
		return this->GetNick() < str;
	}

	bool operator==(const string& str) const {
		return this->GetNick() == str;
	}

	template<typename T>
	void ShowTree(Tree<T>&root) {
		root.Show();
	}
};

