#ifndef ACCOUNT_HPP
# define ACCOUNT_HPP

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
		
		Account(int id, double value);
		//Bank a accès aux attributs privés de la classe Account
		void addMoney(int value);
		void deleteMoney(int value);
		friend class Bank;

	public:
		~Account(void);
		int getId(void) const;
		int getValue(void) const;
		void setValue(int value);

		friend ostream& operator<<(ostream& os, const Account& account);
};

#endif