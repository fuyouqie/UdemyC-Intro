#include "Savings_Account-Sec16-Chal.h"

using namespace std;

Savings_Account::Savings_Account(string name, double balance, double interest_rate)
	:Account(name, balance), interest_rate{interest_rate}
{
}

bool Savings_Account::deposit(double amount)
{
	amount += amount * interest_rate;
	return Account::deposit(amount);
}

bool Savings_Account::withdraw(double amount)
{
	return Account::withdraw(amount);
}

void Savings_Account::print(ostream &os)
{
	os << "Savings account: " << name;
	os << ". Balance: " << balance;
	os << ". Interest rate: " << interest_rate;
}