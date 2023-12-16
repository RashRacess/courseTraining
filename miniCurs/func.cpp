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
	myCout << "| " << setw(15) << other.GetNick() << " | " << setw(15) << other.GetPassword() << " | " << setw(10) << other.GetRole() << " |";
	return myCout;
}

ostream& operator<<(ostream& myCout, const Admin& other)
{
	myCout << "| " << setw(15) << other.GetNick() << " | " << setw(15) << other.GetPassword() << " | " << setw(10) << other.GetRole() << " |";
	return myCout;
}

ostream& operator<<(ostream& myCout, const Record& other) {
	myCout << "| " << setw(15) << other.GetComName() << " | ";
	myCout << setw(20) << other.GetAgent() << " | ";
	myCout << setw(15) << other.GetPhoneNum() << " | ";
	myCout << setw(20) << other.GetStreetName() << " | ";
	myCout << setw(10) << other.GetHouseNum() << " |";
	return myCout;
}

ostream& operator<<(ostream& fCout, const User* other)
{
	fCout << "| " << setw(10) << other->GetNick() << " | " << setw(15) << other->GetPassword() << " | " << setw(10) << other->GetRole() << " |";
	return fCout;
}

ostream& operator<<(ostream& fCout, const Admin* other)
{
	fCout << "| " << setw(10) << other->GetNick() << " | " << setw(15) << other->GetPassword() << " | " << setw(10) << other->GetRole() << " |";
	return fCout;
}

ostream& operator<<(ostream& fCout, const Record* other)
{
	fCout << "| " << setw(10) << other->GetComName() << " | ";
	fCout << setw(10) << other->GetAgent() << " | ";
	fCout << setw(10) << other->GetPhoneNum() << " | ";
	fCout << setw(20) << other->GetStreetName() << " | ";
	fCout << setw(8) << other->GetHouseNum() << " |";
	return fCout;
}

void CreateUserTree(Tree<User>& root, fstream& file, string nameOfFile)
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

void CreateRecordTree(Tree<Record>& root, fstream& file, string nameOfFile) {
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
	cout << "--------------------------------------------------" << endl;
	cout << "| " << setw(15) << "User" << " | " << setw(15) << "Password" << " | " << setw(10) << "Role" << " |" << endl;
	cout << "--------------------------------------------------" << endl;
}

void HumanRecordInference() {
	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "| " << setw(15) << "Name" << " | ";
	cout << setw(20) << "Agent" << " | ";
	cout << setw(15) << "Phone" << " | ";
	cout << setw(20) << "Street Name" << " | ";
	cout << setw(10) << "Home num" << " |" << endl;
	cout << "------------------------------------------------------------------------------------------------" << endl;
}

Admin& copirovanie(const User& user) {
	Admin* admin = new Admin();
	admin->SetNick(user.GetNick());
	admin->SetPassword(user.GetPassword());
	return *admin;
}

void showAndWAit()
{
	char ch;
	ch = _getch();
	if (ch) {
		system("cls");
	}
}

void ShowRecordWithStreetName(Node<Record>* root, string str)
{
	if (root) {
		if (root->data.GetStreetName() == str)
			cout << root->data << endl;
		ShowRecordWithStreetName(root->left, str);
		ShowRecordWithStreetName(root->right, str);
	}
}

void ShowRecordWithCompanyName(Node<Record>* root, string str)
{
	if (root) {
		if (root->data.GetComName() == str)
			cout << root->data << endl;
		ShowRecordWithCompanyName(root->left, str);
		ShowRecordWithCompanyName(root->right, str);
	}
}

void ShowRecordWithAgent(Node<Record>* root, string str)
{
	if (root) {
		if (root->data.GetAgent().find(str) != std::string::npos)
			cout << root->data << endl;
		ShowRecordWithAgent(root->left, str);
		ShowRecordWithAgent(root->right, str);
	}
}

void ShowUsersWithNicks(Node<User>* root, string name)
{
	if (root) {
		if (root->data.GetNick() == name) {
			cout << root->data << endl;
		}
		ShowUsersWithNicks(root->left, name);
		ShowUsersWithNicks(root->right, name);
	}
}