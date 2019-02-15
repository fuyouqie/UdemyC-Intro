#include <set>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <iomanip>

std::string clean(std::string unit)
{
	std::string temp;
	for (const auto &c : unit)
	{
		if (std::isalpha(c))
			temp += c;
	}
	return temp;
}

void display_part1(std::map<std::string,int> &word_count)
{
	std::cout << std::left;
	std::cout << std::setw(15) << "Word" << "Count" << std::endl;
	std::cout << "-----------------------" << std::endl;

	for (const auto &pair : word_count)
		std::cout << std::setw(15) << pair.first << pair.second << std::endl;
}

void part1(std::ifstream &file)
{
	std::map<std::string, int> word_count;
	std::string line;
	
	while (std::getline(file, line))
	{
		std::istringstream strm{line};
		std::string unit;

		while (strm >> unit)
		{
			std::string word = clean(unit);
			if (word_count.count(word) == 0)
				word_count[word] = 1;
			else
				word_count[word]++;
		}
	}

	file.close();
	file.clear();
	file.seekg(0);

	display_part1(word_count);
}

void display_part2(std::map<std::string, std::set<int>> word_occurance)
{
	std::cout << std::left;
	std::cout << std::setw(15) << "Word" << "Occurance" << std::endl;
	std::cout << "-----------------------" << std::endl;

	for (const auto &pair : word_occurance)
	{
		std::cout << std::setw(15) << pair.first;

		std::cout << "[ ";
		for (const auto &line_num : pair.second)
			std::cout << line_num << " ";
		std::cout << "]";

		std::cout << std::endl;
	}
}

void part2(std::ifstream &file)
{
	std::map<std::string, std::set<int>> word_occurance;
	std::string line;
	int line_num{1};

	while (std::getline(file, line))
	{
		std::istringstream strm{line};
		std::string unit;

		while (strm >> unit)
		{
			std::string word = clean(unit);
			if (word_occurance.count(word) == 0)
				word_occurance[word] = std::set<int>{line_num};
			else
				word_occurance[word].insert(line_num);
		}

		line_num++;
	}

	file.close();
	display_part2(word_occurance);
}

int main()
{
	std::ifstream file_stream1{"words.txt"};
	std::ifstream file_stream2{"words.txt"};
	bool error{0};

	if (!file_stream1)
	{
		std::cout << "Error opening file";
		error = 1;
	}

	if (!file_stream1)
	{
		std::cout << "Error creating file";
		error = 1;
	}

	if (error)
		return 1;

	part1(file_stream1);
	std::cout << std::endl;
	part2(file_stream2);

	file_stream1.close();
	file_stream2.close();


	return 0;
}