#include <iostream>
#include <vector>

using namespace std;

class Base
{
public:
	virtual void say_hi() const
	{
		cout << "Hello I am base" << endl;
	}

	virtual ~Base()
	{
		cout << "Base destructor" << endl;
	}
};

class Derived : public Base
{
public:
	virtual void say_hi() const
	{
		cout << "Hello I am derived" << endl;
	}

	virtual ~Derived()
	{
		cout << "Derived destructor" << endl;
	}
};


void greeting(const Base &obj)
{
	obj.say_hi();
}

int main()
{
	Base* p1 = new Base();
	Base* p2 = new Base();
	Derived* p3 = new Derived();
	Derived* p4 = new Derived();

	vector<Base*> bases;
	bases.push_back(p1);
	bases.push_back(p2);
	bases.push_back(p3);
	bases.push_back(p4);

	for (Base* current : bases)
		current->say_hi();

	delete p1;
	delete p2;
	delete p3;
	delete p4;

	return 0;
}