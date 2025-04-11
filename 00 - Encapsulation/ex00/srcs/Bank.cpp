#include "../includes/Bank.hpp"

Bank::Bank(void) : _liquidity(999)
{
	cout << "Bank has been created" << endl;
	return;
}

Bank::~Bank(void)
{
	for (size_t i = 0; i < clientAccounts.size(); ++i)
		delete clientAccounts[i];
	clientAccounts.clear();
	cout << "Bank has been destroyed" << endl;
	return;
}

Account* Bank::createAccount(int id, double value) {
	Account* acc = new Account(id, value);
	clientAccounts.push_back(acc);
	return acc;
}

//friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
//{
//	p_os << "Bank informations : " << std::endl;
//	p_os << "Liquidity : " << p_bank.liquidity << std::endl;
//	for (auto &clientAccount : p_bank.clientAccounts)
//	p_os << *clientAccount << std::endl;
//	return (p_os);
//}