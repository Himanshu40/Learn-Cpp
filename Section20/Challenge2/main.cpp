// Section 20
// Challenge 2 - Lists
#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
        friend std::ostream &operator<<(std::ostream &os, const Song &s);
        std::string name;
        std::string artist;
        int rating;
    public:
        Song() = default;
        
        Song(std::string name, std::string artist, int rating)
                : name{name}, artist{artist}, rating{rating} {}
        
        std::string get_name() const {
            return name;
        }
        
        std::string get_artist() const {
            return artist;
        }
        
        int get_rating() const {
            return rating;
        }
        
        bool operator<(const Song &rhs) const  {
            return this->name < rhs.name;
        }
        
        bool operator==(const Song &rhs) const  {
            return this->name == rhs.name;
        }
};

class InvalidChoiceException : public std::exception {
    public:
        InvalidChoiceException() noexcept = default;
        
        ~InvalidChoiceException() = default;
        
        virtual const char *what() const noexcept {
            return "Invalid Input. Try again!!!\n";
        }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    // This function should display 
    // Playing: followed by the song that is playing
    std::cout << "Playing:" << std::endl;
    std::cout << song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    // This function should display the current playlist 
    // and then the current song playing.
    for (const auto &elem : playlist) {
        std::cout << elem << std::endl;
    }

    std::cout << "\nCurrent Song:" << std::endl;
    std::cout << current_song << std::endl;
}

void play_next_song(std::list<Song> &playlist, std::list<Song>::iterator &current_song) {
    std::cout << "\nPlaying next song" << std::endl;

    if (current_song == std::prev(playlist.end())) {
        std::cout << "Wrapping to start of playlist" << std::endl;
        current_song = playlist.begin();
    }
    else {
        current_song++;
    }

    play_current_song(*current_song);
}

void play_previous_song(std::list<Song> &playlist, std::list<Song>::iterator &current_song) {
    std::cout << "\nPlaying previous song" << std::endl;

    if (current_song == playlist.begin()) {
        std::cout << "Wrapping to end of playlist" << std::endl;
        current_song = std::prev(playlist.end());
    }
    else {
        current_song--;
    }

    play_current_song(*current_song);
}

void add_Song(std::list<Song> &playlist, std::list<Song>::iterator &current_song) {
    std::string name;
    std::string artist;
    int rating;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    std::cout << "Adding and playing new song" << std::endl;
    std::cout << "Enter song name: ";
    std::getline(std::cin, name);

    std::cout << "Enter song artist: ";
    std::getline(std::cin, artist);

    std::cout << "Enter your rating(1-5): ";
    std::cin >> rating;

    Song new_song {name, artist, rating};
    playlist.insert(current_song, new_song);
    current_song = std::prev(current_song);

    play_current_song(*current_song);
}

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    
    std::list<Song>::iterator current_song = playlist.begin();
    
    display_playlist(playlist, *current_song);

    while (true) {
        display_menu();

        char choice;
        try {
            std::cin >> choice;

            choice = std::toupper(choice);
            std::cout << choice << std::endl;
            
            if (choice == 'F' || choice == 'N' ||
                choice == 'P' || choice == 'A' ||
                choice == 'L' || choice == 'Q') {
            }
            else {
                throw InvalidChoiceException();
            }
        }
        catch (const InvalidChoiceException &ex) {
            std::cerr << ex.what();
            continue;
        }

        switch (choice) {
            case 'F': current_song = playlist.begin();
                      play_current_song(*current_song);
                      break;
            case 'N': play_next_song(playlist, current_song);
                      break;
            case 'P': play_previous_song(playlist, current_song);
                      break;
            case 'A': add_Song(playlist, current_song);
                      break;
            case 'L': display_playlist(playlist, *current_song);
                      break;
            case 'Q': std::cout << "\nThanks for listening!" << std::endl;
                      break;
        }

        if (choice == 'Q') {
            break;
        }
    }

    return 0;
}
