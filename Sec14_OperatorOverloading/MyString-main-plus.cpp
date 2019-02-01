#include <iostream>
#include "MyString-plus.h"
#include <vector>

using namespace std;

int main()
{
	/*
		By default the compiler will use the copy constructor to 
		make a copy and assign to left, no matter it's a l-value or r-value rhs

		However if it's a r-value rhs, it's better just move the rhs to left rather than copy
		therefore overloading move assignment comes in
		the constructor takes a r-value reference
	*/

	MyString a{"Hello"};                // Overloaded constructor
	a = MyString{"Hola"};              // Overloaded constructor then move assignment
	a = "Bonjour";                         // Overloaded constructor then move assignment


	MyString empty;                      // no-args constructor
	MyString larry("Larry");             // overloaded constructor
	MyString stooge{larry};            // copy constructor 
	MyString stooges;                   // no-args constructor

	empty = stooge;                     // copy assignment operator
												  // stooge is an l-value

	empty = "Funny";                    // move assignment operator
												  // "Funny" is an r-value

	empty.display();
	larry.display();
	stooge.display();
	empty.display();

	stooges = "Larry, Moe, and Curly";
	stooges.display();

	vector<MyString> stooges_vec;
	stooges_vec.push_back("Larry");                // Move constructor
	stooges_vec.push_back("Moe");                // Move constructor
	stooges_vec.push_back("Curly");              // Move constructor    

	cout << "=== Loop 1 ==================" << endl;
	for (const MyString &s : stooges_vec)
		s.display();

	cout << "=== Loop 2 ==================" << endl;
	for (MyString &s : stooges_vec)
		s = "Changed";                                      // move assignment

	cout << "=== Loop 3 ==================" << endl;
	for (const MyString &s : stooges_vec)
		s.display();

	return 0;
}