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

};

