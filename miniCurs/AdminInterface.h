#pragma once
#include "func.h"

class AdminInterface
{
	void AdminAccount(Admin admin) {
		fstream recordedUsers;
		fstream recordedRecords;

		fstream users;
		Tree<User> UserTree; //������ �������������
		CreateUserTree(UserTree, users, "Users.txt");

		fstream records;
		Tree<Record> RecordTree; //������ �������
		CreateRecordTree(RecordTree, records, "Records.txt");

		Record* recordTmp = new Record();
		User* userTmp = new User();

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
				admin.ShowTree<User>(UserTree);
				showAndWAit();
				break;
			case 2:
				cout << "you choosed show record tree" << endl;
				admin.ShowTree<Record>(RecordTree);
				showAndWAit();
				break;
			case 3:
				cout << "you choosed search record" << endl;
				break;
			case 4:
				cout << "you choosed search user" << endl;
				break;
			case 5:
				cout << "you choosed add record" << endl;
				//recordTmp->CreateRecord();
				//RecordTree.Insert(*recordTmp);
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
