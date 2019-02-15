// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <iterator>

bool is_palindrome(const std::string& s)
{
	// You must implement this function.
	// Since we are learning the STL - use a deque to solve the problem.
	bool is_palindrome = true;

	std::deque<char> forward;
	for (const auto &c : s)
	{
		if(std::isalpha(c))
			forward.push_back(::toupper(c));
	}

	std::deque<char> backward;
	std::copy(forward.begin(), forward.end(), std::front_inserter(backward));

	auto forward_it = forward.begin();
	auto backward_it = backward.begin();

	for (size_t i{0}; i < (forward.size() / 2) + 1; i++)
	{
		if (*forward_it != *backward_it)
		{
			is_palindrome = false;
			break;
		}
	}

	return is_palindrome;
}

bool better_solution(const std::string& s)
{
	std::deque<char> str;
	for (const auto &c : s)
	{
		if (std::isalpha(c))
			str.push_back(::toupper(c));
	}

	char front{};
	char back{};

	while (str.size() > 1)
	{
		front = str.front();
		back = str.back();
		str.pop_front();
		str.pop_back();
		
		if (front != back)
			return false;
	}

	return true;
}

int main()
{
	std::vector<std::string> test_strings{"a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
		"avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
		"A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome"};

	std::cout << std::boolalpha;
	std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
	for (const auto& s : test_strings)
	{
		std::cout << std::setw(8) << std::left << better_solution(s) << s << std::endl;
	}
	std::cout << std::endl;
	return 0;
}