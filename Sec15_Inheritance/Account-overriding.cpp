#include "Account-overriding.h"

using namespace std;

Account::Account()
	:Account(0.0)
{
}

Account::Account(double balance)
	:balance{balance}
{
}

Account::~Account()
{
}

void Account::deposit(double amount)
{
	balance += amount;
}

void Account::withdraw(double amount)
{
	if (amount <= balance)
		balance -= amount;
	else
		cout << "Insufficient balance" << endl;
}

ostream &operator<<(ostream &os, const Account &acc)
{
	os << "Account balance: " << acc.balance;
	return os;
}
