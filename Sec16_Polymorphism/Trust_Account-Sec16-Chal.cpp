#include "Trust_Account-Sec16-Chal.h"

using namespace std;

Trust_Account::Trust_Account(string name, double balance, double interest_rate)
	:Savings_Account(name, balance, interest_rate), num_withdrawals{0}
{
}

bool Trust_Account::deposit(double amount)
{
	if (amount >= 5000)
		amount += 50;
	return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount)
{
	if (num_withdrawals >= max_withdrawals || amount >= balance * 0.2)
		return false;
	else
	{
		num_withdrawals++;
		return Savings_Account::withdraw(amount);
	}
}

void Trust_Account::print(ostream &os)
{
	os << "Trust account: " << name;
	os << ". Balance: " << balance;
	os << ". Interest rate: " << interest_rate;
}