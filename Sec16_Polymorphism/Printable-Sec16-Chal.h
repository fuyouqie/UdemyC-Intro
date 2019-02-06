#pragma once

#include <iostream>

class Printable
{
	friend std::ostream &operator<<(std::ostream &os, Printable &obj);

public:
	virtual void print(std::ostream &os) = 0;
	virtual ~Printable() = default;
};