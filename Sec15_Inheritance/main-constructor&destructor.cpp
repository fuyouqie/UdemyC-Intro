#include <iostream>

using namespace std;

class Base
{
private:
	int base_field;

public:
	Base()
		:base_field{0}
	{
		cout << "Base default constructor called" << endl;
	}

	Base(int value)
		:base_field{value}
	{
		cout << "Base alternate constructor called" << endl;
	}

	~Base()
	{
		cout << "Base destructor called" << endl;
	}
};


class Derived : public Base
{
	//using Base::Base;
	/*
		inherits the non-special constructors,
		if Derived(int value) was not defined, calling Derived d(100)
		is actually calling Base(int value) since they match
		however it's not dealing with the derived_field
	*/

private:
	int derived_field;

public:
	Derived()
		:derived_field{0}
	{
		cout << "Derived default constructor called" << endl;
	}

	Derived(int value)
		:derived_field{value}
	{
		cout << "Derived alternate constructor called" << endl;
	}

	~Derived()
	{
		cout << "Derived destructor called" << endl;
	}
};

int main()
{
	//Base base;
	Derived d{1000};

	return 0;
}