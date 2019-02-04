#pragma once
#include "Account-overriding.h"

class Savings_Account : public Account
{
	friend std::ostream &operator<<(std::ostream &os, const Savings_Account &sav_acc);

protected:
	double interest_rate;

public:
	Savings_Account();
	Savings_Account(double balance, double interest_rate);
	~Savings_Account();
	void deposit(double amount);
};

