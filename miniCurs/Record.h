#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Record
{
private:
	string _companyName;
	string _agent;
	string _phoneNumber;
	string _streetName;
	int _houseNumber;
public:
	Record() :_companyName{ "unknown" }, _agent{ "unknown" }, _phoneNumber{ "unknown" }, _streetName{ "unknown" }, _houseNumber{ 0 } {}

	Record(string companyName, string agent, string phoneNumber, string streetName, int houseNumber) {
		this->_companyName = companyName;
		this->_agent = agent;
		this->_phoneNumber = phoneNumber;
		this->_streetName = streetName;
		this->_houseNumber = houseNumber;
	}

	Record(const Record& rec) {
		_companyName = rec._companyName;
		_agent = rec._agent;
		_phoneNumber = rec._phoneNumber;
		_streetName = rec._streetName;
		_houseNumber = rec._houseNumber;
	}

	Record& operator*() {
		return *this;
	}

	bool operator<(const Record& rec) const {
		return this->_companyName < rec._companyName;
	}

	bool operator>(const Record& rec) const {
		return this->_companyName > rec._companyName;
	}

	bool operator==(const Record& rec) const {
		return this->_companyName == rec._companyName;
	}

	bool operator<(const string& str) {
		return this->_companyName < str;
	}

	bool operator>(const string& str) {
		return this->_companyName > str;
	}

	bool operator==(const string& str) {
		return this->_companyName == str;
	}

	string GetComName() const;
	void SetComName(string comName);

	string GetAgent() const;
	void SetAgent(string agent);

	string GetPhoneNum()const;
	void SetPhoneNum(string phoneNum);

	string GetStreetName()const;
	void SetStreetName(string streetName);

	int GetHouseNum()const;
	void SetHouseNum(int num);

	void ShowRec();

	void CreateRecord() {
		string comName, agent, phoneNum, streetName;
		int houseNum;
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Enter name of this company: ";
		cin >> comName;
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Enter agent:";
		cin >> agent;
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Enter phone of this company: ";
		cin >> phoneNum;
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Enter street name of this company: ";
		cin >> streetName;
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Enter house number: " << endl;
		cin >> houseNum;
		this->SetComName(comName);
		this->SetAgent(agent);
		this->SetPhoneNum(phoneNum);
		this->SetStreetName(streetName);
		this->SetHouseNum(houseNum);
	}
};

