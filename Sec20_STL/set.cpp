#include <set>
#include <string>
#include <iostream>

/*
	Duplicate elements are not allowed in set
	std::set is ordered
	For custom defined class type, overloaded < operator is needed for ordering
*/

/*
	std::multi_set
		ordered
		allows duplicates
*/

/*
	std::unordered_set
		unordered
		cannot modify elements, only by erase and insert new one
*/

/*
	std::unordered_multiset
*/

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

template<typename T>
void display(std::set<T> &s)
{
	std::cout << "[ ";
	for (const auto &ele : s)
		std::cout << ele << " ";
	std::cout << "]" << std::endl;
}

void basic()
{
	std::set<int> numbers{1,2,3,4,5};
	std::set<std::string> strs
	{
		std::string{"Alice"},
		std::string{"Bob"},
		std::string{"Carel"}
	};

	display(numbers);
	display(strs);

	numbers = {2,2,1,3,5,0};
	strs = {std::string{"Carel"},std::string{"Alice"},std::string{"Bob"}};

	display(numbers);
	display(strs);

	//adding elements, no duplication, added in order
	numbers.insert(2);
	numbers.insert(1);
	numbers.insert(4);
	display(numbers);

	std::set<Player> players
	{
		{2,"Alice",54},
		{43,"Bob",2},
		{15,"Cate",6},
		{23,"Danial",7},
		{96,"Alice",5},
		{45,"Frank",6},
		{15,"Alice",6},
		{27,"Helen",57}
	};

	display(players);
	players.insert({5,"NEW",23});
	display(players);

	//delete elements
	auto it = players.find({5,"NEW",23});
	if (it != players.end())
		players.erase(it);
	display(players);

	//count() to test if a element is in the set(returns 0 or 1)
	std::cout << numbers.count(3) << std::endl;

	//return value of insert: std::pair<iterator,bool>
	//result1: iterator to the newly inserted 100, bool true
	auto result1 = numbers.insert(100);
	//result2: iterator to the duplicate 4, bool false
	auto result2 = numbers.insert(4);
	std::cout << std::boolalpha;

	std::cout << "Result1 first: " << *result1.first << ". Second: " << result1.second << std::endl;
	std::cout << "Result2 first: " << *result2.first << ". Second: " << result2.second << std::endl;


}

int main()
{
	basic();
	
	return 0;
}