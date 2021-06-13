/******************************************************************
 * Section 13 Challenge
 * Movies.h
 * 
 * Models a collection of Movies as a std::vector
 * 
 * ***************************************************************/

#include <iostream>
#include "Movies.h"


bool Movies::incrementWatched(std::string name) {
    for (auto &x : movies) {
        if (name == x.getName()) {
            x.incrementWatched();
            return true;
        }
    }

    return false;
}

bool Movies::addMovie(std::string name, std::string rating, unsigned int watched) {
    for (auto &x : movies) {
        if (name == x.getName()) {
            return false;
        }
    }

    movies.push_back(Movie{name, rating, watched});
    
    return true;
}

void Movies::display() const {
    if (!movies.empty()) {
        for (const auto &x : movies) {
            x.display();
        }
    }
    else {
        std::cout << "Movies database is empty" << std::endl;
    }
}
