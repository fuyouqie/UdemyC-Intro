//romeoandjuliet.txt

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	//open file
	ifstream in;
	in.open("romeoandjuliet.txt");
	if (!in)
	{
		cout << "Cannot open file" << endl;
		return 1;
	}

	//variables
	size_t total_text{0};
	string text_to_search;
	size_t times_found{0};

	//read the text to search
	cout << "Enter the text to search: ";
	cin >> text_to_search;

	//search
	while (!in.eof())
	{
		string temp_text;
		in >> temp_text;

		size_t found = temp_text.find(text_to_search);
		if (found != string::npos)
			times_found++;
		total_text++;
	}

	cout << total_text << " words were searched" << endl;
	cout << "The substring " << text_to_search << " was found " << times_found << " times" << endl;

	in.close();

	return 0;
}