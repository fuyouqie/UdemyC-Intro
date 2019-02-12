#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream in{"poem.txt"};
	ofstream out{"poem_out.txt"};

	bool error{0};
	if (!in)
	{
		cout << "Error opening file";
		error = 1;
	}

	if (!out)
	{
		cout << "Error creating file";
		error = 1;
	}

	if (error)
		return 1;

	//One line at a time
	string line;
	while (getline(in, line))
	{
		out << line << endl;
	}

	//One character at a time
	/*
	char c;
	while (in.get(c))
		out << put(c);
	*/

	cout << "File copied successful" << endl;

	in.close();
	out.close();

	return 0;
}