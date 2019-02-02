#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
	MyString empty;
	MyString alice("Alice");
	MyString alice_copy(alice);

	empty.display();
	alice.display();
	alice_copy.display();

	return 0;
}