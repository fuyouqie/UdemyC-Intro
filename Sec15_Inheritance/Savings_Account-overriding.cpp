#include "Savings_Account-overriding.h"

using namespace std;

Savings_Account::Savings_Account()
	:Savings_Account(0.0, 0.0)
{
}

Savings_Account::Savings_Account(double balance, double interest_rate)
	:Account(balance), interest_rate{interest_rate}
{
}

Savings_Account::~Savings_Account()
{
}

void Savings_Account::deposit(double amount)
{
	amount += amount * interest_rate;
	Account::deposit(amount);
}

ostream &operator<<(ostream &os, const Savings_Account &sav_acc)
{
	os << "Savings account balance: " << sav_acc.balance << ". Interest rate: " << sav_acc.interest_rate;
	return os;
}