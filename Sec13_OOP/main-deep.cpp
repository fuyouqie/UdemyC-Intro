#include "Student-deep.h"
#include <iostream>

using namespace std;

void displayPlayer(Student student)
{
	cout << "Displaying player: " << student.getName() << endl;
}

int main()
{
	Student alice(123,"Alice");

	displayPlayer(alice);

	return 0;
}