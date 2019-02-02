#include <iostream>

using namespace std;

void mulTable()
{
	const int MAX{5};

	for (int row = 1; row <= MAX; row++)
	{
		for (int col = 1; col <= row; col++)
		{
			cout << row << " X " << col << " = " << row * col << " ";
		}
		cout << endl;
	}
}

int main()
{
	//for-each loop
	int nums[]{2,3,4,5,6};
	for (auto num : nums)
		cout << num << endl;

	for (auto num : {12.23,45.3})
		cout << num << endl;

	for (auto c : "Printing out characters")
		cout << c;

	return 0;
}