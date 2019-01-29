/*
	primitive types
		char
			char : at least 8 bits(1 byte)
			char16_t : at least 16 bits
			char32_t : at least 32 bits
			wchar_t : largest available character set
		int
			(unsigned)short : at least 16 bits
			(unsigned)int : at least 16 bits
			(unsigned)long : at least 32 bits
			(unsigned)long long : at least 64 bits
		float
			float : 7 decimal places
			double : 15 decimal places
			long double : 19 decimal places
		boolean 
			0 is false
			non-zero is true

*/

#include <iostream>

using namespace std;

int mainb()
{
	/*************************
		Integers
	**************************/
	
	//long people{7'600'000'000};
	//throws error

	long long peole{7'600'000'000};
	//no error with list initialization syntax

	//long people = 7'600'000'000;
	//no error when compiling but causes a overflow when executing
	

	/*************************
		Floating point
	**************************/

	long double largeNum{3.543e130};

	/*************************
		Boolean
	**************************/

	bool isGood{true};
	bool isDone{false};

	cout << isGood << endl;
	//prints out 1 for true
	cout << isDone << endl;
	//prints out 0 for false

	return 0;
}