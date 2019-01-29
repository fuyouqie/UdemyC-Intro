#include <iostream>

using namespace std;

void swapRef(int &a, int &b);
void swap(int a, int b);

//passing array : pass the address(ref)
//passing vector object, making a copy

int mainj()
{
	int a = 2, b = 4;
	cout << a << " " << b << endl;
	swapRef(a, b);
	cout << a << " " << b << endl;
	swap(a, b);
	cout << a << " " << b << endl;
	return 0;
}

void swapRef(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}