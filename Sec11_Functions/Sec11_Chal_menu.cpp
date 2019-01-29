#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

void menu();
void displayItems();
char readOption();
void printList(const vector<int> &numbers);
void add(vector<int> &numbers);
void mean(const vector<int> &numbers);
void smallest(const vector<int> &numbers);
void largest(const vector<int> &numbers);
void quitProgram();
void error();

int main()
{
	menu();
	return 0;
}

void menu()
{
	char option{};
	vector<int> numbers;

	do
	{
		displayItems();
		option = readOption();

		switch (option)
		{
			case 'P':
				printList(numbers);
				break;
			case 'A':
				add(numbers);
				break;
			case 'M':
				mean(numbers);
				break;
			case 'S':
				smallest(numbers);
				break;
			case 'L':
				largest(numbers);
				break;
			case 'Q':
				quitProgram();
				break;
			default:
				error();
		}
	}
	while (option != 'Q');
}

void displayItems()
{
	cout << "\nP - Print Numbers" << endl;
	cout << "A - Add a number" << endl;
	cout << "M - Display mean of the numbers" << endl;
	cout << "S - Display the smallest number" << endl;
	cout << "L - Display the largest number " << endl;
	cout << "Q - Quit" << endl;
}

char readOption()
{
	cout << "\nPlease enter your choice: ";
	char option{};
	cin >> option;
	return toupper(option);
}

void printList(const vector<int> &numbers)
{
	if (numbers.size() != 0)
	{
		cout << "[ ";
		for (auto number : numbers)
			cout << number << " ";
		cout << "]" << endl;
	}
	else
		cout << "[] - the list is empty" << endl;
}

void add(vector<int> &numbers)
{
	cout << "Enter an integer: ";
	int temp;
	cin >> temp;
	cout << temp << " is added to the list" << endl;
	numbers.push_back(temp);
}

void mean(const vector<int> &numbers)
{
	if (numbers.size() != 0)
	{
		int total{0};
		for (auto number : numbers)
			total += number;
		cout << "Average is " << static_cast<double>(total) / numbers.size() << endl;
	}
	else
		cout << "[] - the list is empty" << endl;
}

void smallest(const vector<int> &numbers)
{
	if (numbers.size() != 0)
	{
		int smallest = numbers.at(0);
		for (auto number : numbers)
		{
			if (number < smallest)
				smallest = number;
		}
		cout << "Smallest: " << smallest << endl;
	}
	else
		cout << "[] - the list is empty" << endl;
}

void largest(const vector<int> &numbers)
{
	if (numbers.size() != 0)
	{
		int largest = numbers.at(0);
		for (auto number : numbers)
		{
			if (number > largest)
				largest = number;
		}
		cout << "Largest: " << largest << endl;
	}
	else
		cout << "[] - the list is empty" << endl;
}

void quitProgram()
{
	cout << "GoodBye..." << endl;
}

void error()
{
	cout << "Option invalid" << endl;
}