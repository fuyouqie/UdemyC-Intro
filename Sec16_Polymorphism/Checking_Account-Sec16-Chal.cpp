#include "Checking_Account-Sec16-Chal.h"

using namespace std;

Checking_Account::Checking_Account(string name, double balance)
	:Account(name, balance)
{
}

bool Checking_Account::withdraw(double amount)
{
	amount += withdraw_fee;
	return Account::withdraw(amount);
}

bool Checking_Account::deposit(double amount)
{
	return Account::deposit(amount);
}

void Checking_Account::print(ostream &os)
{
	os << "Checking account: " << name;
	os << ". Balance: " << balance;
	os << ". Withdrawl fee: " << withdraw_fee;
}
