#include "../includes/Bank.hpp"

Bank::Bank(void) : _liquidity(999)
{
	cout << "Bank has been created" << endl;
	return;
}

Bank::~Bank(void)
{
	for (size_t i = 0; i < _clientAccounts.size(); ++i)
		delete _clientAccounts[i];
	_clientAccounts.clear();
	cout << "Bank has been destroyed" << endl;
	return;
}

//Create account
Account* Bank::createAccount(int id, int value) {
	Account* newAccount = new Account(id, value);
	_clientAccounts.push_back(newAccount);
	return newAccount;
}

//Delete account
void Bank::deleteAccount(int id) {
    for (std::vector<Account*>::iterator it = _clientAccounts.begin(); it != _clientAccounts.end(); it++)
	{
        if ((*it)->getId() == id) {
            delete *it;
            it = _clientAccounts.erase(it); 
            cout << "Account deleted" << id << endl;
            return;
        } else {
            ++it;
        }
    }
    cerr << "Account " << id << " not found" << endl;
}

//Modify account
void Bank::deposit(Account* account, int value) {
	if (value <= 0) return;
	int fee = value * 0.05;
	int netDeposit = value - fee;
    account->addMoney(netDeposit);
	_liquidity += fee;
}

void Bank::withdraw(Account* account, int value) {
	if (value <= 0) return;
	if (account->getValue() < value) return;
    account->deleteMoney(value);
}

bool Bank::loanToAccount(int id, int value) {
    if (value <= 0) 
		return false;

    if (_liquidity < value) {
        cerr << "Insufficient bank liquidity" << endl;
        return false;
    }

    for (auto& account : _clientAccounts) {
        if (account->getId() == id) {
            account->addMoney(value);
            _liquidity -= value;

            cout << "Loan of " << value << " granted to account " << id << endl;;
            return true;
        }
    }

    cerr << "Account " << id << " not found" << endl;
    return false;
}

ostream& operator<<(ostream& os, const Bank& bank)
{
    os << "Bank Information:\n";
    os << "Liquidity: " << bank._liquidity << "\n";

    if (bank._clientAccounts.empty()) {
        os << "No client accounts.\n";
    } else {
        os << "Client Accounts:\n";
        for (const auto& clientAccount : bank._clientAccounts) {
            os << *clientAccount << "\n";
        }
    }

    return os;
}