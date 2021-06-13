/******************************************************************
 * Section 13 Challenge
 * main.cpp
 * 
 * Test the Movies project
 * 
 * ***************************************************************/

#include <iostream>
#include "Movies.h"


void incrementWatched(Movies &movies, std::string name);
void addMovie(Movies &movies, std::string name, std::string rating, int watched);


int main() {
    Movies myMovies;
    
    myMovies.display();
    
    addMovie(myMovies, "Big", "PG-13",2);     // OK
    addMovie(myMovies,"Star Wars", "PG",5);   // OK
    addMovie(myMovies,"Cinderella", "PG",7);  // OK
     
    myMovies.display();                       // Big, Star Wars, Cinderella
    
    addMovie(myMovies,"Cinderella", "PG",7);  // Already exists
    addMovie(myMovies,"Ice Age", "PG",12);    // OK
 
    myMovies.display();                       // Big, Star Wars, Cinderella, Ice Age
    
    incrementWatched(myMovies,"Big");         // OK
    incrementWatched(myMovies,"Ice Age");     // OK
    
    myMovies.display();                       // Big and Ice Age watched count incremented by 1
    
    incrementWatched(myMovies,"XXX");         // XXX not found

    return 0;
}

void incrementWatched(Movies &movies, std::string name) {
    if (movies.incrementWatched(name)) {
        std::cout << "*** " << name << " watch incremented" <<  std::endl;
    }
    else {
        std::cout << "*** " << name << " not found" <<  std::endl;
    }
}

void addMovie(Movies &movies, std::string name, std::string rating, int watched) {
    if (movies.addMovie(name, rating, watched)) {
        std::cout << "** " << name << " added" << std::endl;
    }
    else {
        std::cout << "** " << name << " already exists" <<  std::endl;
    }
}
