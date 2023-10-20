#include "Record.h"

string Record::GetComName() const 
{
	return this->_companyName;
}

void Record::SetComName(string comName)
{
	this->_companyName = comName;
}

string Record::GetAgent() const
{
	return this->_agent;
}

void Record::SetAgent(string agent)
{
	this->_agent = agent;
}

string Record::GetPhoneNum() const
{
	return this->_phoneNumber;
}

void Record::SetPhoneNum(string phoneNum)
{
	this->_phoneNumber = phoneNum;
}

string Record::GetStreetName() const
{
	return this->_streetName;
}

void Record::SetStreetName(string streetName)
{
	this->_streetName = streetName;
}

int Record::GetHouseNum() const
{
	return this->_houseNumber;
}

void Record::SetHouseNum(int num)
{
	this->_houseNumber = num;
}

void Record::ShowRec()
{
	cout << "Name of company: " << this->_companyName << endl;
	cout << "Agent: " << this->_agent << endl;
	cout << "Phone number: " << this->_phoneNumber << endl;
	cout << "Street name: " << this->_streetName << endl;
	cout << "house number: " << this->_houseNumber << endl;
}