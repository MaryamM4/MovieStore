// Inventory.h
/**
 * Inventory class manages a collection of files using a hastable.
 */

#pragma once

#include "hashtable.h"
#include "movie.h"
#include "operation.h"

#include <set>

class Inventory {
public:
  Inventory();
  ~Inventory();

  // Builds the inventory from a file.
  // Returns a pointer to the movie if found, nullptr otherwise.
  /*
  open file
  while not end of file
      read movie details from file
      create new Movie object with details
      insert Movie object into hash table
  close file
  */
  void buildInventory(std::fstream &infile);

  // Borrow a movie from the inventory.
  // // Returns true if the movie was borrowed successfully, false otherwise.
  /*
  get movie
  if movie found and available
    create and execute op
    return true
  else
    return false
  */
  bool borrowMovie(BorrowOperation *op);

  // Return a movie to the inventory.
  // Returns true if the movie was returned successfully, false otherwise.
  /*
  get movie
  if movie found and borrowed
    create and execute op
    return true
  else
    return false
  */
  bool returnMovie(ReturnOperation *op);

  // Displays inventory
  /*
  for each movie in movies
    cout movie
  */
  void display();

private:
  // HashTable<Movie> movies;
  std::set<Movie *> movies;

  // Returns pointer to movie in set.
  // If movie DNE in set, returns nullptr.
  Movie *getMovie(const Movie *movie) const;
  Movie *getMovieByID(int ID) const;
};