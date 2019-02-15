#include <iostream>
#include <string>

using namespace std;

template<typename T, size_t N>
class Array
{
	template<typename T, size_t N>
	friend ostream &operator<<(ostream &os, const Array<T, N> &arr);

private:
	size_t size{N};
	T arr[N];

public:
	Array() = default;

	Array(T init_val)
	{
		fill(init_val);
	}

	void fill(T value)
	{
		for (auto &element : arr)
			element = value;
	}

	size_t get_size() const
	{
		return size;
	}

	T &operator[](int index)
	{
		return arr[index];
	}
};

template<typename T, size_t N>
ostream &operator<<(ostream &os, const Array<T, N> &arr)
{
	os << "[ ";
	for (auto &ele : arr.arr)
		os << ele << " ";
	os << "]";
	return os;
}

int main()
{
	Array<double, 10> doubles;
	cout << doubles << endl;
	doubles.fill(22.5);
	cout << doubles << endl;

	return 0;
}