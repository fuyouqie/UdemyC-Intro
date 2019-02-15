/*
	Adapter class
	First-in, First-out
	Any container has front and back
	Can be implemented as list, deque
	!Elements are pushed at back, popped from front
*/

#include <queue>
#include <list>
#include <deque>
#include <iostream>

template<typename T>
void display(std::queue<T> q)
{
	std::cout << "[ ";
	while (!q.empty())
	{
		std::cout << q.front() << " ";
		q.pop();
	}
	std::cout << "]" << std::endl;
}

int main()
{
	//by default it uses deque
	std::queue<int> q1;

	//explictely specifying
	std::queue<int, std::list<int>> q2;
	std::queue<int, std::deque<int>> q3;

	//add element at the back
	for (int i : {1, 2, 3, 4, 5, 6, 7})
		q1.push(i);

	//accessing front and back element
	std::cout << q1.front() << std::endl;
	std::cout << q1.back() << std::endl;

	//remove element at the front
	q1.pop();
	q1.pop(); 

	//iterate, pass by value	
	display(q1);

	return 0;
}