#include "Account-Sec15-Chal.h"

using namespace std;

Account::Account(string name, double balance)
	: name{name}, balance{balance}
{
}

Account::~Account()
{
}

bool Account::deposit(double amount)
{
	if (amount <= 0)
		return false;
	balance += amount;
	return true;
}

bool Account::withdraw(double amount)
{
	if (amount > balance)
		return false;
	balance -= amount;
	return true;
}

ostream &operator<<(ostream &os, const Account &acc)
{
	os << "Account: " << acc.name;
	os << ". Balance: " << acc.balance;
	return os;
}
