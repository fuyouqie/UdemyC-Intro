#include <iostream>

using namespace std;

int main()
{
	//casting
	double num1 = 8 / 5;
	double num2 = 8.0 / 5;
	double num3 = static_cast<double>(8) / 5;
	double num4 = static_cast<double>(8 / 5);
	double num5 = (double)8 / 5;
	//old C-style casting, converts whatever to double
	//static casting does checking to make sure its convertable

	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;
	cout << num4 << endl;


	//equality
	cout << (100 == 200) << endl;
	//displays 0 for false
	cout << boolalpha; //display true/false rather than 0/1
	//cout << noboolalpha;
	cout << (100 == 200) << endl;
	return 0;
}