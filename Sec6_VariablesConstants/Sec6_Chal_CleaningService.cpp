#include <iostream>

using namespace std;

int main()
{
	const int PRICE_SMALL{25};
	const int PRICE_LARGE{35};
	const float TAX_RATE{0.06f};
	const int VALID_PERIOD{30};
	
	cout << "Hello, Welcome to Frank's Carpet Cleaning Service" << endl;
	cout << endl;
	
	int numOfSmallRooms{0};
	int numOfLargeRooms{0};

	cout << "How many small rooms would you like to cleaned? ";
	cin >> numOfSmallRooms;
	
	cout << "How many large rooms would you like to cleaned? ";
	cin >> numOfLargeRooms;
	cout << endl;

	int totalRoomCost{numOfSmallRooms * PRICE_SMALL + numOfLargeRooms * PRICE_LARGE};
	float tax{totalRoomCost * TAX_RATE};

	cout << "Estimate for carpet cleaning service" << endl;
	cout << "Number of small rooms: " << numOfSmallRooms << endl;
	cout << "Number of large rooms: " << numOfLargeRooms << endl;
	cout << "Price per small room: $" << PRICE_SMALL << endl;
	cout << "Price per large room: $" << PRICE_LARGE << endl;
	cout << "Cost: $" << totalRoomCost << endl;
	cout << "Tax: $" << tax << endl;
	cout << "============================" << endl;
	
	cout << "Total estimate: $" << totalRoomCost + tax << endl;
	cout << "This estimate is valid for " << VALID_PERIOD << " days" << endl;

	return 0;
}