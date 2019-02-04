#pragma once
#include "Account-complex.h"

class Savings_Account : public Account
{
	friend std::ostream &operator<<(std::ostream &os, const Savings_Account &sav_acc);

protected:
	double interest_rate;

public:
	Savings_Account(std::string name = "Unnamed Savings Account", double balance = 0.0, double interest_rate = 0.0);
	~Savings_Account();

	bool deposit(double amount);
};

