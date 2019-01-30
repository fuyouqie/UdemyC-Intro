#include "Student-move.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{

	//vector<Student> vec;
	//vec.push_back(Student{123, "Alice"});
	//vec.push_back(Student{456, "Bob"});
	//vec.push_back(Student{978, "Tom"});
	//vec.push_back(Student{834, "Tim"});

	const Student alice{123, "Alice"};

	//setName() is not a const method
	//alice.setName("aliceeeses");
	
	cout << alice.getName() << endl; //OK since getName() is const

	return 0;
}