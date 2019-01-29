/*
	reference is just a alias of a variable
	!!!!references cannot be null!!! and must be initialised on declaration
	a reference cannot be changed to refer to another value
*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

int mainq()
{
	vector<string> names{"A","B","C"};

	for (auto str : names)
		cout << str << endl;

	for (auto str : names)
		str = "HAHAH";
	for (auto str : names)
		cout << str << endl; //still A B C, str is the copy of each vector element and it's changing the copy

	for (auto &str : names)
		str = "HAHAH";
	for (auto str : names)
		cout << str << endl;// actually changes names vector

	for (auto const &str : names)
		cout << str << endl;// prevents any attempts to change the vector

	/*
		l-values
		have names and addressable
		modifiable if not constants
	*/
	int x{100};
	x = 200;



	/*
		r-values (not l-value)
		not addressable
		not modifiable
		a literal
		temporarty value
		on right-hand side of an assignment statement
	*/

	//100 = x;
	//100 is not a l-value here, it's a literal and not addressable
	x = x + 100;// (x+100) is a r-value

	/*
		l-value references
		r-value cannot be referenced since it's not addressable

		If a function expects a integer reference, it cannot accepts a literal like 5
		it can accept a l-value like a variable name
	*/
	int y{3};
	int &yRef1 = y;
	//int &ref2 = 100; //100 is a r-value

	int a = 3;
	int b = 5;

	//reference must be initialised on declaration
	//reference is not a variable stored in memory
	int &ref = a;
	ref = b; // results in a = 5 rather than "ref" referring to variable b

	return 0;
}