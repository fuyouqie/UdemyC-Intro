#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	//open file
	ifstream in;
	in.open("responses.txt");

	if (!in)
	{
		cout << "Cannot open file";
		return 1;
	}

	//declare variables
	string key;
	size_t total_score{0};
	size_t total_response{0};
	size_t general_width{25};

	//read key
	in >> key;

	//display - header
	cout << left;
	cout << setw(general_width) << "Student" << "Score" << endl;
	cout << "------------------------" << endl;

	while (!in.eof())
	{
		//declaring temp variables
		string temp_name;
		string temp_response;
		size_t temp_score{0};

		//reading input
		in >> temp_name;
		in >> temp_response;

		//calculate score and adds to total score
		for (size_t i{0}; i < key.size(); i++)
		{
			if (key.at(i) == temp_response.at(i))
				temp_score++;
		}
		total_score += temp_score;
		total_response++;

		//display - content
		cout << setw(general_width) << temp_name;
		cout << temp_score << "/" << key.size() << endl;
	}

	//display - average
	cout << "------------------------" << endl;
	cout << setw(general_width) << "Average Score";
	cout << static_cast<double>(total_score) / total_response << endl;

	//close file
	in.close();

	return 0;
}