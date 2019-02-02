#include <iostream>

using namespace std;

double increase(double base, double rate = 0.03);

int main()
{
	cout << increase(5);
	return 0;
}

double increase(double base, double rate)
{
	return base * (1 + rate);
}
