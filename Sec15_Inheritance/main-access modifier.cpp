#include <iostream>

using namespace std;

class Base
{
public:
	int a{0};

protected:
	int b{0};

private:
	int c{0};
};


class Derived : public Base
{
public:
	void access_base_fields()
	{
		a = 100;
		b = 200;
		//c = 300; // error
	}
};

int main()
{
	cout << "Base object" << endl;
	Base base{};
	base.a = 100;
	//base.b = 200; //error
	//base.c = 300; //error

	cout << "Base object" << endl;
	Derived derived{};
	derived.a = 100;
	//derived.b = 200; //error
	//derived.c = 300; //error

	return 0;
}