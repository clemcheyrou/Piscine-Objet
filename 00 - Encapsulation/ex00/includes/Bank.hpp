#ifndef BANK_HPP
# define BANK_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

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
		void modifyAccount(int id, int value);
		void deposit(Account* account, int value);
		void withdraw(Account* account, int value);
		bool loanToAccount(int id, int value);

		friend ostream& operator<<(ostream& os, const Bank& bank);
};

#endif