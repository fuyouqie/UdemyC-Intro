#include "Student-move.h"
#include <iostream>

using namespace std;

void Student::sayHi()
{
	cout << "Hi there, I'm " << *name << endl;
}

bool Student::match(int id)
{
	return *(Student::id) == id;
}

//constructor
Student::Student(int id, string name)
{
	Student::id = new int;
	*(Student::id) = id;
	Student::name = new string;
	*(Student::name) = name;
	cout << "Alternate constructor called" << endl;
}

//destructor
Student::~Student()
{
	delete Student::id;
	delete Student::name;
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

string Student::getName()
{
	return *name;
}

void Student::setName(string name)
{
	*(Student::name) = name;
}