/******************************************************************
 * Section 13 Challenge
 * Movie.h
 * 
 * Models a Movie with the following atttributes
 * 
 * std::string name - the name of the movie 
 * std::string rating - G, PG, PG-13, R
 * int watched - the number of times you've watched the movie
 * ***************************************************************/

#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <string>

class Movie {
        std::string name;
        std::string rating;
        unsigned int watched;
    public:
        Movie(std::string name, std::string rating, unsigned int watched);
        Movie(const Movie &src);
        void setName(std::string name);
        std::string getName() const;
        void setRating(std::string rating);
        std::string getRating() const;
        void setWatched(unsigned int watched);
        unsigned int getWatched() const;
        void incrementWatched();
        void display() const;
};

#endif
