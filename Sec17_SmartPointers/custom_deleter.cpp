/*
	To use custom deleter, the pointer cannot be declared using make_....
*/

#include <memory>
#include <iostream>
#include <vector>

using namespace std;

class Test
{
private:
	int num;

public:
	Test(int num)
	{
		this->num = num;
		cout << "Constructor called" << endl;
	}

	~Test()
	{
		cout << "Destructor called" << endl;
	}

	void display()
	{
		cout << "Testing " << num << endl;
	}
};

void custom_deleter(Test *obj)
{
	cout << "Custom deleter called" << endl;
	delete obj;
}

int main()
{
	{
		/*
			Way One: Function
		*/
		unique_ptr<Test, decltype(&custom_deleter)> ptr1{new Test(5), &custom_deleter};

		shared_ptr<Test> ptr2{new Test(500), &custom_deleter};
	}

	{
		/*
			Way Two: Lambda
		*/
		shared_ptr<Test> ptr2{new Test(300),
			[](Test *obj)
		{
			cout << "Custom deleter called" << endl;
			delete obj;
		}
		};
	}

	return 0;
}