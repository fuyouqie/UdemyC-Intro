//A variable is an abstraction of memory location

#include <iostream>

using namespace std;

//global variable
int age{5};

int main()
{
	//local variable
	int age{10};

	//age is 10 in this case, the global variable age is shadowed
	cout << age << endl;

	return 0;
}