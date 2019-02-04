/*
	Copy constructor, Move constructor, overloaded assignment operator
	are not inherited automatically from base class
*/


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

	/*
		Actually there's no need to write a copy constructor here
		since there's no raw-pointer attributes
	*/
	Base(const Base &source)
		:base_field{source.base_field}
	{
		cout << "Base copy constructor called" << endl;
	}

	Base(Base &&source)
		:base_field{source.base_field}
	{
		source.base_field = 0;
		cout << "Base move constructor" << endl;
	}

	Base &operator=(const Base &rhs)
	{
		cout << "Base copy assignment" << endl;
		if (this != &rhs)
			base_field = rhs.base_field;
		return *this;
	}

	Base &operator=(Base &&rhs)
	{
		cout << "Base move assginment" << endl;
		if (this != &rhs)
		{
			base_field = rhs.base_field;
			rhs.base_field = 0;
		}
		return *this;
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
		:Base(), derived_field{0}
	{
		cout << "Derived default constructor called" << endl;
	}

	Derived(int value)
		:Base(value), derived_field{value}
	{
		cout << "Derived alternate constructor called" << endl;
	}

	Derived(const Derived &source)
		:Base(source), derived_field{source.derived_field}
	{
		cout << "Derived copy constructor called" << endl;
	}

	Derived(Derived &&source)
		:Base(source), derived_field{source.derived_field}
	{
		source.derived_field = 0;
		cout << "Derived move constructor" << endl;
	}

	Derived &operator=(const Derived &rhs)
	{
		cout << "Derived copy assignment" << endl;
		if (this != &rhs)
		{
			Base::operator=(rhs);
			derived_field = rhs.derived_field;
		}
		return *this;
	}

	Derived &operator=(Derived &&rhs)
	{
		cout << "Derived move assignment" << endl;
		if (this != &rhs)
		{
			Base::operator=(move(rhs)); // fucking tricky
			derived_field = rhs.derived_field;
			rhs.derived_field = 0;
		}
		return *this;
	}

	~Derived()
	{
		cout << "Derived destructor called" << endl;
	}
};

int main()
{
	//overloaded constructor
	Derived d1(20);
	
	//copy constructor
	Derived d2(d1);

	//copy assignment
	d1 = d2;

	//overloaded constructor
	//move assignment
	Derived d3(100);
	d3 = Derived(200);

	return 0;
}