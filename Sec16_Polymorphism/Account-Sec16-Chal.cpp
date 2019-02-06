#include "Account-Sec16-Chal.h"

using namespace std;

Account::Account(string name, double balance)
	: name{name}, balance{balance}
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

void Account::print(ostream &os)
{
	os << "Account: " << name;
	os << ". Balance: " << balance;
}