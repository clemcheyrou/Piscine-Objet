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
		vector<Account *> _clientAccounts;

	public:
		Bank(void);
		~Bank(void);
		Account* createAccount(int id, int value);
		void deleteAccount(int id);
		void deposit(Account* account, int value);
		void withdraw(Account* account, int value);
		bool loanToAccount(int id, int value);

		friend ostream& operator<<(ostream& os, const Bank& bank);
};

#endif