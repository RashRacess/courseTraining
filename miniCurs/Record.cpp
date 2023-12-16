#include "Record.h"

Record::Record(string companyName, string agent, string phoneNumber, string streetName, int houseNumber)
{
	this->_companyName = companyName;
	this->_agent = agent;
	this->_phoneNumber = phoneNumber;
	this->_streetName = streetName;
	this->_houseNumber = houseNumber;
}

Record::Record(const Record& rec)
{
	_companyName = rec._companyName;
	_agent = rec._agent;
	_phoneNumber = rec._phoneNumber;
	_streetName = rec._streetName;
	_houseNumber = rec._houseNumber;
}

Record& Record::operator*()
{
	return *this;
}

bool Record::operator<(const Record& rec) const
{
	if (this->_companyName != rec._companyName)
		return this->_companyName < rec._companyName;
	else {
		return this->_agent < rec._agent;
	}
}

bool Record::operator>(const Record& rec) const
{
	if (this->_companyName != rec._companyName)
		return this->_companyName > rec._companyName;
	else {
		return this->_agent > rec._agent;
	}
}

bool Record::operator==(const Record& rec) const
{
	return this->_companyName == rec._companyName and this->_agent == rec._agent;
}

bool Record::operator<(const string& str) const
{
	return this->_agent < str;
}

bool Record::operator>(const string& str) const
{
	return this->_agent > str;
}

bool Record::operator==(const string& str) const
{
	return this->GetComName().find(str) != std::string::npos;
}

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

void Record::CreateRecord()
{
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
