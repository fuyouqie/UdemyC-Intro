#include <cstring>
#include <iostream>
#include "MyString-Sec14-Chal-mem.h"

using namespace std;

MyString::MyString()
	:str{nullptr}
{
	cout << "Default constructor called" << endl;
	str = new char[1];
	*str = '\0';
}

MyString::MyString(const char *s)
	:str{nullptr}
{
	cout << "Alternate constructor called" << endl;
	if (s == nullptr)
	{
		str = new char[1];
		*str = '\0';
	}
	else
	{
		str = new char[strlen(s) + 1];
		strcpy(str, s); //copies the charactersa and ends with \0 terminator
	}
}

MyString::MyString(const MyString &source)
	:str{nullptr}
{
	cout << "Copy constructor called" << endl;
	str = new char[strlen(source.str) + 1];
	strcpy(str, source.str);
}

MyString::MyString(MyString &&source)
	:MyString{source.str}
{
	cout << "Move constructor called" << endl;
	source.str = nullptr;
}

MyString::~MyString()
{
	cout << "Destructor called" << endl;
	delete[] str;
}

MyString &MyString::operator=(const MyString &rhs)
{
	cout << "Copy assignment" << endl;
	if (this == &rhs) //test if the address of current object is the same as the address of rhs
		return *this; //"this" is a pointer to current object

	delete[] str;
	str = new char[strlen(rhs.str) + 1];
	strcpy(str, rhs.str);
	return  *this;
}

MyString &MyString::operator=(MyString &&rhs)
{
	cout << "Move assignment" << endl;
	if (this == &rhs)
		return *this;

	delete[] str;
	str = rhs.str;
	rhs.str = nullptr;
	return *this;
}

MyString MyString::operator-()
{
	char *buff = new char[strlen(str) + 1];
	for (size_t i = 0; i < strlen(buff); i++)
		buff[i] = tolower(str[i]);
	MyString temp(buff);
	delete[] buff;
	return temp;
}

bool MyString::operator==(const MyString &rhs)
{
	return strcmp(str, rhs.str) == 0;
}

bool MyString::operator!=(const MyString &rhs)
{
	return strcmp(str, rhs.str);
}

bool MyString::operator<(const MyString &rhs)
{
	if (strcmp(str, rhs.str) == -1)
		return true;
	return false;
}

bool MyString::operator>(const MyString &rhs)
{
	if (strcmp(str, rhs.str) == 1)
		return true;
	return false;
}

MyString MyString::operator+(const MyString &rhs)
{
	char *buff = new char[strlen(str) + strlen(rhs.str) + 1];
	strcpy(buff, str);
	strcat(buff, rhs.str);
	MyString temp(buff);
	delete[] buff;
	return temp;
}

MyString &MyString::operator+=(const MyString &rhs)
{
	MyString temp = operator+(rhs);
	operator=(temp);
	return *this;
}

MyString MyString::operator*(size_t num)
{
	char *buff = new char[strlen(str) * num + 1];
	strcpy(buff, str);
	for (size_t i = 0; i < num-1; i++)
		strcat(buff, str);
	MyString temp(buff);
	delete[] buff;
	return temp;
}

MyString &MyString::operator*=(size_t num)
{
	MyString temp = operator*(num);
	operator=(temp);
	return *this;
}

MyString &MyString::operator++()
{
	for (size_t i = 0; i < strlen(str); i++)
		str[i] = toupper(str[i]);
	return *this;
}

MyString MyString::operator++(int)
{
	MyString temp(*this);
	operator++();
	return temp;
}


ostream &operator<<(std::ostream &os, const MyString &rhs)
{
	os << rhs.str;
	return os;
}


istream &operator>>(std::istream &is, MyString &rhs)
{
	char *buff = new char[1000];
	is >> buff;
	rhs = MyString(buff);
	delete[] buff;
	return is;
}

int MyString::get_length() const
{
	return strlen(str);
}

const char *MyString::get_str() const
{
	return str;
}