#include "Savings_Account-complex.h"

using namespace std;

Savings_Account::Savings_Account(string name, double balance, double interest_rate)
	:Account(name, balance), interest_rate{interest_rate}
{
}

Savings_Account::~Savings_Account()
{
}

bool Savings_Account::deposit(double amount)
{
	amount += amount * interest_rate;
	return Account::deposit(amount);
}

ostream &operator<<(ostream &os, const Savings_Account &sav_acc)
{
	os << "Savings account: " << sav_acc.name;
	os << ". Balance: " << sav_acc.balance;
	os << ". Interest rate: " << sav_acc.interest_rate;
	return os;
}