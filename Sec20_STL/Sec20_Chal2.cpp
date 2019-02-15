#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <sstream>

class Song
{
	friend std::ostream &operator<<(std::ostream &os, const Song &s);

private:
	std::string name;
	std::string artist;
	int rating;

public:
	Song() = default;

	Song(std::string name, std::string artist, int rating)
		: name{name}, artist{artist}, rating{rating}
	{
	}

	std::string get_name() const
	{
		return name;
	}

	std::string get_artist() const
	{
		return artist;
	}

	int get_rating() const 
	{
		return rating;
	}

	bool operator<(const Song &rhs) const
	{
		return this->name < rhs.name;
	}

	bool operator==(const Song &rhs) const
	{
		return this->name == rhs.name;
	}
};

std::ostream &operator<<(std::ostream &os, const Song &s)
{
	os << std::setw(20) << std::left << s.name
		<< std::setw(30) << std::left << s.artist
		<< std::setw(2) << std::left << s.rating;
	return os;
}

void display_menu()
{
	std::cout << "\nF - Play First Song" << std::endl;
	std::cout << "T - Play Last Song" << std::endl;
	std::cout << "N - Play Next song" << std::endl;
	std::cout << "P - Play Previous song" << std::endl;
	std::cout << "A - Add and play a new Song at current location" << std::endl;
	std::cout << "L - List the current playlist" << std::endl;
	std::cout << "===============================================" << std::endl;
	std::cout << "Enter a selection (Q to quit): ";
}

char read_option()
{
	std::string line;
	std::getline(std::cin, line);
	std::cout << std::endl;
	char option = ::toupper(line.at(0));
	return option;
}

std::string read_line(std::string msg)
{
	std::string line;
	std::cout << msg;
	std::getline(std::cin, line);
	return line;
}

bool read_int(int &destination, std::string msg)
{
	std::string line = read_line(msg);
	std::istringstream iss{line};
	bool successful{false};

	if (iss >> destination)
	{
		if (destination >= 0 && destination <= 5)
			successful = true;
	}

	return successful;
}

void error()
{
	std::cout << "Option invalid" << std::endl;
}

void quit()
{
	std::cout << "Goodbye! Thank you for listening" << std::endl;
}

void play_song(const Song &song)
{
	std::cout << "Playing: " << song << std::endl;
}

void play_first(const std::list<Song> &playlist, std::list<Song>::const_iterator &current_song)
{
	current_song = playlist.begin();
	play_song(*current_song);
}

void play_last(const std::list<Song> &playlist, std::list<Song>::const_iterator &current_song)
{
	current_song = playlist.end();
	current_song--;
	play_song(*current_song);
}

void play_next(const std::list<Song> &playlist, std::list<Song>::const_iterator &current_song)
{
	current_song++;
	if (current_song == playlist.end())
		current_song = playlist.begin();
	play_song(*current_song);
}

void play_previous(const std::list<Song> &playlist, std::list<Song>::const_iterator &current_song)
{
	if (current_song == playlist.begin())
		current_song = playlist.end();
	current_song--;
	play_song(*current_song);
}

void display_playlist(const std::list<Song> &playlist, std::list<Song>::const_iterator &current_song)
{
	std::cout << std::left;
	for (const auto &song : playlist)
		std::cout << song << std::endl;

	play_song(*current_song);
}

void add_play(std::list<Song> &playlist, std::list<Song>::iterator &current_song)
{
	std::string name;
	std::string artist;
	int rating{0};

	name = read_line(std::string{"Enter name of song: "});
	artist = read_line(std::string{"Enter artist of song: "});
	if (read_int(rating, "Enter rating of song: "))
	{
		playlist.emplace(current_song, name, artist, rating);
		std::cout << "New song added" << std::endl;
	}
	else
		std::cout << "Invalid input" << std::endl;
}

void driver(std::list<Song> &playlist, std::list<Song>::iterator &current_song)
{
	char option{};
	do
	{
		display_menu();
		option = read_option();

		switch (option)
		{
			case 'F':
				play_first(playlist, current_song);
				break;
			case 'T':
				play_last(playlist, current_song);
				break;
			case 'N':
				play_next(playlist, current_song);
				break;
			case 'P':
				play_previous(playlist, current_song);
				break;
			case 'A':
				add_play(playlist, current_song);
				break;
			case 'L':
				display_playlist(playlist, current_song);
				break;
			case 'Q':
				quit();
				break;
			default:
				error();
		}
	}
	while (option != 'Q');
}

int main()
{
	std::list<Song> playlist
	{
			{"God's Plan",        "Drake",                     5},
			{"Never Be The Same", "Camila Cabello",            5},
			{"Pray For Me",       "The Weekend and K. Lamar",  4},
			{"The Middle",        "Zedd, Maren Morris & Grey", 5},
			{"Wait",              "Maroone 5",                 4},
			{"Whatever It Takes", "Imagine Dragons",           3}
	};

	std::list<Song>::iterator current_song = playlist.begin();

	display_playlist(playlist, current_song);
	driver(playlist, current_song);

	return 0;
}