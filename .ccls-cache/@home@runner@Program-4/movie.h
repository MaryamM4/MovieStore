//
// Created by Andrew on 2/19/2024.
//

#pragma once

#include <string>

class Movie {
public:
  enum MovieKind {
    // ‘I’ should output all Comedy movies, then all Dramas, then all Classics.
    NONE,
    COMEDY,
    DRAMA,
    CLASSIC,
  };

  Movie(int stock, std::string director, std::string title, int releaseYear,
        MovieKind kind);
  virtual ~Movie() = default;

  int getStock() const;
  std::string getDirector() const;
  std::string getTitle() const;
  MovieKind getKind() const;
  int getReleaseYear() const;

  int getID() const { return ID; }

  virtual bool operator<(const Movie &rhs) const = 0;
  virtual bool operator>(const Movie &rhs) const = 0;
  virtual bool operator==(const Movie &rhs) const = 0;
  virtual bool operator<=(const Movie &rhs) const = 0;
  virtual bool operator>=(const Movie &rhs) const = 0;

private:
  int ID;
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
};

class DramaMovie : public Movie {
public:
  DramaMovie(int stock, std::string director, std::string title,
             int releaseYear);
  ~DramaMovie() override = default;

  int getReleaseYear() const;

  bool operator<(const Movie &rhs) const override;
  bool operator>(const Movie &rhs) const override;
  bool operator==(const Movie &rhs) const override;
  bool operator<=(const Movie &rhs) const override;
  bool operator>=(const Movie &rhs) const override;
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

private:
  int releaseMonth;
  std::string majorActor;
};
