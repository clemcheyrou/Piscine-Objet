#include <iostream>
#include "Bank.hpp"

int main()
{
	Bank bank = Bank();
	Account* clem = bank.createAccount(1, 1000);
	bank.deposit(clem, 500);
	bank.withdraw(clem, 100);

	cout << bank;

	return (0);
}