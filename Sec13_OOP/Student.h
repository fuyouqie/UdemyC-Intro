#pragma once

#include <string>

class Student
{
private:
	int id;
	std::string name;

public:
	Student();
	Student(int id, std::string name);
	~Student();
	void sayHi();
	void setName(std::string name);
	bool match(int id);
};

