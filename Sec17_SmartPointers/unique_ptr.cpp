/*
	Unique Pointer:
	1 - 1 relationship between the pointer and the object pointed to
	Cannot be copied or assigned
	Can be moved
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
	}

	void display()
	{
		cout << "Testing " << num << endl;
	}
};

int main()
{
	//automatically deleted when no longer needed
	unique_ptr<double> ptr1{new double{2.35}};
	cout << ptr1 << endl;
	cout << *ptr1 << endl;

	//get the raw pointer version to work with libraries that take raw pointers
	cout << ptr1.get() << endl;

	//set to nullptr
	ptr1.reset();

	//check if null pointer
	if (ptr1)
		cout << *ptr1 << endl;

	//make_unique<>() function
	unique_ptr<float> ptr2 = make_unique<float>(56.23f);

	//copy, assign not allowed
	//ptr2 = ptr1;

	//Move allowed (move ownership), ptr2 is nullptr now
	unique_ptr<float> ptr3;
	ptr3 = move(ptr2);

	//User-defined class and vector
	vector<unique_ptr<Test>> test_arr;
	test_arr.push_back(make_unique<Test>(5));
	test_arr.push_back(make_unique<Test>(3));
	test_arr.push_back(make_unique<Test>(6));

	//if not by reference, the elements are copied which is not allowed
	for (const auto &test : test_arr)
		(*test).display();


	return 0;
}