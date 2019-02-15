/*
	Adapter class, same as queue, which it's implementation is based on already existing STL containers
	Fisrt-in, Last-out
	Can be implemented as vector, list, deque which all have a back
	they use push_back(), pop_back() methods 
*/

#include <stack>
#include <vector>
#include <list>
#include <iostream>

template<typename T>
void display(std::stack<T> s)
{
	std::cout << "[ ";
	while (!s.empty())
	{
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << "]" << std::endl;
}

int main()
{
	//By default, deque container is used
	std::stack<int> s1;

	//Providing the container explicitly
	std::stack<int, std::vector<int>> s2;
	std::stack<int, std::list<int>> s3;
	std::stack<int, std::deque<int>> s4;

	//adding elements at the back
	s1.push(2);
	s1.push(20);

	//access top(back) element
	std::cout << s1.top() << std::endl;

	//pop element at the back
	s1.pop();
	std::cout << s1.top() << std::endl;

	//iterate, passing by value
	s1.push(3);
	s1.push(4);
	s1.push(50);
	s1.push(50);
	display(s1);
	display(s1);

	return 0;
}