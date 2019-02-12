#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream in;
	in.open("text_3.txt");

	if (!in)
	{
		cout << "Cannot open file" << endl;
		return 1;
	}

	string line;
	while (getline(in, line))
		cout << line << endl;
	
	in.close();

	return 0;
}