#include "inventory.h"
#include "customer.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

Inventory::Inventory() {}
Inventory::~Inventory() {}

void Inventory::buildInventory(std::fstream &infile) {
  Movie *newMovie;

  std::string currLine;
  while (std::getline(infile, currLine)) {
    newMovie = MovieFactory::determineMovie(currLine);

    if (newMovie == nullptr) {
      std::cout << "Failed to add movie due to invalid line:\n"
                << currLine << "\n"
                << std::endl;

    } else {
      Movie *movieInTable = movies.getByID(newMovie->getID());

      if (movieInTable == nullptr) {
        movies.add(newMovie);

      } else { // Movie already exists in HashTable
        if (movieInTable != newMovie) {
          std::cout << "ID WARNING: Different movies have the same ID:\n"
                    << *movieInTable << "\n"
                    << *newMovie << "\n"
                    << std::endl;
        }
        std::cout << "Inventory will not add replica movie:\n"
                  << *newMovie << "\n"
                  << std::endl;
        // movieInTable->addStock();
      }
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
 * @note   Does not check if customer is valid, nor deal with customer's
 * end.
 * @return True if movie was succesfully borrowed, or false otherwise.
 */
bool Inventory::borrowMovie(BorrowOperation *op) {
  Movie *movie = movies.getByID(op->getMovieID());

  if (movie != nullptr) {
    // remStock subtracts 1 from stock.
    // Returns false if not enough stock to borrow.
    return (movie->remStock());

  } else {
    std::cout << "Inventory: Could not borrow non-existing movie." << std::endl;
    return false;
  }

  return false;
}

/**
 *
 * @note   Does not check for valid customer.
 * @return True if movie was succesfully returned, or false otherwise.
 */
bool Inventory::returnMovie(ReturnOperation *op) {
  Movie *movie = movies.getByID(op->getMovieID());

  if (movie != nullptr) {
    // Add 1 back to stock.
    movie->addStock();
    return true;

  } else {
    std::cout << "Inventory: Could not return non-existing movie." << std::endl;
    return false;
  }

  return false;
}