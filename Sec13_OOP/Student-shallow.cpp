#include "Student-shallow.h"
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
	delete id;
	delete name;
	cout << "Student destroyed" << endl;
}

//copy constructor
Student::Student(const Student &source)
	:id{source.id}, name{source.name}
{
	cout << "Copy constructor called - shallow copy " <<  endl;
}

string Student::getName()
{
	return *name;
}

void Student::setName(string name)
{
	*(Student::name) = name;
}