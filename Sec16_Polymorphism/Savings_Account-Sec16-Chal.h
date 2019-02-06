#pragma once
#include "Account-Sec16-Chal.h"

class Savings_Account : public Account
{
protected:
	double interest_rate;

public:
	Savings_Account(std::string name = "Unnamed Savings Account", double balance = 0.0, double interest_rate = 0.0);
	virtual ~Savings_Account() = default;

	virtual bool deposit(double amount) override;
	virtual bool withdraw(double amount) override;
	virtual void print(std::ostream &os) override;
};

