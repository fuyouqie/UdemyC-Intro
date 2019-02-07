#include <memory>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//when use count is 0, the memory on the heap is freed up
	shared_ptr<double> ptr1{new double{3.52}};
	shared_ptr<double> ptr2{ptr1};
	shared_ptr<double> ptr3{ptr2};

	cout << ptr1.use_count() << endl;
	cout << ptr2.use_count() << endl;

	ptr1.reset(); //does not free up heap memory since other pointers are referring to it

	cout << ptr1.use_count() << endl; //nullptr
	cout << ptr2.use_count() << endl;
	cout << ptr3.use_count() << endl;

	//work with vector
	vector<shared_ptr<double>> vec;
	shared_ptr<double> ptr4{new double{2.1213}};
	vec.push_back(ptr4); //copy is allowed with shared pointer
	for (const auto current : vec)
	{
		cout << *current << endl;
		cout << "Ptr4: " << ptr4.use_count() << endl; // copied 3 times
	}

	//A more efficient way to declare shared pointer - make_shared<>()
	shared_ptr<int> ptr5 = make_shared<int>(5);

	return 0;
}