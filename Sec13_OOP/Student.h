#pragma once

#include <string>

class Student
{
private:
	int id;
	std::string name;

public:
	Student(int id = 0, std::string name = "None");
	~Student();

	void sayHi();
	void setName(std::string name);
	bool match(int id);
};

