#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	ifstream in{"romeoandjuliet.txt"};
	ofstream out{"romeoandjuliet_out.txt"};

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

	string line;
	size_t line_count{1};

	out << left;
	while (getline(in, line))
	{
		string line_num = line == "" ? "" : to_string(line_count++) + ".";
		out << setw(12) << line_num << line << endl;
	}

	cout << "Copy completed" << endl;

	in.close();
	out.close();

	return 0;
}