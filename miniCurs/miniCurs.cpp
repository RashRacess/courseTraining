#include "func.h"
#include "Authorization.h"

int main() {
	LinkedList<User> userList;
	User pers("RashRecess", "33TG2", "admin"); //администратор
	userList.Add(pers);
	userList.Show();
	userList.Delete();
	return 0;
}
