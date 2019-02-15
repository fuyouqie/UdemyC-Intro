#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>

/*
	vector.begin() gets the position of first element
	vector.end() gets the position of last element + 1
	dereference the iterator to get the element 
*/

void t1()
{
	std::vector<char> cs{'H','e','l','l','o'};
	auto it = cs.begin(); //std::vector<char>::iterator it
	std::cout << *it << std::endl;
	
	it += 2;
	std::cout << *it << std::endl;

	it += 2;
	std::cout << *it << std::endl;

	std::cout << *(cs.end()-1) << std::endl;

}

void t2()
{
	std::vector<double> nums{12.5,67.23,21.123,467.6,6.1};
	auto it = nums.begin();
	while (it != nums.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
}

void t3()
{
	std::vector<double> nums{12.5,67.23,21.123,467.6,6.1};
	auto it = nums.cbegin(); //const begin
	//std::vector<double>::const_iterator it = nums.begin();
	while (it != nums.cend())
	{
		//*it = 23.3;
		it++;
	}

}

void t4()
{
	//reverse
	std::cout << "Reverse vector" << std::endl;
	std::vector<int> nums{1,2,3,4,5};
	auto it1 = nums.rbegin();
	while (it1 != nums.rend())
	{
		std::cout << *it1 << std::endl;
		it1++;
	}

	//const reverse list
	std::cout << "\nconst reverse list" << std::endl;
	std::list<std::string> strs{std::string{"Alice"},std::string{"Bob"},std::string{"Tom"}};
	auto it2 = strs.crbegin();
	while (it2 != strs.crend())
	{
		std::cout << *it2 << std::endl;
		it2++;
	}

	//map
	std::cout << "\nmap" << std::endl;
	std::map<std::size_t,std::string> students{{1,"Alice"},{2,"Bob"},{3,"Tom"}};
	auto it3 = students.begin();
	while (it3 != students.end())
	{
		std::cout << it3->first << "," << it3->second << std::endl;
		it3++;
	}
}

int main()
{
	t4();

	return 0;
}