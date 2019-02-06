#include <iostream>

using namespace std;

class A
{
	virtual void method();
};

class B : public A
{
	//prevents subclasses of B to override
	virtual void method() override final;
};

//prevents class C from being inherited by other classes
class C final : public B
{
	
	virtual void method() override;
};

class D : public C
{

};

int main()
{


	return 0;
}