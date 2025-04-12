#ifndef ACCOUNT_HPP
# define ACCOUNT_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

#include <iostream>
#include <set>
#include <stdexcept>

using namespace std;

class Account
{
	private:
		static set<int> used_ids;

		int _id;
		int _value;
		
		Account(int id, int value);
		//Bank a accès aux attributs privés de la classe Account
		void addMoney(int value);
		void deleteMoney(int value);
		void setValue(int value);
		friend class Bank;

	public:
		~Account(void);
		int getId(void) const;
		int getValue(void) const;

		friend ostream& operator<<(ostream& os, const Account& account);
};

#endif