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
		//Bank a acces aux attributs prives de la classe Account
		friend class Bank;

	public:
		~Account(void);
};

#endif