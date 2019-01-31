#pragma once

#include "Movie.h"
#include <vector>

class Movies
{
private:
	std::vector<Movie> movies;

public:
	size_t size() const;
	Movies();
	~Movies();
	Movie *find_movie_by_name(std::string name);
	bool add_movie(std::string name, std::string rating, int watched);
	void display() const;
	bool increment_watched(std::string name);
};