#include <iostream>
#include <vector>

using namespace std;

int main()
{
	char option{};
	vector<int> numbers;

	do
	{
		cout << "\nP - Print Numbers" << endl;
		cout << "A - Add a number" << endl;
		cout << "M - Display mean of the numbers" << endl;
		cout << "S - Display the smallest number" << endl;
		cout << "L - Display the largest number " << endl;
		cout << "Q - Quit" << endl;

		cout << "\nPlease enter your choice: ";
		cin >> option;

		switch (option)
		{
			case 'P':
			case 'p':
				if (numbers.size() != 0)
				{
					cout << "[ ";
					for (auto number : numbers)
						cout << number << " ";
					cout << "]" << endl;
				}
				else
					cout << "[] - the list is empty" << endl;
				break;
			case 'A':
			case 'a':
				cout << "Enter an integer: ";
				int temp;
				cin >> temp;
				cout << temp << " is added to the list" << endl;
				numbers.push_back(temp);
				break;
			case 'M':
			case 'm':
				if (numbers.size() != 0)
				{
					int total{0};
					for (auto number : numbers)
						total += number;
					cout << "Average is " << static_cast<double>(total) / numbers.size() << endl;
				}
				else
					cout << "[] - the list is empty" << endl;
				break;
			case 'S':
			case 's':
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
				break;
			case 'L':
			case 'l':
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
				break;
			case 'Q':
			case 'q':
				cout << "GoodBye..." << endl;
				break;
			default:
				cout << "Option invalid" << endl;
		}
	}
	while (option != 'q' && option != 'Q');

	return 0;
}