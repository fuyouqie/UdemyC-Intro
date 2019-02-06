#include <iostream>

using namespace std;

class Printable
{
	friend ostream &operator<<(ostream &os, Printable &obj);

public:
	virtual void print(ostream &os) = 0;
	virtual ~Printable() = default;
};

ostream &operator<<(ostream &os, Printable &obj)
{
	obj.print(os);
	return os;
}

class Shape : public Printable
{
public:
	virtual void draw() = 0; // = 0 makes it a pure virtual function and abstracts the class
	virtual void scale() = 0;
	virtual ~Shape()
	{
	}
};

class Open_Shape : public Shape
{
public:
	virtual ~Open_Shape()
	{
	}
};

class Closed_Shape : public Shape
{
public:
	virtual void perimeter() = 0;
	virtual void area() = 0;
	virtual ~Closed_Shape()
	{
	}
};

class Line : public Open_Shape
{
public:
	virtual void draw() override
	{
		cout << "Draw a line" << endl;
	}

	virtual void scale() override
	{
		cout << "Line scaled" << endl;
	}

	virtual void print(ostream &os) override
	{
		os << "Printing Line";
	}
};

class Circle : public Closed_Shape
{
public:
	virtual void draw() override
	{
		cout << "Draw a circle" << endl;
	}

	virtual void scale() override
	{
		cout << "Circle scaled" << endl;
	}

	virtual void perimeter() override
	{
		cout << "Perimeter is xxx" << endl;
	}

	virtual void area() override
	{
		cout << "Area is xxx" << endl;
	}

	virtual void print(ostream &os) override
	{
		os << "Printing Circle";
	}
};


int main()
{
	Shape *p1 = new Line();
	Shape *p2 = new Circle();

	cout << *p1 << endl;
	cout << *p2 << endl;



	return 0;
}