#include <memory>
#include <iostream>
#include <vector>

using namespace std;

/*
	Both A and B cannot be deleted since the use count is 2
	Strong circular reference
*/

class B;

class A
{
public:
	shared_ptr<B> B_ptr;

	A()
	{
		cout << "A constructor called" << endl;
	}

	~A()
	{
		cout << "A destructor called" << endl;
	}

	void setB(shared_ptr<B> B_ptr)
	{
		this->B_ptr = B_ptr;
	}
};

class B
{
public:
	shared_ptr<A> A_ptr;

	B()
	{
		cout << "B constructor called" << endl;
	}

	~B()
	{
		cout << "A destructor called" << endl;
	}

	void setA(shared_ptr<A> A_ptr)
	{
		this->A_ptr = A_ptr;
	}
};

/*
	 make weak pointer to break strong circular reference
	 the weak pointer to D in class C now does not add to use count of C object
*/


class D;

class C
{
public:
	shared_ptr<D> D_ptr;

	C()
	{
		cout << "C constructor called" << endl;
	}

	~C()
	{
		cout << "C destructor called" << endl;
	}

	void setD(shared_ptr<D> D_ptr)
	{
		this->D_ptr = D_ptr;
	}
};

class D
{
public:
	weak_ptr<C> C_ptr; //weak pointer

	D()
	{
		cout << "D constructor called" << endl;
	}

	~D()
	{
		cout << "D destructor called" << endl;
	}

	void setC(shared_ptr<C> C_ptr)
	{
		this->C_ptr = C_ptr;
	}
};

int main()
{
	shared_ptr<A> A_ptr = make_shared<A>();
	shared_ptr<B> B_ptr = make_shared<B>();
	A_ptr->setB(B_ptr);
	B_ptr->setA(A_ptr);

	shared_ptr<C> C_ptr = make_shared<C>();
	shared_ptr<D> D_ptr = make_shared<D>();
	C_ptr->setD(D_ptr);
	D_ptr->setC(C_ptr);

	return 0;
}