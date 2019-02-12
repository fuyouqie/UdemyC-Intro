#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	ifstream in;
	in.open("text_2.txt");
	if (!in)
	{
		cout << "File not opened";
		return 1;
	}

	size_t cust_id;
	string name;
	string gender;

	while (!in.eof())
	{
		in >> cust_id >> name >> gender;
		cout << left;
		cout << setw(10) << cust_id;
		cout << setw(10) << name;
		cout << setw(10) << gender;
		cout << endl;
	}

	in.close();

	return 0;
}