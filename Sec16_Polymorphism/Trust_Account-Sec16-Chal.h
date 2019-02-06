#pragma once

#include "Savings_Account-Sec16-Chal.h"
#include <string>

class Trust_Account : public Savings_Account
{
protected:
	static const size_t max_withdrawals{3};
	size_t num_withdrawals;

public:
	Trust_Account(std::string name = "Unnamed Trust Account", double balance = 0.0, double interest_rate = 0.0);
	virtual ~Trust_Account() = default;

	virtual bool deposit(double amount) override;
	virtual bool withdraw(double amount) override;
	virtual void print(std::ostream &os) override;
};