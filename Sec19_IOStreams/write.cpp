#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	/*
		By default, file will be create if not exist
			file will be truncated(overwritten) if exist
	*/

	/*
		truncated mode
			ofstream out{"output.txt"};
			ofstream out{"output.txt", std::ios::trunc};
		append mode
			ofstream out{"output.txt", std::ios::app};


	*/

	ofstream out{"output.txt", ios::app};
	if (!out)
	{
		cout << "Error creating file";
		return 1;
	}

	string line;
	cout << "Enter some text: " << endl;
	cin >> line;
	out << line << endl;


	out.close();
	
	return 0;
}