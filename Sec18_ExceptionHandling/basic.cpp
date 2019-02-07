#include <iostream>

using namespace std;

int main()
{
	double num1{0};
	double num2{0};
	double result{0};

	cout << "Enter number1: ";
	cin >> num1;

	cout << "Enter number2: ";
	cin >> num2;

	try
	{
		if (num2 == 0)
			throw 0;
		result = num1 / num2;
		cout << num1 << "/" << num2 << " is " << result << endl;
	}

	catch(int &ex)
	{
		cout << "Exception: " << ex << endl;
		cout << "Cannot divide, num2 is 0" << endl;
	}
	cout << "Proram ended" << endl;

	return 0;
}