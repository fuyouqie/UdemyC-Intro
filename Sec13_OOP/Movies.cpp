#include "Movies.h"

using namespace std;

Movies::Movies()
{

}

Movies::~Movies()
{

}

size_t Movies::size() const
{
	return movies.size();
}

Movie *Movies::find_movie_by_name(string name)
{
	Movie *movie_found = nullptr;
	for (size_t i = 0; i < size(); i++)
	{
		if (movies.at(i).get_name() == name)
			movie_found = &movies.at(i);
	}
	return movie_found;
}

bool Movies::add_movie(string name, string rating, int watched)
{
	Movie *movie_found = find_movie_by_name(name);
	if (movie_found == nullptr)
	{
		Movie m(name, rating, watched);
		movies.push_back(m);
		return true;
	}
	return false;
}

void Movies::display() const
{
	for (Movie m : movies)
		m.display();
}

bool Movies::increment_watched(std::string name)
{
	Movie *movie_found = find_movie_by_name(name);
	if (movie_found != nullptr)
	{
		(*movie_found).increment_watched();
		return true;
	}
	return false;
}