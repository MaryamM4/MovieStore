//
// Created by Andrew on 2/19/2024.
//

#include "inventory.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void Inventory::buildInventory(std::fstream &infile) {
  char movieType;
  std::string director;
  std::string title;
  std::string majorActor;
  int releaseYear;
  int releaseMonth;
  int stock;

  bool invalidLine;
  std::string currLine;
  while (std::getline(infile, currLine)) {
    Movie *newMovie;

    std::istringstream iss(currLine);
    invalidLine = true;

    if (iss >> movieType >> stock >> director >> title) {
      switch (movieType) {
      case 'F': // Comedy
        if (iss >> releaseYear) {
          newMovie = new ComedyMovie(stock, director, title, releaseYear);
          invalidLine = false;
        }

      case 'D': // Drama
        if (iss >> releaseYear) {
          newMovie = new DramaMovie(stock, director, title, releaseYear);
          invalidLine = false;
        }

      case 'C': // Classic
        if (iss >> majorActor >> releaseMonth >> releaseYear) {
          newMovie = new ClassicMovie(stock, director, title, majorActor,
                                      releaseMonth, releaseYear);
          invalidLine = false;
        }

      default:
        invalidLine = true;
      }
    }

    if (invalidLine) {
      std::cout << "Failed to add movie: " << currLine << std::endl;

    } else {
      movies.add(newMovie);
    }
  }
}

// Gets a movie from the inventory
Movie *Inventory::getMovie(Movie *movie) { return movies.get(movie); }

void Inventory::display() { movies.display(); }