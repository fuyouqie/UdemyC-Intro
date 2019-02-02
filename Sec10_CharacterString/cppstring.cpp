/*
	C++ strings are also stored contiguously in memory like C-style strings
	however c++ strings are dynamic in size
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	/********************************
		Initialisation
	*********************************/
	
	//C++ strings are automatically initialised, s1 is initialised to empty
	string s1;

	//initialiser list style
	string s2{"Hello"};

	
	string s3{s2};

	//"Hell"
	string s4{"Hello",4};

	//initialise from s3, start at index 0, grab 2 characters ('H','e')
	string s5{s3,0,2};

	//constructor syntax to initialise. three characters. "AAA"
	string s6(3, 'A');

	/********************************
		Assignment
	*********************************/

	//basic
	string str;
	str = "HAHAH";

	//concatenation
	string str1{"Hello"};
	string str2{"World"};
	string msg;
	//combination of c++ style string and c-style string is ok
	msg = str1 + " " + str2 + "!";
	
	//two C-style literals cannot be concatenated with +
	//msg = "Hello" + "World!";

	/********************************
		Access
	*********************************/

	//subscript operator[] or at() method
	string str3{"Hello"};
	cout << str3[0] << endl;
	cout << str3.at(0) << endl;

	//display characters
	for (char c : str3)
		cout << c << endl;

	//get length of string
	cout << "Length of " << str3 << " is " << str3.length() << endl;

	/********************************
		Comparison
	*********************************/

	/*
		Can compare:
			two c++ string objects
			c++ string object and C-style string variable
			c++ string object and C-style string literal
		using operators:
			==, !=, >, >=, <, <=
			A < B < Z < a < b < z (based on ASCII table)
	*/
	string st1{"apple"};
	string st2{"Apple"};
	cout << boolalpha;
	cout << (st1 == st2) << endl;
	cout << (st1 == "apple") << endl;
	cout << noboolalpha;

	/********************************
		Substrings
	*********************************/

	//extract substrings
	string intro{"Hello World!"};
	//starting at index 0, including 4 characters. If less than 4 remaining, all remainders are taken
	cout << intro.substr(0, 4) << endl;

	//search strings using find()
	//object.find(stringToSearch) returns the index of the first character
	string warning{"Do not reply!"};
	cout << warning.find("Do") << endl;// 0
	cout << warning.find('e') << endl;// 8
	size_t found = warning.find("Does");
	if (found == string::npos)
		cout << "Not found" << endl;
	
	//erase(start_index, length), clear()
	string sayHi{"Hi, I'am Alice"};
	cout << sayHi.erase(9, 5) << endl;
	cout << sayHi << endl;
	sayHi.clear();
	cout << sayHi << endl;

	/********************************
		Read input with C++ string
	*********************************/

	//extraction operator >> stops when it sees whitespace
	//string text1;
	//cin >> text1;
	//giving input hello world, only hellow will be accepted

	string text2;
	getline(cin, text2);//reads the whole line (up to \n)

	string text3;
	getline(cin, text3, 'S'); //S is the delimiter. Entering "hello worldS another text", "hello world" is accepted

	return 0;
}