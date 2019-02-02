#include <cstring>
#include <iostream>
#include "MyString-global.h"

using namespace std;

MyString::MyString()
	:str{nullptr}
{
	str = new char[1];
	*str = '\0';
}

MyString::MyString(const char *s)
	:str{nullptr}
{
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
	str = new char[strlen(source.str) + 1];
	strcpy(str, source.str);
}

MyString::~MyString()
{
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

void MyString::display() const
{
	cout << str << " : " << get_length() << endl;
}

int MyString::get_length() const
{
	return strlen(str);
}

const char *MyString::get_str() const
{
	return str;
}


bool operator==(const MyString &lhs, const MyString &rhs)
{
	return strcmp(lhs.str, rhs.str) == 0;
}

MyString operator-(const MyString &source)
{
	char *buff = new char[strlen(source.str) + 1];
	for (size_t i = 0; i < strlen(buff); i++)
		buff[i] = tolower(source.str[i]);
	MyString temp(buff);
	delete[] buff;
	return temp;
}

MyString operator+(const MyString &lhs, const MyString &rhs)
{
	char *buff = new char[strlen(lhs.str) + strlen(rhs.str) + 1];
	strcpy(buff, lhs.str);
	strcat(buff, rhs.str);
	MyString temp(buff);
	delete[] buff;
	return temp;
}