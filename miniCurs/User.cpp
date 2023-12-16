#include "User.h"

User::User(string nick, string password, string role)
{
	this->_nick = nick;
	this->_password = password;
	this->_role = role;
}

User::User(string nick, string password)
{
	this->_nick = nick;
	this->_password = password;
}

User::~User() {}

User::User(const User& user)
{
	_nick = user._nick;
	_password = user._password;
	_role = user._role;
}

User& User::operator=(const User& user)
{
	if (&user != this) {
		_nick = user._nick;
		_password = user._password;
		_role = user._role;
	}
	return *this;
}

bool User::operator>(const User& other) const
{
	if (this->GetNick() != other.GetNick())
		return (this->_nick > other._nick);
	else {
		return (this->_password > other._password);
	}
}

bool User::operator<(const User& other) const
{
	if (this->GetNick() != other.GetNick())
		return (this->_nick < other._nick);
	else {
		return (this->GetPassword() < other.GetPassword());
	}
}

bool User::operator==(const User& other) const
{
	return (this->_nick == other._nick) and (this->_password == other._password);
}

bool User::operator==(const string& other) const
{
	return this->GetNick() == other;
}

bool User::operator<(const string& str) const
{
	return (this->_nick < str);
}

bool User::operator>(const string& str) const
{
	return (this->_nick > str);
}

User& User::operator*()
{
	return *this;
}

void User::SetNick(string nick)
{
	this->_nick = nick;
}

string User::GetNick() const
{
	return this->_nick;
}

void User::SetPassword(string password)
{
	this->_password = password;
}

string User::GetPassword() const
{
	return this->_password;
}

void User::SetRole(string role)
{
	this->_role = role;
}

string User::GetRole() const
{
	return this->_role;
}

void User::ShowUser()
{
	cout << "User name: " << this->_nick << endl;
	cout << "Password: " << this->_password << endl;
	cout << "Role: " << this->_role << endl;
}

void User::CreateUser()
{
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