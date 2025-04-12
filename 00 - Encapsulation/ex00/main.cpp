#include <iostream>
#include "includes/Bank.hpp"

int main()
{
	cout << "TEST1-------------------------------------------------------" << endl;
	cout << "The accounts must never have two identical IDs\n" << endl;
	try {
		Bank bank = Bank();
		Account* clem = bank.createAccount(1, 1000);
		Account* elise = bank.createAccount(1, 1200);
	} catch (const invalid_argument& e) {
		cout << BLUE << e.what() << RESET << endl; 
	}
	cout << "\nTEST2-------------------------------------------------------" << endl;
	cout << "The bank must receive 5 pourcent of each money inflow on these client accounts\n" << endl;
	
	Bank bank = Bank();
	cout << bank;
	Account* clem = bank.createAccount(1, 1000);
	bank.deposit(clem, 500);
	cout << bank;

	cout << "\nTEST3-------------------------------------------------------" << endl;
	cout << "The attributes of the structures must not be modifiable from the outside\n" << endl;

	//clem->addMoney(500); 
	
	cout << "\nTEST4-------------------------------------------------------" << endl;
	cout << "The bank must be able to create, delete and modify the accounts of these customers\n" << endl;

	bank.deleteAccount(clem->getId());
	Account* newclem = bank.createAccount(1, 1000);
	cout << *newclem << '\n';
	bank.modifyAccount(1, 1500);
	cout << *newclem << '\n';

	cout << "\nTEST5-------------------------------------------------------" << endl;
	cout << "A customer can withdraw money through the bank\n" << endl;
	bank.withdraw(clem, 100);
	cout << *newclem << '\n';

	cout << "\nTEST6-------------------------------------------------------" << endl;
	cout << "The bank must be able to give a loan to a customer, within the limits of its funds\n" << endl;
	
	cout << bank;
	cout << *newclem << '\n';

	bank.loanToAccount(1, 2000);
	bank.loanToAccount(1, 1000);

	cout << bank;
	cout << *newclem << '\n';

	bank.loanToAccount(1, -2000);

	return (0);
}