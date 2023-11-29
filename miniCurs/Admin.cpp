#include "Admin.h"

Admin::Admin() : User() {
	isAdmin = true;
	this->SetRole("admin");
}

Admin::Admin(string name, string password, string role, bool isAdmin) : User(name, password) {
	role = "admin";
	isAdmin = true;
}

Admin::Admin(const Admin& admin)
{
	this->SetNick(admin.GetNick());
	this->SetPassword(admin.GetPassword());
	this->SetRole(admin.GetRole());
}

Admin& Admin::operator=(const User& user)
{
	this->SetNick(user.GetNick());
	this->SetPassword(user.GetPassword());
	this->SetRole("admin");
	return *this;
}

Admin& Admin::operator=(const Admin& admin)
{
	if (&admin != this) {
		this->SetNick(admin.GetNick());
		this->SetPassword(admin.GetPassword());
		this->SetRole("admin");
	}
	return *this;
}

Admin& Admin::operator*()
{
	return *this;
}

bool Admin::operator>(const Admin& other) const
{
	return this->GetNick() > other.GetNick();
}

bool Admin::operator<(const Admin& other) const
{
	return this->GetNick() < other.GetNick();
}

bool Admin::operator==(const Admin& other) const
{
	return this->GetNick() == other.GetNick();
}

bool Admin::operator>(const string& str) const
{
	return this->GetNick() > str;
}

bool Admin::operator<(const string& str) const
{
	return this->GetNick() < str;
}

bool Admin::operator==(const string& str) const
{
	return this->GetNick() == str;
}




