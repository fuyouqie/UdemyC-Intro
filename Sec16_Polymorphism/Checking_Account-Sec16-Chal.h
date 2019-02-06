#pragma once

#include "Account-Sec16-Chal.h"
#include <string>

class Checking_Account : public Account
{
protected:
	const double withdraw_fee{1.5};

public:
	Checking_Account(std::string name = "Unnamed Checking Accont", double balance = 0.0);
	virtual ~Checking_Account() = default;

	virtual bool withdraw(double amount) override;
	virtual bool deposit(double amount)	override;
	virtual void print(std::ostream &os) override;
};