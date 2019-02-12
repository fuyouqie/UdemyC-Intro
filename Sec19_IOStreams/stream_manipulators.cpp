#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// * -> default
int main()
{
	/*****************************
		Boolean
			boolalpha, *noboolalpha
	*****************************/
	cout << "========Boolean================================" << endl;

	cout << (1 == 2) << endl;  // 0 for false
	cout << (2 == 2) << endl;  // 1 for true

	//manipulator version
	cout << boolalpha;
	cout << (1 == 2) << endl;
	cout << (2 == 2) << endl;

	cout << noboolalpha;
	cout << (1 == 2) << endl;
	cout << (2 == 2) << endl;

	//method version
	cout.setf(ios::boolalpha);
	cout << (1 == 2) << endl;
	cout << (2 == 2) << endl;

	//reset to default for boolalpha flag
	cout << resetiosflags(ios::boolalpha);
	cout << (1 == 2) << endl;
	cout << (2 == 2) << endl;


	/*****************************
		Integer
			*dec, oct, hex
			showbase, *noshowbase
			uppercase, *nouppercase
			showpos, *noshowpos
	*****************************/
	cout << "========Integer================================" << endl;

	int num{9979678};
	cout << showbase << uppercase;

	cout << dec;
	cout << num << endl; //no prefix for dec
	cout << oct;
	cout << num << endl; //prefix 0 for oct
	cout << hex;
	cout << num << endl; //prefix 0x for hex

	//+ shown before positive integers
	cout << dec;
	int pos_num{100};
	int neg_num{-50};
	cout << showpos;
	cout << pos_num << endl;
	cout << neg_num << endl;

	cout << noshowbase << nouppercase << noshowpos;
	/*****************************
		Floating points
			Precision: 6 by default, with rounding
						setprecision(5) to set precision to 5
			fixed
			scientific
			uppercase, *nouppercase
			showpos, *noshowpos
			showpoint, *noshowpoint //trailing zeros
	*****************************/
	cout << "========Floating points================================" << endl;

	double num1{12345.798987};
	double num2{123.45};
	double num3{123};

	cout << "---Default---" << endl;
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;

	cout << "---Precision 4---" << endl;
	cout << setprecision(4);
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;

	cout << "---Precision 3 && fixed---" << endl;
	cout << setprecision(3) << fixed;
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;

	cout << "---Precision 6 && scientific---" << endl;
	cout.unsetf(ios::fixed);
	cout << setprecision(6) << scientific;
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;

	//set to default
	cout << defaultfloat;


	/*****************************
		Align, Fill
			field width: a block with specific length
				setw(), no width set by default

			justification: left, *right
			!!The justification will presist until changed,
			however it only works together with setw()

			field fill: fill the empty spaces in a field
				setfill()
				only works if there's a field associated
	*****************************/
	cout << "========Align Fill================================" << endl;

	string str{"HELLO"};
	double data{125.675};

	cout << "---Default---" << endl;
	cout << str << data << endl;

	cout << "---setw(15)---" << endl;
	cout << "123451234512345" << endl;
	cout << setw(15);
	cout << str << data << endl;

	cout << "---setw(15) && left justified---" << endl;
	cout << "123451234512345" << endl;
	cout << setw(15) << left;
	cout << str << data << endl;

	cout << "---setw(15) && left justified && setfill('*')---" << endl;
	cout << "123451234512345" << endl;
	cout << setw(15) << setfill('*');
	cout << str << data << endl;

	return 0;
}