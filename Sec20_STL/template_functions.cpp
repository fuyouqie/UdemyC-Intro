#include <iostream>
#include <string>

using namespace std;

template<typename T>
T max(T a, T b)
{
	return a > b ? a : b;
}

struct Player
{
	string name;
	int level;
};

bool operator>(Player &lhs, Player &rhs)
{
	return lhs.level > rhs.level;
}

ostream &operator<<(ostream &os, Player &player)
{
	os << player.name << " at level " << player.level;
	return os;
}

ostream &operator<<(ostream &os, Player &&player)
{
	os << player.name << " at level " << player.level;
	return os;
}

int main()
{
	cout << max<int>(5, 10) << endl;
	cout << max(20.5, 10.8) << endl;

	Player p1{"P1", 12};
	Player p2{"P2", 15};
	cout << max(p1, p2) << endl;

	return 0;
}