#include "inventory.h"
#include "customer.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

Inventory::Inventory() {}

Inventory::~Inventory() {
  for (auto *moviePtr : movies) {
    delete moviePtr;
  }
  movies.clear();
}

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
      Movie *movieInTable = getMovieByID(newMovie->getID());

      if (movieInTable == nullptr) {
        movies.insert(newMovie);

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
 * Prints all movies in set.
 *
 * @pre Set orders movies first by kind.
 */
void Inventory::display() {
  for (auto *currMovie : movies) {
    std::cout << *currMovie << std::endl;
  }
  std::cout << std::endl;
}

/**
 *
 * @note   Does not check if customer is valid, nor deal with customer's
 * end.
 * @return True if movie was succesfully borrowed, or false otherwise.
 */
bool Inventory::borrowMovie(BorrowOperation *op) {
  // Movie *movie = movies.getByID(op->getMovieID());
  Movie *movie = getMovieByID(op->getMovieID());

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
  // Movie *movie = movies.getByID(op->getMovieID());
  Movie *movie = getMovieByID(op->getMovieID());

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

/**
 * @return Pointer to movie in set.
 *         nullptr if movie DNE in set.
 * @note Ternary operator syntax:
 *       condition ? statement_if_true : statement_if_false
 *       https://www.geeksforgeeks.org/cpp-ternary-or-conditional-operator/
 */
Movie *Inventory::getMovie(const Movie *movie) const {
  auto it = movies.find(const_cast<Movie *>(movie));
  return (it != movies.end()) ? *it : nullptr;
}

/**
 * @return Pointer to movie in set.
 *         nullptr if movie DNE in set.
 */
Movie *Inventory::getMovieByID(int ID) const {
  for (auto *currMoviePtr : movies) {
    if (currMoviePtr->getID() == ID) {
      return currMoviePtr;
    }
  }

  return nullptr;
}