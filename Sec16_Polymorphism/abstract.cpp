#include <iostream>

using namespace std;

class Shape
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
};


int main()
{
	//Shape, Open_Shape, Closed_Shape are not instaniatable
	//Shape s;
	//Open_Shape os;
	//Closed_Shape cs;

	Line l;
	l.draw();

	Shape *p1 = new Line();
	Shape *p2 = new Circle();

	p1->draw();
	p2->draw();

	return 0;
}