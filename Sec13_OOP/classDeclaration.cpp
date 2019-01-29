#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student
{
public:
	int id;
	string name;
	
	void sayHi()
	{
		cout << name << " says hi!" << endl;
	}
	bool matchv1(int theId);
};

bool Student::matchv1(int theId)
{
	return id == theId;
}

int maine()
{
	/*****************************
		Create object
	******************************/
	//create object on stack
	Student alice;
	Student bob;

	//create object on heap
	Student *tom = new Student();

	/*****************************
		Access
	******************************/
	//dot operator
		//object on stack
	alice.name = "Alice";
	alice.sayHi();

		//object on heap
	(*tom).name = "Tom";
	(*tom).sayHi();

	//member of pointer/arrow operator to access object on heap
	tom->sayHi();
	

	return 0;
}