#include "../includes/Account.hpp"

set<int> Account::used_ids;

Account::Account(int id, double value) : _id(id), _value(value)
{
	if (used_ids.count(id)) {
		throw std::invalid_argument("id already used");
	}
	used_ids.insert(id);
	cout << "Account " << _id << " has been created with the value" << _value << endl;
	return;
}

Account::~Account(void)
{
	used_ids.erase(_id);
	cout << "Account " << _id << " has been deleted" << endl;
	return;
}

//	friend std::ostream& operator << (std::ostream& p_os, const Account& p_account)
	//{
	//	p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
	//	return (p_os);
	//}