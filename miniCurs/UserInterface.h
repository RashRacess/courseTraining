#pragma once
#include "func.h"

class UserInterface
{
public:
	void UserAccount(User user) {
		fstream records;
		Tree<Record> RecordTree; //дерево записей
		string nameOfCompany;

		CreateRecordTree(RecordTree, records, "Records.txt");
		system("cls");
		cout << "Hello, " << user.GetNick() << endl;
		Sleep(1000);
		int forSwitch = -1;
		while (forSwitch != 4) {
			system("cls");
			cout << "1. Show your profile" << endl;
			cout << "2. Show Records" << endl;
			cout << "3. Find record" << endl;
			cout << "4. Exit" << endl;
			forSwitch = GetNumber<int>("Your choise is");
			system("cls");
			switch (forSwitch)
			{
			case 1:
				cout << "you choosed showing your profile" << endl;
				HumanUserInference();
				cout << user << endl;
				showAndWAit();
				break;

			case 2:
				cout << "you choosed showing book of recording" << endl;
				HumanRecordInference();
				RecordTree.Show();
				showAndWAit();
				break;
			case 3:
				cout << "you choosed search record" << endl;
				cout << "Enter name of company: ";
				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, nameOfCompany);
				HumanRecordInference();
				ShowRecordWithCompanyName(RecordTree.GetRoot(), nameOfCompany);
				cout << string(96, '-');
				showAndWAit();
				break;

			case 4:
				cout << "exit" << endl;
				break;
			}
		}
	}
};

