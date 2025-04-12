#include "../includes/Account.hpp"

set<int> Account::used_ids;

Account::Account(int id, int value) : _id(id), _value(value)
{
	if (used_ids.count(id)) {
		throw invalid_argument("id already used");
	}
	used_ids.insert(id);
	cout << GREEN << "Account " << _id << " has been created with the value " << _value << RESET << endl;
}

Account::~Account(void)
{
	used_ids.erase(_id);
	cout << RED << "Account " << _id << " has been deleted" << RESET << endl;
	return;
}

int Account::getId(void) const
{
	return _id;
}

int Account::getValue(void) const
{
	return _value;
}

void Account::setValue(int value)
{
	_value = value;
}

void Account::addMoney(int value)
{
	_value += value;
}

void Account::deleteMoney(int value)
{
    if (_value >= value)
        _value -= value;
}

ostream& operator<<(ostream& os, const Account& account)
{
    os << "[" << account._id << "] - [" << account._value << "]";
    return os;
}