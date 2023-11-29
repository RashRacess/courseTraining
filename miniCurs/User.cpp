#include "User.h"

User::~User() {}

User& User::operator=(const User& user)
{
	if (&user != this) {
		_nick = user._nick;
		_password = user._password;
		_role = user._role;
	}
	return *this;
}
