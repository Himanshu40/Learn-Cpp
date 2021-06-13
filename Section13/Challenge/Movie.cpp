/******************************************************************
 * Section 13 Challenge
 * Movie.cpp
 * 
 * Models a Movie with the following atttributes
 * 
 * std::string name - the name of the movie 
 * std::string rating - G, PG, PG-13, R
 * int watched - the number of times you've watched the movie
 * ***************************************************************/

#include <iostream>
#include "Movie.h"

Movie::Movie(std::string name, std::string rating, int watched)
    : name{name}, rating{rating}, watched{watched} {
}

Movie::Movie(const Movie &src)
    : Movie{src.name, src.rating, src.watched} {
}

void Movie::setName(std::string name) {
    this->name = name;
}

std::string Movie::getName() const {
    return name;
}

void Movie::setRating(std::string rating) {
    this->rating = rating;
}

std::string Movie::getRating() const {
    return rating;
}

void Movie::setWatched(unsigned int watched) {
    this->watched = watched;
}

unsigned int Movie::getWatched() const {
    return watched;
}

void Movie::incrementWatched() {
    ++watched;
}

void Movie::display() const {
    std::cout << "Movie Name: " << name << std::endl;
    std::cout << "Movie Rating: " << rating << std::endl;
    std::cout << "Movie Watch Count: " << watched << std::endl;
}
