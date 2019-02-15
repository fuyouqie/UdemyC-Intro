/*
	std::map
	std::multimap
	std::unordered_map
	std::unordered_multimap
*/

/*
	@std::map
	elements are stored in key,value pair (std::pair objects)
	ordered by key
	no duplicates of key
	direct access with key
	no front of back
*/

#include <map>
#include <iostream>
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

	bool operator<(const Player &player) const
	{
		return this->level < player.get_level();
	}
};

std::ostream &operator<<(std::ostream &os, const Player &player)
{
	os << "Player ID: " << player.id << ". Name: " << player.name << ". Level: " << player.level;
	return os;
}

template<typename T1, typename T2>
void display(std::map<T1,T2> &s)
{
	std::cout << "{ ";
	for (const auto &ele : s)
		std::cout << "{" << ele.first << "," << ele.second << "}" << " ";
	std::cout << "}" << std::endl;
}

int main()
{
	std::map<int, int> number_map{{1,2},{1,3},{2,2},{2,3}};
	display(number_map); //dispalys 1,2 pair, and 2,2 pair to avoid duplicates of keys

	number_map = {{1,1},{2,1},{3,2},{4,2}};
	display(number_map); //displays all elements, since no duplicates of keys

	//insert - make pair
	number_map.insert(std::make_pair(100, 100));

	//insert pair object
	std::pair<int, int> pair1 = {200,200};
	number_map.insert(pair1);

	display(number_map);

	//[] operator to insert&update element
	number_map[300] = 300; //insert 300,300 since key 300 does not exist
	display(number_map);

	number_map[300] = 301; // update pair 300,300 to 300,301, since key 300 exists
	display(number_map);

	//.at()	method throws exception if key not found
	//number_map.at(400) = 300;
	//display(number_map);

	//erase element
	number_map.erase(300);
	display(number_map);

	auto it = number_map.find(200);
	if (it != number_map.end())
		number_map.erase(it);
	display(number_map);

	//count() to check if a key pair exists
	if (number_map.count(100) == 1)
		std::cout << "100 exists" << std::endl;

	return 0;
}