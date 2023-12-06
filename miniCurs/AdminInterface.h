#pragma once
#include "func.h"

class AdminInterface
{
public:
	void AdminAccount(Admin admin) {
		fstream recordedUsers;
		fstream recordedRecords;

		fstream users;
		Tree<User> UserTree; //дерево пользователей
		CreateUserTree(UserTree, users, "Users.txt");

		fstream records;
		Tree<Record> RecordTree; //дерево записей
		CreateRecordTree(RecordTree, records, "Records.txt");

		Record* recordTmp = new Record();
		User* userTmp = new User();

		string nick, password, role;
		string nameOfCompany, agent;
		system("cls");

		cout << "Hello, " << admin.GetNick() << endl;
		Sleep(1000);

		int forSwitch = -1;
		while (forSwitch != 9) {
			system("cls");
			cout << "0. Show your profile" << endl;
			cout << "1. Show user tree" << endl;
			cout << "2. Show record tree" << endl;
			cout << "3. Search record" << endl;
			cout << "4. Search user" << endl;
			cout << "5. Add record" << endl;
			cout << "6. Add user" << endl;
			cout << "7. Record users to file" << endl;
			cout << "8. Record records to file" << endl;
			cout << "9. Exit" << endl;
			cout << "10. delete node" << endl;
			forSwitch = GetNumber<int>("Your choise");
			system("cls");
			switch (forSwitch) {
			case 0:
				cout << "you choosed show your profile" << endl;
				admin.ShowUser();
				showAndWAit();
				break;
			case 1:
				cout << "you choosed show user tree" << endl;
				UserTree.Show();
				showAndWAit();
				break;
			case 2:
				cout << "you choosed show record tree" << endl;
				RecordTree.Show();
				showAndWAit();
				break;
			case 3:
				cout << "you choosed search record" << endl;
				cout << "Enter name of company: ";
				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, nameOfCompany);
				RecordTree.TreeSearchString(nameOfCompany);
				showAndWAit();
				break;
			case 4:
				cout << "you choosed search user" << endl;
				cout << "Enter nick: ";
				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, nick);
				UserTree.TreeSearchString(nick);
				showAndWAit();
				break;
			case 5:
				cout << "you choosed add record" << endl;
				recordTmp->CreateRecord();
				RecordTree.Insert(*recordTmp);
				break;
			case 6:
				cout << "you choosed add user" << endl;
				userTmp->CreateUser();
				UserTree.Insert(*userTmp);
				break;
			case 7:
				UserTree.RecordTreeToFile(recordedUsers, "RecordedUsers.txt");
				break;
			case 8:
				RecordTree.RecordTreeToFile(recordedRecords, "RecordedRecords.txt");
				break;
			case 9:
				cout << "Exit" << endl;
				break;
			}
		}
	}
};

