#include <iostream>

using namespace std;

class Base
{
public:
	void say_hi() const
	{
		cout << "Hello I am base" << endl;
	}
};

class Derived : public Base
{
public:
	void say_hi() const
	{
		cout << "Hello I am derived" << endl;
	}
};


void greeting(const Base &obj)
{
	obj.say_hi();
}

int main()
{
	Base b;
	Derived d;

	greeting(b);
	greeting(d);

	Base *ptr = new Derived();
	ptr->say_hi();

	return 0;
}