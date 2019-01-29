#include <iostream>

using namespace std;

int maina()
{
	/*****************************
		Declare and initialise a pointer
	******************************/

	//always initialise the pointer, at least to 0 or nullptr so that it points to nowhere
	//uninitialised pointer contain garbage data and can point anywhere
	int *ptrErr{}; 
	int *ptrOne{0};
	int *ptrTwo{nullptr};

	/*****************************
		Store and access address in a pointer
	******************************/

	int num = 5;
	int *numPtr = &num;
	//cout << *numPtr;

	/*****************************
		Dynamic memory allocation
	******************************/

	// new keyword, allocates storage for an int and stores the address into pointer
	// the allocated storage does not have a name, the only way to access that storage is the pointer
	// if somehow the pointer is lost (out of scope or reassigned), then a memory leak occurs+
	int *heapAllo = new int;
	cout << heapAllo << endl; //address
	cout << *heapAllo << endl; //garbage
	*heapAllo = 100; //assign a valid value
	cout << *heapAllo << endl;
	delete heapAllo; //frees the storage allocated
	//"delete" makes the only way to access the memory gone, by 

	double *heapArr = new double[5];
	delete[] heapArr; // delete[] to free memory allocated with array

	/*****************************
		Array <-> pointer
	******************************/

	//An array name represents the address of the first element
	int marks[]{20,50,30,40};
	cout << marks << endl; //address of first element
	cout << *marks << endl; //value of first element

	int *marksPtr{marks};
	cout << marksPtr << endl;
	cout << *marksPtr << endl;

	cout << "========NOTATIONS========" << endl;
	// Array subscript notation
	cout << marksPtr[1] << endl;
	cout << marksPtr[2] << endl;
	
	// Array offest notation
	cout << *(marks + 1) << endl;
	cout << *(marks + 2) << endl;

	// Pointer subscript notation
	cout << marksPtr[1] << endl;
	cout << marksPtr[2] << endl;

	// Pointer offest notation
	cout << *(marksPtr + 1) << endl;
	cout << *(marksPtr + 2) << endl;
	cout << "========NOTATIONS========" << endl;

	//adds the address by 4 which is 1 integer away
	cout << marksPtr + 1 << endl;
	cout << marksPtr + 2 << endl;

	/*****************************
		Pointer arithmetic
	******************************/

	int amount{5};
	int *integerPtr = &amount;
	//increment/decrement the value by size of the data type it's pointing to
	integerPtr++;
	integerPtr--;

	//*integerPtr++;
	//deref integerPtr, increment integerPtr
	cout << *integerPtr++ << endl;

	//increment integerPtr, deref integerPtr
	cout << *++integerPtr << endl;

	char name[]{"Frank"};

	char *char_ptr1{nullptr};
	char *char_ptr2{nullptr};

	char_ptr1 = &name[0];   // F
	char_ptr2 = &name[3];   // n

	cout << "In the string " << name << ",  " << *char_ptr2 << " is " << (char_ptr2 - char_ptr1) << " characters away from " << *char_ptr1 << endl;

	/*****************************
		Pointer and constants
	******************************/

	int low{10};
	int high{20};
	//pointer to constant
	const int *ptc = &low;

	//*ptc = 5; //error
	ptc = &high;

	//constant pointer
	int *const cp = &low;
	*cp = 5;
	//cp = &high; //error

	//constant pointer to constant
	const int *const cptc = &low;
	//*cp = 5; //error
	//cp = &high; //error

	return 0;
}