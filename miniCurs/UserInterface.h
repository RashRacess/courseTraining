#pragma once
#include "func.h"

class UserInterface
{
public:
	void UserAccount(User user) {
		fstream records;
		Tree<Record> RecordTree; //дерево записей
		CreateRecordTree(RecordTree, records, "Records.txt");
		system("cls");
		cout << "Hello, " << user.GetNick() << endl;
		Sleep(1000);
		int forSwitch = -1;
		while (forSwitch != 3) {
			system("cls");
			cout << "1. Show your profile" << endl;
			cout << "2. Show Records" << endl;
			cout << "4. Exit" << endl;
			forSwitch = GetNumber<int>("Your choise is");
			system("cls");
			switch (forSwitch)
			{
			case 1:
				cout << "you choosed showing your profile" << endl;
				user.ShowUser();
				showAndWAit();
				break;

			case 2:
				cout << "you choosed showing book of recording" << endl;
				user.ShowTree<Record>(RecordTree);
				showAndWAit();
				break;
			case 3:
				cout << "exit" << endl;
				break;
			}
		}
	}
};

