#include "Printable-Sec16-Chal.h"
#include <iostream>

using namespace std;

ostream &operator<<(ostream &os, Printable &obj)
{
	obj.print(os);
	return os;
}