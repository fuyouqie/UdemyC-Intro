#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <iomanip>
#include <cctype>
#include <string>

bool is_palindrome(const std::string& str)
{
	std::stack<char> s;
	std::queue<char> q;
	for (const auto &c : str)
	{
		if (std::isalpha(c))
		{
			s.push(::toupper(c));
			q.push(::toupper(c));
		}
	}

	while (s.size() >= (s.size() / 2 + 1))
	{
		if (s.top() != q.front())
			return false;
		s.pop();
		q.pop();
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
		std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
	}
	std::cout << std::endl;
	return 0;
}