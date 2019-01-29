#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> vector1;
	vector<int> vector2;

	vector1.push_back(10);
	vector1.push_back(20);
	cout << "vector1 index0: " << vector1.at(0) << endl;
	cout << "vector1 index1: " << vector1.at(1) << endl;
	cout << "Size of vector1: " << vector1.size() << endl;

	vector2.push_back(100);
	vector2.push_back(200);
	cout << "vector2 index0: " << vector2.at(0) << endl;
	cout << "vector2 index1: " << vector2.at(1) << endl;
	cout << "Size of vector2: " << vector2.size() << endl;

	vector<vector<int>> vector2D;
	vector2D.push_back(vector1);
	vector2D.push_back(vector2);

	cout << "Elements in vector2D" << endl;
	cout << vector2D.at(0).at(0) << endl;
	cout << vector2D.at(0).at(1) << endl;
	cout << vector2D.at(1).at(0) << endl;
	cout << vector2D.at(1).at(1) << endl;

	vector1.at(0) = 1000;
	cout << "After changing-----------" << endl;
	cout << "Elements in vector2D" << endl;
	cout << vector2D.at(0).at(0) << endl;
	cout << vector2D.at(0).at(1) << endl;
	cout << vector2D.at(1).at(0) << endl;
	cout << vector2D.at(1).at(1) << endl;

	cout << "Elements in vector1" << endl;
	cout << vector1.at(0) << endl;
	cout << vector1.at(1) << endl;

	/******************************
		with pointer
	*******************************/
	//vector<vector<int>*> vector2D;
	//vector2D.push_back(&vector1);
	//vector2D.push_back(&vector2);

	//cout << "Elements in vector2D" << endl;
	//cout << (*vector2D.at(0)).at(0) << endl;
	//cout << (*vector2D.at(0)).at(1) << endl;
	//cout << (*vector2D.at(1)).at(0) << endl;
	//cout << (*vector2D.at(1)).at(1) << endl;

	//vector1.at(0) = 1000;
	//cout << "After changing-----------" << endl;
	//cout << "Elements in vector2D" << endl;
	//cout << (*vector2D.at(0)).at(0) << endl;
	//cout << (*vector2D.at(0)).at(1) << endl;
	//cout << (*vector2D.at(1)).at(0) << endl;
	//cout << (*vector2D.at(1)).at(1) << endl;

	//cout << "Elements in vector1" << endl;
	//cout << vector1.at(0) << endl;
	//cout << vector1.at(1) << endl;


	return 0;
}