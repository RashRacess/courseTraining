#include "func.h"

void devString(string in, string* arr)
{
	int c = 0;
	string tmp;
	for (int i = 0; i < in.size(); i++) {
		if (in[i] != ' ')
			tmp += in[i];
		else {
			arr[c] = tmp;
			tmp = "";
			c++;
		}
	}
	arr[c] = tmp;
	//(*count) = ++c;
}


ostream& operator<<(ostream& myCout, const User& other) {
	myCout << "User name: " << other.GetNick() << '\t';
	myCout << "Password: " << other.GetPassword() << '\t';
	myCout << "Role: " << other.GetRole() << '\t';
	return myCout;
}

ostream& operator<<(ostream& myCout, const Record& other) {
	myCout << "Name of company: " << other.GetComName() << endl;
	myCout << "Agent: " << other.GetAgent() << endl;
	myCout << "Phone number: " << other.GetPhoneNum() << endl;
	myCout << "Street name: " << other.GetStreetName()<< endl;
	myCout << "house number: " << other.GetHouseNum() << endl;
	return myCout;
}

//void CreateUserTree(Tree &root, ifstream& file)
//{
//	User* user = new User();
//	string line;
//	string* arrString = new string[100];
//	file.open("Users.txt");
//	if (!(file.is_open())) return;
//	while (getline(file, line)) {
//		devString(line, arrString);
//		user->SetNick(arrString[0]);
//		root.InsertNode(arrString[0]);
//	}
//	file.close();
//	delete[] arrString;
//}


