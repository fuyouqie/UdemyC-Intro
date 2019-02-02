#include <iostream>

using namespace std;

int main()
{
	enum Direction{LEFT,RIGHT,UP,DOWN};
	Direction d1{LEFT};

	cout << d1 << endl;
	return 0;
}