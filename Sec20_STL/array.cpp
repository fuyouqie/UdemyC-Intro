#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>  // for more algorithms like accumulate

template<typename T, size_t size>
void display(const std::array<T,size> &arr)
{
	std::cout << "[ ";
	for (auto &i : arr)
		std::cout << i << " ";
	std::cout << "]" << std::endl;
}

void basic()
{
	std::array<int, 5> arr1{1,2,3,4,5};     // double {{ }} if C++ 11
	std::array<int, 5> arr2;

	display(arr1);
	display(arr2);          // Elements are not initialized (contain 'garbage')

	arr2 = {10,20,30,40,50};

	display(arr1);
	display(arr2);

	std::cout << "Size of arr1 is: " << arr1.size() << std::endl;       //5 
	std::cout << "Size of arr2 is: " << arr2.size() << std::endl;       //5

	arr1[0] = 1000;
	arr1.at(1) = 2000;
	display(arr1);

	std::cout << "Front of arr2: " << arr2.front() << std::endl;        // 10
	std::cout << "Back of arr2: " << arr2.back() << std::endl;          // 50

	std::array<int, 4> arr3{1,2};
	std::cout << arr3.size() << " " << arr3.max_size() << std::endl;
	//in std::array they give same value. In other containers the result differs

	std::array<int, 0> arr4;
	std::array<int, 4> arr5;
	std::cout << std::boolalpha << arr4.empty() << arr5.empty() << std::endl;

	arr3.fill(3);
	arr5.fill(5);
	display(arr3);
	display(arr5);

	arr3.swap(arr5);
	display(arr3);
	display(arr5);
}

void get_raw_arr()
{
	std::array<int, 5> arr1{1,2,3,4,5};
	int *numbers = arr1.data(); //the address of first element
	std::cout << numbers << " " << *numbers << std::endl;
}

void sort()
{
	std::array<int, 5> arr1{3,5,1,4,2};
	display(arr1);
	std::sort(arr1.begin(), arr1.end());
	display(arr1);
}

void min_max()
{
	std::array<int, 5> arr1{2,1,4,5,3};

	//min_element()/max_element() returns an iterator to the min/max element
	std::array<int, 5>::iterator min_num = std::min_element(arr1.begin(), arr1.end());
	auto max_num = std::max_element(arr1.begin(), arr1.end());
	std::cout << "min: " << *min_num << " , max: " << *max_num << std::endl;
}

void adjacent()
{
	//returns an iterator to the first occurance of two adjacent values, == operator used
	std::array<int, 5> arr1{2,1,3,3,5};

	auto adjacent = std::adjacent_find(arr1.begin(), arr1.end());
	if (adjacent != arr1.end())
		std::cout << "Adjacent element found with value: " << *adjacent << std::endl;
	else
		std::cout << "No adjacent elements found" << std::endl;
}

void accumulate()
{
	std::array<int, 5> arr1{2,1,3,3,5};
	int num = std::accumulate(arr1.begin(), arr1.end(), 0); //start to add from 0
	std::cout << "Sum of all elements is " << num << std::endl;
}

int main()
{
	//basic();
	//get_raw_arr();
	//sort();
	//min_max();
	//adjacent();
	//accumulate();

	return 0;
}