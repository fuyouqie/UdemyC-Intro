#include <iostream>

using namespace std;

double div_result(int num1, int num2)
{
	if (num2 == 0)
		throw 0;
	return static_cast<double>(num1) / num2;
}

int main()
{
	int num1{0};
	int num2{0};
	double result{0};

	cout << "Enter number1: ";
	cin >> num1;

	cout << "Enter number2: ";
	cin >> num2;

	try
	{
		result = div_result(num1, num2);
		cout << num1 << "/" << num2 << " is " << result << endl;
	}
	catch (int &ex)
	{
		cout << "Exception: " << ex << endl;
		cout << "Cannot divide, num2 is 0" << endl;
	}
	cout << "Proram ended" << endl;

	return 0;
}