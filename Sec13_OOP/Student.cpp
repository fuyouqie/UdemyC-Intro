#include "Student.h"
#include <iostream>

void Student::sayHi()
{
	std::cout << "Hi there, I'm " << name << std::endl;
}

bool Student::match(int id)
{
	return Student::id == id;
}

void Student::setName(std::string name)
{
	Student::name = name;
}

Student::Student()
	:Student{0,"None"} // initialization list initialises the data before creating object
{
	std::cout << "Default constructor called" << std::endl;
}

Student::Student(int id, std::string name)
	: Student::id{id}, Student::name{name}
{
	std::cout << "Alternate constructor called" << std::endl;
}

Student::~Student()
{
	std::cout << "Student destroyed" << std::endl;
}