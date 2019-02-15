#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

class Player
{
	friend std::ostream &operator<<(std::ostream &os, const Player &player);

private:
	size_t id;
	std::string name;
	size_t level;

public:
	Player(size_t id, std::string name, size_t level)
		:id{id}, name{name}, level{level}
	{
	}

	bool operator==(const Player &rhs) const
	{
		return this->id == rhs.id && this->name == rhs.name && this->level == rhs.level;
	}

	bool operator>=(const Player &rhs) const
	{
		return this->level >= rhs.level;
	}

	size_t get_level() const
	{
		return level;
	}
	
	void set_level(size_t level)
	{
		this->level = level;
	}
};

std::ostream &operator<<(std::ostream &os, const Player &player)
{
	os << "Player ID: " << player.id << ". Name: " << player.name << ". Level: " << player.level;
	return os;
}

//based on the overloaded == operator defiend in Player class
void find(std::vector<Player> &players)
{
	auto location = std::find(players.begin(), players.end(), Player{96,"Elise",5});

	if (location != players.end())
		std::cout << *location << std::endl;
	else
		std::cout << "Player not found" << std::endl;
}

//based on the algorithm passed in
void find_if(std::vector<Player> &players)
{
	//finds the first occurance of Player > level 10
	size_t level{10};
	auto algo = [level](const Player &player) { return player.get_level() > level; };
	auto location = std::find_if(players.begin(), players.end(), algo);

	if (location != players.end())
		std::cout << *location << std::endl;
	else
		std::cout << "Player not found" << std::endl;
}

void count_if(std::vector<Player> &players)
{
	//simple example
	std::vector<int> vec{1,2,3,4,5,1,2,1};
	int num1 = std::count(vec.begin(), vec.end(), 1);
	std::cout << num1 << " occurrences found" << std::endl;
	
	//count number of players > level 5 (5 players)
	size_t level{5};
	auto algo = [level](const Player &player) { return player.get_level() > level; };
	int num2 = std::count_if(players.begin(), players.end(), algo);
	std::cout << num2 << std::endl;
}

void replace(std::vector<Player> players)
{
	//simple example
	std::vector<int> vec{1,2,3,4,5,1,2,1};
	for (auto i : vec)
		std::cout << i << " ";
	std::cout << std::endl;

	std::replace(vec.begin(), vec.end(), 1, 100);//replace 1 with 100
	for (auto i : vec)
		std::cout << i << " ";
	std::cout << std::endl;

	//replace player
	for (auto &player : players)
		std::cout << player << std::endl;
	std::cout << std::endl;

	std::replace(players.begin(), players.end(), Player{43,"Bob",2}, Player{44,"Bobee",25});
	for (auto &player : players)
		std::cout << player << std::endl;
	std::cout << std::endl;
}

void replace_if(std::vector<Player> players)
{
	//std::replace_if() replace all level 6 player with an "empty" player
	size_t origin_lvl{6};

	auto origin = [origin_lvl](const Player &player)
	{
		return player.get_level() == origin_lvl;
	};

	std::replace_if(players.begin(), players.end(), origin, Player{0,"Unknown",0});
	for (auto &player : players)
		std::cout << player << std::endl;
	std::cout << std::endl;

	//level up all 0-level players to level 99
	origin_lvl = 0;
	size_t target_lvl{99};

	auto algo = [origin_lvl, target_lvl](Player &player)
	{
		if (player.get_level() == origin_lvl)
			player.set_level(target_lvl);
	};

	std::for_each(players.begin(), players.end(), algo);
	for (auto &player : players)
		std::cout << player << std::endl;
}

void all_of(std::vector<Player> players)
{
	size_t max{99};
	auto algo = [max](Player &player)
	{
		return player.get_level() < 99;
	};
	
	if (std::all_of(players.begin(), players.end(), algo))
	{
		std::cout << "All players are below level " << max << std::endl;
	}
	else
		std::cout << "Not all players are below level " << max << std::endl;

	players.at(3).set_level(99);
	if (std::all_of(players.begin(), players.end(), algo))
	{
		std::cout << "All players are below level " << max << std::endl;
	}
	else
		std::cout << "Not all players are below level " << max << std::endl;
}

void transform()
{
	std::string str1{"This is a test"};
	std::cout << "Before transform: " << str1 << std::endl;
	std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper); //::toupper means global scope toupper
	std::cout << "After transform: " << str1 << std::endl;
}

int main()
{
	std::vector<Player> players
	{
		{2,"Alice",0},
		{43,"Bob",2},
		{15,"Cate",6},
		{23,"Danial",7},
		{96,"Alice",5},
		{45,"Frank",6},
		{15,"Alice",6},
		{27,"Helen",57}
	};

	//find(players);
	//find_if(players);
	//count_if(players);
	//replace(players);
	//replace_if(players);
	//all_of(players);
	transform();

	return 0;
}