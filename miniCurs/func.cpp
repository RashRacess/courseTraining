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
	myCout << "| " << setw(10) << other.GetNick() << " | " << setw(15) << other.GetPassword() << " | " << setw(10) << other.GetRole() << " |";
	return myCout;
}

ostream& operator<<(ostream& myCout, const Record& other) {
	myCout << "| " << setw(10) << other.GetComName() << " | ";
	myCout << setw(10) << other.GetAgent() << " | ";
	myCout << setw(10) << other.GetPhoneNum() << " | ";
	myCout << setw(20) << other.GetStreetName() << " | ";
	myCout << setw(8) << other.GetHouseNum() << " |";
	return myCout;
}

void CreateUserTree(Tree<User>& root, ifstream& file, string nameOfFile)
{
	string line;
	string* arrString = new string[98];
	file.open(nameOfFile);
	if (!(file.is_open())) return;
	while (getline(file, line)) {
		devString(line, arrString);
		User user(arrString[0], arrString[1], arrString[2]);
		root.Insert(user);
	}
	file.close();
	delete[] arrString;
}

void CreateRecordTree(Tree<Record>& root, ifstream& file, string nameOfFile) {
	string line;
	string* arrString = new string[99];
	file.open(nameOfFile);
	if (!(file.is_open())) return;
	while (getline(file, line)) {
		devString(line, arrString);
		Record rec(arrString[0], arrString[1], arrString[2], arrString[3], stoi(arrString[4]));
		root.Insert(rec);
	}
	file.close();
	delete[] arrString;
}

void HumanUserInference() {
	cout << "---------------------------------------------" << endl;
	cout << "| " << setw(10) << "User" << " | " << setw(15) << "Password" << " | " << setw(10) << "Role" << " |" << endl;
	cout << "---------------------------------------------" << endl;
}

void HumanRecordInference() {
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "| " << setw(10) << "Name" << " | ";
	cout << setw(10) << "Agent" << " | ";
	cout << setw(10) << "Phone" << " | ";
	cout << setw(20) << "Street Name" << " | ";
	cout << setw(5) << "Home num" << " |" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
}