#pragma once
#include "func.h"

class AdminInterface
{
public:
	void AdminAccount(Admin admin) {
		fstream recordedUsers; //файл записанных пользователей
		fstream users; //файл с пользовател€ми
		Tree<User> UserTree; //дерево пользователей
		CreateUserTree(UserTree, users, "Users.txt"); //конструирование дерева пользователей
		User* userTmp = new User(); // буферный пользователь
		string nick, password, role; // дополнительные переменные дл€ работы с пользовател€ми



		fstream recordedRecords; //файл записанных записей
		fstream records; //файл с запис€ми
		Tree<Record> RecordTree; //дерево записей
		CreateRecordTree(RecordTree, records, "Records.txt"); // конструирование дерева записей
		Record* recordTmp = new Record(); // буферна€ запись
		string nameOfCompany, agent, streetName; // дополнительные переменные дл€ работы с запис€ми

		int size = 0;

		system("cls");

		cout << "Hello! And welcome to the Los Pollos Hermanos family. My name is Gustavo, but you can call me \"Gus\".";
		showAndWAit();

		int forSwitch = -1;
		while (forSwitch != 12) {
			system("cls");
			cout << "0. Show your profile" << endl;
			cout << "1. Show user tree" << endl;
			cout << "2. Show record tree" << endl;
			cout << "3. Search record with street name" << endl;
			cout << "4. Search with agent" << endl;
			cout << "5. Search user" << endl;
			cout << "6. Add record" << endl;
			cout << "7. Add user" << endl;
			cout << "8. Record users to file" << endl;
			cout << "9. Record records to file" << endl;
			cout << "10. delete record" << endl;
			cout << "11. delete user" << endl;
			cout << "12. REwrite user" << endl;
			cout << "13. Exit" << endl;
			forSwitch = GetNumber<int>("Your choise");
			system("cls");
			switch (forSwitch) {
			case 0:
				cout << "you choosed show your profile" << endl;
				HumanUserInference();
				cout << admin << endl;
				cout << string(50, '-');
				showAndWAit();
				break;

			case 1:
				cout << "you choosed show user tree" << endl;
				HumanUserInference();
				UserTree.Show();
				cout << string(50, '-') << endl;
				cout << "size of tree is: " << UserTree.GetSize();
				showAndWAit();
				break;

			case 2:
				cout << "you choosed show record tree" << endl;
				HumanRecordInference();
				RecordTree.Show();
				cout << string(96, '-');
				cout << "size of tree is: " << RecordTree.GetSize();
				showAndWAit();
				break;

			case 3:
				cout << "you choosed search record" << endl;
				cout << "Enter name of street: ";
				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, streetName);
				HumanRecordInference();
				ShowRecordWithStreetName(RecordTree.GetRoot(), streetName);
				cout << string(96, '-');
				showAndWAit();
				break;
			case 4:
				cout << "you choosed search with name of agent" << endl;
				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, agent);
				HumanRecordInference();
				ShowRecordWithAgent(RecordTree.GetRoot(), agent);
				cout << string(96, '-');
				showAndWAit();
				break;

			case 5:
				cout << "you choosed search user" << endl;
				cout << "Enter nick: ";
				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, nick);
				HumanUserInference();
				ShowUsersWithNicks(UserTree.GetRoot(), nick);
				cout << string(50, '-');
				showAndWAit();
				break;

			case 6:
				cout << "you choosed add record" << endl;
				recordTmp->CreateRecord();
				RecordTree.Insert(*recordTmp);
				break;

			case 7:
				cout << "you choosed add user" << endl;
				userTmp->CreateUser();
				UserTree.Insert(*userTmp);
				break;

			case 8:
				UserTree.RecordTreeToFile(recordedUsers, "RecordedUsers.txt");
				break;

			case 9:
				RecordTree.RecordTreeToFile(recordedRecords, "RecordedRecords.txt");
				break;

			case 10:
				cout << "deleting the record" << endl;
				cout << "Enter name of company: ";
				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, nameOfCompany);
				cout << "Enter name of agent: ";
				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, agent);
				recordTmp->SetComName(nameOfCompany);
				recordTmp->SetAgent(agent);
				RecordTree.DeleteNode(*recordTmp);
				break;

			case 11:
				cout << "deleting the user" << endl;
				cout << "Enter nick: ";
				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, nick);
				cout << "enter password: " << endl;
				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, password);
				userTmp->SetNick(nick);
				userTmp->SetPassword(password);
				if (static_cast<User>(admin) == *userTmp) {
					cout << "Sorry, but this user is you. If you want to exit, just click the cross in the corner of the screen" << endl;
					showAndWAit();
					break;
				}
				UserTree.DeleteNode(*userTmp);
				break;

			case 12:
				cout << "rewriting the user" << endl;
				cout << "Enter nick: ";
				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, nick);
				cout << "enter password: " << endl;
				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, password);
				userTmp->SetNick(nick);
				userTmp->SetPassword(password);
				if (static_cast<User>(admin) == *userTmp) {
					cout << "Sorry, but this user is you. If you want to exit, just click the cross in the corner of the screen" << endl;
					showAndWAit();
					break;
				}
				size = UserTree.GetSize();
				UserTree.DeleteNode(*userTmp);
				if (size != UserTree.GetSize()) {
					userTmp->CreateUser();
					UserTree.Insert(*userTmp);
				}
				else {
					cout << "Sorry, but this user is dont exist in this tree" << endl;
				}
				break;

			case 13:
				cout << "Exit" << endl;
				break;
			}
		}
	}
};

