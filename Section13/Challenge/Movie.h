#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>

class Movie {
        std::string name;
        std::string rating;
        unsigned int watchCount;
    public:
        Movie(std::string name, std::string rating, int watched);
        Movie(const Movie &src);
        void setName(std::string name);
        std::string get_name() const;
        void setRating(std::string rating);
        std::string getRating() const;
        void setWatchCount(unsigned int watchCount);
        unsigned int getWatchCount() const;
        void increment_watched();
        void display() const;
};

#endif