#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream in;
	in.open("text_1.txt");

	if (!in)
	{
		cout << "Cannot open file" << endl;
		return 1;
	}

	cout << "File opened" << endl;
	
	string str;
	int integer;
	double flo;

	//stops at a whitespace
	in >> integer >> str >> flo;
	cout << str << endl;
	cout << integer << endl;
	cout << flo << endl;

	in.close();

	return 0;
}