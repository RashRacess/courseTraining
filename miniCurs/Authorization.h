#pragma once
#include "func.h"

User* GetAccess(Tree<User> &root, User& user);

User* SignIn(Tree<User> &root, User user);

User* SignUp(Tree<User>&root, User& user);