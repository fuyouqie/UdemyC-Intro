#include <iostream>

using namespace std;

int main()
{
	/*
		creating an int array of size 5 (int num[5];)
		compiler grabs a memory chunk of 20 bytes, for example from 1000 to 1020
		accessing num[1]: first accessing variable num, the memory location 1000
		then go 1 integer away from 1000 which adds 4 btyes
		it reaches 1004, therefore value stored at num[1] is retrived
		
		if accessing or modifing num[5] which is outside the array boundary
		it will modify the value stored at that memory location which may cause the program to crash
		!there is no real, physical boundaries
	*/
	
	//ways to declare and initialise array
	int arrayOne[5]{1,5,-5,15,36};
	int arrayTwo[10]{3,5}; // first two elements 3, 5. 0 for the rest 8 elements
	int arrayThree[100]{0}; //all 0
	int arrayFour[]{2,3,4,5,6}; //length is figured out by compiler based on the initialiser{}
	cout << arrayOne[8] << endl;
	
	int testScores[5];
	//compiler arranges an array of size 5. The values inside is unpredictable because it's not initialised

	//int testScores[5]{};
	//initialises the array
	cout << testScores[0] << endl;
	cout << testScores[1] << endl;
	cout << testScores[2] << endl;
	cout << testScores[3] << endl;
	cout << testScores[4] << endl;

	return 0;
}