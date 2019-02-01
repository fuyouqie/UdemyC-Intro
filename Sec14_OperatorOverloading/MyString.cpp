#include <cstring>
#include <iostream>
#include "MyString.h"

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