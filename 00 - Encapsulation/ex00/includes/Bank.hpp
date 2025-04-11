#ifndef BANK_HPP
# define BANK_HPP

#include "Account.hpp"
#include <vector>
#include <iostream>

using namespace std;

class Bank
{
	private:
		int _liquidity;
		vector<Account *> clientAccounts;

	public:
		Bank(void);
		~Bank(void);
		Account* createAccount(int id, double value);
};

#endif