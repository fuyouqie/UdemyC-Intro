#include <iostream>

using namespace std;

void wayOne()
{
	const int CENT_PER_DOLLAR{100};
	const int CENT_PER_QUATER{25};
	const int CENT_PER_DIME{10};
	const int CENT_PER_NICKEL{5};
	const int CENT_PER_PENNY{1};

	int remainder{0};
	int cents;
	cout << "Enter an amount in cents: ";
	cin >> cents;

	int dollar = cents / CENT_PER_DOLLAR;
	remainder = cents - dollar * CENT_PER_DOLLAR;
	cout << "Dollor: " << dollar << endl;

	int quater = remainder / CENT_PER_QUATER;
	remainder -= quater * CENT_PER_QUATER;
	cout << "Quater: " << quater << endl;

	int dime = remainder / CENT_PER_DIME;
	remainder -= dime * CENT_PER_DIME;
	cout << "Dime: " << dime << endl;

	int nickel = remainder / CENT_PER_NICKEL;
	remainder -= nickel * CENT_PER_NICKEL;
	cout << "Nickel: " << nickel << endl;

	int penny = remainder / CENT_PER_PENNY;
	cout << "Penny: " << penny << endl;
}

void wayTwo()
{
	const int CENT_PER_DOLLAR{100};
	const int CENT_PER_QUATER{25};
	const int CENT_PER_DIME{10};
	const int CENT_PER_NICKEL{5};
	const int CENT_PER_PENNY{1};

	int cents;
	cout << "Enter an amount in cents: ";
	cin >> cents;

	int remainder{0};
	int dollar = cents / CENT_PER_DOLLAR;
	remainder = cents % CENT_PER_DOLLAR;
	cout << "Dollor: " << dollar << endl;

	int quater = remainder / CENT_PER_QUATER;
	remainder %= CENT_PER_QUATER;
	cout << "Quater: " << quater << endl;

	int dime = remainder / CENT_PER_DIME;
	remainder %= CENT_PER_DIME;
	cout << "Dime: " << dime << endl;

	int nickel = remainder / CENT_PER_NICKEL;
	remainder %= CENT_PER_NICKEL;
	cout << "Nickel: " << nickel << endl;

	int penny = remainder / CENT_PER_PENNY;
	cout << "Penny: " << penny << endl;
}

int main()
{
	wayTwo();
	return 0;
}