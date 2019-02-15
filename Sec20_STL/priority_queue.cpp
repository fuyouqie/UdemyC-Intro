/*
	std::priority_queue
	Elements are stored in a vector by default internally
	Inserted in order, the largest element is always at the front
*/

#include <queue>
#include <iostream>

template<typename T>
void display(std::priority_queue<T> pq)
{
	std::cout << "[ ";
	while (!pq.empty())
	{
		std::cout << pq.top() << " ";
		pq.pop();
	}
	std::cout << "]" << std::endl;
}

int main()
{
	std::priority_queue<int> pq;
	
	//add element, sorted automatically
	pq.push(2);
	pq.push(3);
	pq.push(1);

	//remove the top/largest element
	pq.pop();

	//access top element
	std::cout << pq.top() << std::endl;

	//iterate, pass by value
	pq.push(5);
	pq.push(18);
	pq.push(6);
	pq.push(10);
	pq.push(100);

	display(pq);

	return 0;
}