/******************************************************************
 * Section 13 Challenge
 * Movies.h
 * 
 * Models a collection of Movie as a std::vector
 *  implement these methods in Movies.cpp
 *
 * ***************************************************************/

#ifndef _MOVIES_H_
#define _MOVIES_H_

#include <vector>
#include <string>
#include "Movie.h"

class Movies {
        std::vector<Movie> movies;
    public:
        bool incrementWatched(std::string name);
        bool addMovie(std::string name, std::string rating, int watched);
        void display() const;
};

#endif