//
// Created by Andrew on 2/19/2024.
//

#pragma once

#include <string>

class Movie {
public:
  enum MovieKind {
    // ‘I’ should output all Comedy movies, then all Dramas, then all Classics.
    NONE = 0,
    COMEDY,
    DRAMA,
    CLASSIC,
  };

  Movie(int stock, std::string director, std::string title, int releaseYear,
        MovieKind kind);
  virtual ~Movie() = default;

  int getStock() const;
  void addStock(); // Adds 1 to stock
  bool remStock(); // Subtracts 1 from stock if > 0.

  std::string getDirector() const;
  std::string getTitle() const;
  MovieKind getKind() const;
  int getReleaseYear() const;

  int getID() const;
  int determineID(); // Only call in constructor.
  // Helper method for determineID
  int hashStringToInt(std::string str, int digitLength) const;

  // Overloaded operators
  virtual bool operator<(const Movie &rhs) const = 0;
  virtual bool operator>(const Movie &rhs) const = 0;
  virtual bool operator==(const Movie &rhs) const = 0;
  virtual bool operator<=(const Movie &rhs) const = 0;
  virtual bool operator>=(const Movie &rhs) const = 0;

  // << can't be overloaded as a pure virtual function.
  virtual std::ostream &display(std::ostream &os) const = 0;
  friend std::ostream &operator<<(std::ostream &os, const Movie &movie);

private:
  int ID;
  bool PRINT_ID; // If true, << displays ID as well

  int stock = 0;
  std::string director;
  std::string title;
  MovieKind kind = NONE;
  int releaseYear;
};

class ComedyMovie : public Movie {
public:
  ComedyMovie(int stock, std::string director, std::string title,
              int releaseYear);
  ~ComedyMovie() override = default;

  bool operator<(const Movie &rhs) const override;
  bool operator>(const Movie &rhs) const override;
  bool operator==(const Movie &rhs) const override;
  bool operator<=(const Movie &rhs) const override;
  bool operator>=(const Movie &rhs) const override;

  std::ostream &display(std::ostream &os) const override;
};

class DramaMovie : public Movie {
public:
  DramaMovie(int stock, std::string director, std::string title,
             int releaseYear);
  ~DramaMovie() override = default;

  bool operator<(const Movie &rhs) const override;
  bool operator>(const Movie &rhs) const override;
  bool operator==(const Movie &rhs) const override;
  bool operator<=(const Movie &rhs) const override;
  bool operator>=(const Movie &rhs) const override;

  std::ostream &display(std::ostream &os) const override;
};

class ClassicMovie : public Movie {
public:
  ClassicMovie(int stock, std::string director, std::string title,
               std::string majorActor, int releaseMonth, int releaseYear);
  ~ClassicMovie() override = default;

  int getReleaseMonth() const;
  std::string getMajorActor() const;

  bool operator<(const Movie &rhs) const override;
  bool operator>(const Movie &rhs) const override;
  bool operator==(const Movie &rhs) const override;
  bool operator<=(const Movie &rhs) const override;
  bool operator>=(const Movie &rhs) const override;

  std::ostream &display(std::ostream &os) const override;

private:
  int releaseMonth;
  std::string majorActor;
};
