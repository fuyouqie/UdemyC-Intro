#pragma once
#include <iostream>
#include <string>
#include "Printable-Sec16-Chal.h"

class Account : public Printable
{
protected:
	std::string name;
	double balance;

public:
	Account(std::string name = "Unnamed Account", double balance = 0.0);
	virtual ~Account() = default;

	virtual bool deposit(double amount) = 0;
	virtual bool withdraw(double amount) = 0;
	virtual void print(std::ostream &os) override;
};

