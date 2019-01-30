#include "Student-cp.h"
#include <iostream>

using namespace std;

void displayPlayer(Student student)
{
	cout << "Displaying player: " << student.getName() << endl;
}

int main()
{
	/*
	{
		Student stu; //calls for default constructor
		Student alice(2313,"Alice");
	}//objects are created on stack and 2 destructors are called automatically 
	
	Student *tom = new Student(454, "Tom");
	//object created on heap

	delete tom; //destructor called;
	*/

	Student empty;
	displayPlayer(empty);// copy constructor called

	Student stu{empty}; //copy constructor called again

	return 0;
}