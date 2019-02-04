#pragma once
#include <iostream>
#include <string>

class Account
{
	friend std::ostream &operator<<(std::ostream &os, const Account &account);

protected:
	std::string name;
	double balance;

public:
	Account(std::string name = "Unnamed Account", double balance = 0.0);
	~Account();

	bool deposit(double amount);
	bool withdraw(double amount);
};

