#include "inventory.h"
#include "customer.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

Inventory::Inventory() { std::cout << "Inventory init." << std::endl; }
Inventory::~Inventory() { std::cout << "Inventory destructor." << std::endl; }

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
      std::cout << "Failed to add movie:\n" << currLine << "\n" << std::endl;

    } else {
      movies.add(newMovie);
      std::cout << "Sucesffully added movie:\n"
                << currLine << "\n"
                << std::endl; // DELETE ME
    }
  }
}

/**
 * @return A pointer to a movie from the inventory
 *         or nullptr if movie not found.
 */
Movie *Inventory::getMovie(Movie *movie) { return movies.get(movie); }
Movie *Inventory::getMovie(int movieID) { return movies.getByID(movieID); }

/**
 *
 */
void Inventory::display() { movies.display(); }

/**
 *
 * @note   Does not check if customer is valid.
 * @return True if movie was succesfully borrowed, or false otherwise.
 */
bool Inventory::borrowMovie(BorrowOperation *op) {
  std::cout << "Borrow Movie" << std::endl;
  /*
  Movie *movie = getMovie(op->getMovieID());
  int customerID = op->getCustomerID();

  if (movie == nullptr) {
    // TODO: Offer alternative.
    return false;
  }

  // TO
  */
  return false;
}

/**
 *
 * @return True if movie was succesfully returned, or false otherwise.
 */
bool Inventory::returnMovie(ReturnOperation *op) {
  std::cout << "Return Movie" << std::endl;
  /*
  int movieID = op->getMovieID();
  int customerID = op->getCustomerID();

  // TODO
  */

  return false;
}