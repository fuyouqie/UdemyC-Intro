#pragma once

class MyString
{
private:
	char *str;

public:
	MyString();
	MyString(const char *s);
	MyString(const MyString &source);
	~MyString();

	MyString &operator=(const MyString &rhs);
	MyString &operator=(MyString &&rhs);
	MyString operator-() const; //unary - operator, make lower case
	MyString operator+(const MyString &rhs) const; //binary + operator, concatenation
	bool operator==(const MyString &rhs) const; //binary ==, test equality
	void display() const;
	int get_length() const;
	const char *get_str() const;
};