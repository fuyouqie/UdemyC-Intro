#include <iostream>
#include <vector>

using namespace std;

int maini()
{
	//ways to declare vectors
	//declare without initialising
	vector<int> vectorOne;

	//declare and initialise with constructor initialiser
	vector<int> vectorTwo(5);//5 integers will be automatically set to 0
	vector<double> vectorThree(15, 1.563);//length 15, all set to 1.563

	//declare and initialise with initialiser list
	vector<int> vectorFour{'a','e','i','o','u'};


	//ways to access vector elements
	//array syntax
	//without bound checking
	cout << vectorFour[2] << endl;//accessing the third element

	//vector syntax
	//perform bound checking, throws exception if out of bound
	cout << vectorFour.at(2) << endl;
	//cout << vectorFour.at(8) << endl;

	
	//ways to modify vector elements
	//push_back adds an element at the end of the vector
	vectorFour.push_back('h');

	//2D vector
	vector<vector<int>> vector2D
	{
		{1,2,3,4},
		{2,2,3,1},
		{4,2,1,4},
		{1,1,3,1},
	};

	return 0;
}