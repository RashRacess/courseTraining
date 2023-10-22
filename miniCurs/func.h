#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <random>
#include <typeinfo>
#include <ctime>
#include <chrono>
#include <string>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "User.h"
#include "Record.h"
#include "Tree.h"
#include "LinkedList.h"


#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

using namespace std;
template<typename Type>
Type GetNumber(const char* S)
{
	Type a;
	cout << S << ": ";
	while (!(cin >> a))
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Try again: ";
	}
	return a;
}

void CreateUserTree(Tree<User>& root, ifstream& file, string nameOFile);

void CreateRecordTree(Tree<Record>& root, ifstream& file, string nameOfFile);

void devString(string in, string* arr);

ostream& operator<<(ostream& myCout, const User& other);

ostream& operator<<(ostream& myCout, const Record& other);

void HumanUserInference();

void HumanRecordInference();