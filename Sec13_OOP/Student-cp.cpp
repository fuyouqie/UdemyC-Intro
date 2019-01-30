#include "Student-cp.h"
#include <iostream>

using namespace std;

void Student::sayHi()
{
	cout << "Hi there, I'm " << name << endl;
}

bool Student::match(int id)
{
	return Student::id == id;
}


Student::Student(int id, string name)
	:Student::id{id}, Student::name{name}
{

	cout << "Alternate constructor called" << endl;
}

//destructor
Student::~Student()
{
	cout << "Student destroyed" << endl;
}

//copy constructor
Student::Student(const Student &source)
	:id{source.id}, name{source.name}
  //:Student{source.id,sourece,name}  //delegating constructor
{
	cout << "Copy constructor: copied object name - " << source.name << endl;
}

string Student::getName()
{
	return name;
}

void Student::setName(string name)
{
	Student::name = name;
}