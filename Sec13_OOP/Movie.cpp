#include "Movie.h"
#include <iostream>

using namespace std;

Movie::Movie(std::string name, std::string rating, int watched)
	:name{name},rating{rating},watched{watched}
{
	
}

Movie::~Movie()
{

}

string Movie::get_name() const
{
	return name;
}

string Movie::get_rating() const
{
	return rating;
}

int Movie::get_watched() const
{
	return watched;
}

void Movie::increment_watched()
{
	watched++;
}

void Movie::display()
{
	cout << "Name: " << name << ". Rating: " << rating << ". Watched " << watched << " times" << endl;
}