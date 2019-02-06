#include <iostream>
#include <vector>
#include "Account-Sec16-Chal.h"
#include "Savings_Account-Sec16-Chal.h"
#include "Checking_Account-Sec16-Chal.h"
#include "Trust_Account-Sec16-Chal.h"
#include "Account_Util-Sec16-Chal.h"

using namespace std;

int main()
{
	//Account frank{"Frank", 5000};         // should not compile
	//cout << frank << endl;

	Checking_Account frank{"Frank", 5000};
	cout << frank << endl;

	Account *trust = new Trust_Account("James");
	cout << *trust << endl;

	Account *p1 = new Checking_Account("Larry", 10000);
	Account *p2 = new Savings_Account("Moe", 1000);
	Account *p3 = new Trust_Account("Curly");

	std::vector<Account *> accounts{p1,p2,p3};

	display(accounts);
	deposit(accounts, 1000);
	withdraw(accounts, 2000);

	display(accounts);

	delete p1;
	delete p2;
	delete p3;

	return 0;
}