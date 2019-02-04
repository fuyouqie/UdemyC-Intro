#include "Checking_Account-Sec15-Chal.h"

using namespace std;

Checking_Account::Checking_Account(string name, double balance)
	:Account(name, balance)
{
}

Checking_Account::~Checking_Account()
{
}

bool Checking_Account::withdraw(double amount)
{
	amount += withdraw_fee;
	return Account::withdraw(amount);
}

ostream &operator<<(ostream &os, Checking_Account &check_acc)
{
	os << "Checking account: " << check_acc.name;
	os << ". Balance: " << check_acc.balance;
	os << ". Withdrawl fee: " << check_acc.withdraw_fee;
	return os;
}
