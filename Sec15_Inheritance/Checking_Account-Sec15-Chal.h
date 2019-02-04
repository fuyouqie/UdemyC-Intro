#pragma once

#include "Account-Sec15-Chal.h"
#include <string>

class Checking_Account : public Account
{
	friend std::ostream &operator<<(std::ostream &os, Checking_Account &check_acc);

protected:
	const double withdraw_fee{1.5};

public:
	Checking_Account(std::string name = "Unnamed Checking Accont", double balance = 0.0);
	~Checking_Account();

	bool withdraw(double amount);
};

