#include "inventory.h"
#include "customer.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

Inventory::Inventory() { std::cout << "Inventory init." << std::endl; }
Inventory::~Inventory() { std::cout << "Inventory destructor." << std::endl; }

void Inventory::buildInventory(std::fstream &infile) {
  std::string movieTypeStr = "";
  std::string director = "";
  std::string title = "";
  std::string majorActor = "";
  std::string releaseYearStr = "";
  std::string releaseMonthStr = "";
  std::string stockStr = "";
  int stock = 0;
  int releaseYear = 0;
  int releaseMonth = 0;

  Movie *newMovie;

  bool invalidLine;
  std::string currLine;
  while (std::getline(infile, currLine)) {
    invalidLine = true;

    std::istringstream iss(currLine);

    if (std::getline(iss, movieTypeStr, ',') &&
        std::getline(iss, stockStr, ',') && std::getline(iss, director, ',') &&
        std::getline(iss, title, ',')) {

      // Convert strings to ints
      stock = std::stoi(stockStr);

      switch (movieTypeStr[0]) {
      case 'F': // Comedy
        if (std::getline(iss, releaseYearStr, ',')) {
          releaseYear = std::stoi(releaseYearStr);

          newMovie = new ComedyMovie(stock, director, title, releaseYear);
          invalidLine = false;
        }
        break;

      case 'D': // Drama
        if (std::getline(iss, releaseYearStr, ',')) {
          releaseYear = std::stoi(releaseYearStr);

          newMovie = new DramaMovie(stock, director, title, releaseYear);
          invalidLine = false;
        }
        break;

      case 'C': // Classic
        if (std::getline(iss, majorActor, ',') &&
            std::getline(iss, releaseMonthStr, ',') &&
            std::getline(iss, releaseYearStr, ',')) {

          // Convert strings to ints
          releaseMonth = std::stoi(releaseMonthStr);
          releaseYear = std::stoi(releaseYearStr);

          newMovie = new ClassicMovie(stock, director, title, majorActor,
                                      releaseMonth, releaseYear);
          invalidLine = false;
        }
        break;

      default:
        invalidLine = true;
      }
    }

    if (invalidLine) {
      std::cout << "Failed to add movie:\n" << currLine << "\n" << std::endl;

    } else {
      movies.add(newMovie);
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