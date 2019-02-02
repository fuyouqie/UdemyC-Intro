#pragma once

class MyString
{
	friend std::ostream &operator<<(std::ostream &os, const MyString &rhs);
	friend std::istream &operator>>(std::istream &is, MyString &rhs);

private:
	char *str;

public:
	MyString();
	MyString(const char *s);
	MyString(const MyString &source);
	~MyString();

	MyString &operator=(const MyString &rhs);
	MyString &operator=(MyString &&rhs);
	void display() const;
	int get_length() const;
	const char *get_str() const;
};