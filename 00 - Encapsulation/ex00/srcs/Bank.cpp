#include "../includes/Bank.hpp"

Bank::Bank(void) : _liquidity(999)
{
	cout << GREEN << "Bank has been created" << RESET << endl;
	return;
}

Bank::~Bank(void)
{
	for (size_t i = 0; i < _clientAccounts.size(); ++i)
		delete _clientAccounts[i];
	_clientAccounts.clear();
	cout << RED << "Bank has been destroyed" << RESET << endl;
	return;
}

Account* Bank::createAccount(int id, int value) {
	Account* newAccount = new Account(id, value);
	_clientAccounts.push_back(newAccount);
	return newAccount;
}

void Bank::deleteAccount(int id) {
    for (std::vector<Account*>::iterator it = _clientAccounts.begin(); it != _clientAccounts.end(); it++)
	{
        if ((*it)->getId() == id) {
            delete *it;
            it = _clientAccounts.erase(it); 
            cout << RED << "Account deleted " << id << RESET << endl;
            return;
        } else {
            ++it;
        }
    }
    cerr << "Account " << id << " not found" << endl;
}

void Bank::modifyAccount(int id, int value) {
    for (std::vector<Account*>::iterator it = _clientAccounts.begin(); it != _clientAccounts.end(); it++)
	{
        if ((*it)->getId() == id) {
            (*it)->setValue(value);
            cout << YELLOW << "Account " << id << " value modified to " << value << RESET << endl;
            return;
        } else {
            ++it;
        }
    }
    cerr << "Account " << id << " not found" << endl;
}

void Bank::deposit(Account* account, int value) {
	if (value <= 0) return;
	int fee = value * 0.05;
	int netDeposit = value - fee;
    account->addMoney(netDeposit);
	cout << YELLOW << "Bank received " << fee << " customer add " << netDeposit << RESET << endl;
	_liquidity += fee;
}

void Bank::withdraw(Account* account, int value) {
	if (value <= 0) return;
	if (account->getValue() < value) return;
    account->deleteMoney(value);
}

bool Bank::loanToAccount(int id, int value) {
    if (value <= 0) {
		cerr << "Can't loan negative value" << endl;
		return false;
	}

    if (_liquidity < value) {
        cerr << "Insufficient bank liquidity" << endl;
        return false;
    }

    for (vector<Account*>::iterator it = _clientAccounts.begin(); it != _clientAccounts.end(); it++) {
        if ((*it)->getId() == id) {
            (*it)->addMoney(value);
            _liquidity -= value;

            cout << "Loan of " << value << " granted to account " << id << endl;;
            return true;
        }
    }

    cerr << "Account " << id << " not found" << endl;
    return false;
}

ostream& operator<<(ostream& os, const Bank& bank) {
    os << "Bank Information:\n";
    os << "Liquidity: " << bank._liquidity << "\n";

    if (bank._clientAccounts.empty()) {
        os << "No client accounts.\n";
    } else {
        for (vector<Account*>::const_iterator it = bank._clientAccounts.begin(); it != bank._clientAccounts.end(); ++it)
            os << (*it)->getId() << "\n";
    }

    return os;
}
