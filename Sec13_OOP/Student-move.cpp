#include "Student-move.h"
#include <iostream>

using namespace std;

void Student::sayHi()
{
	cout << "Hi there, I'm " << *name << endl;
}

bool Student::match(int id)
{
	return *this->id == id;
}

//constructor
Student::Student(int id, string name)
{
	this->id = new int;
	*this->id = id;
	this->name = new string;
	*this->name = name;
	cout << "Alternate constructor called" << endl;
}

//destructor
Student::~Student()
{
	delete id;
	delete name;
	cout << "Student destroyed" << endl;
}

//copy constructor
Student::Student(const Student &source)
	:Student(*source.id,*source.name)
{
	cout << "Copy constructor called - Deep Copy" << endl;
}

//move constructor
Student::Student(Student &&source) noexcept //&& r-value reference
	:id{source.id}, name{source.name}
{
	source.id = nullptr;
	source.name = nullptr;
	cout << "Move constructor called" << endl;
}

string Student::getName() const
{
	return *name;
}

void Student::setName(string name)
{
	*this->name = name;
}