#pragma once

#include "Savings_Account-Sec15-Chal.h"
#include <string>

class Trust_Account : public Savings_Account
{
	friend std::ostream &operator<<(std::ostream &os, Trust_Account &sav_acc);

protected:
	static const size_t max_withdrawals{3};
	size_t num_withdrawals;

public:
	Trust_Account(std::string name = "Unnamed Trust Account", double balance = 0.0, double interest_rate = 0.0);
	~Trust_Account();

	bool deposit(double amount);
	bool withdraw(double amount);
};