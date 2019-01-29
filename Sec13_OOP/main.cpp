#include "Student.h"

int main()
{
	{
		Student stu; //calls for default constructor
		Student alice(2313,"Alice");
	}//objects are created on stack and 2 destructors are called automatically 
	
	Student *tom = new Student(454, "Tom");
	//object created on heap

	delete tom; //destructor called;

	return 0;
}